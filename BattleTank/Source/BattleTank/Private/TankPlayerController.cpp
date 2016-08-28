// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	CrosshairXLocation = 0.5f;
	CrosshairYLocation = 0.352f;
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	if (GetPawn() != nullptr)
	{		
		return Cast<ATank>(GetPawn());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Error, no pawn"));
		return false;
	}
}

void ATankPlayerController::AimTowardsCrosshair()
{
	// if pawn is null, return (get out of this function)
	if (!GetControlledTank()) { return; }
	
	// Get world location if LineTrace through cross hair
	FVector HitLocation_OUT = FVector(0.0f, 0.0f, 0.0f); // Out Parameter
	bool IsActorHit = GetSightRayHitLocation(HitLocation_OUT);
	
	// if it hits the landscape
	if (IsActorHit)
	{		
		// Tell controlled tank to aim at this point
		GetControlledTank()->AimAt(HitLocation_OUT);
	}	
}


bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation_OUT)
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, HitLocation_OUT);
		return true;
	}
	else
		return false;
}

// mutates unit vector and position for the ray trace
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection)
{	
	FVector LookLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, LookLocation, LookDirection);
}

//  if get look direction is true, we need to trace using screen location and LookDirection

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation_OUT)
{
	LineTraceRange = 1000000.0f;
	FVector LineTraceStart = PlayerCameraManager->GetCameraLocation();
	FVector LineTraceEnd = LineTraceStart + (LookDirection * LineTraceRange);
	FHitResult Hit;

	GetWorld()->LineTraceSingleByChannel(Hit, LineTraceStart, LineTraceEnd, ECollisionChannel::ECC_Visibility);
	
	auto Actor = Hit.GetActor();
	if (Actor != nullptr)
	{
		HitLocation_OUT = Hit.Location;
		return true;
	}
	else
	{
		HitLocation_OUT = FVector(0);
		return false;
	}
}
