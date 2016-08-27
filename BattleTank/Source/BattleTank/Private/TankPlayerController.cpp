// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
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
	
	// Get world location if LineTrace through crosshair
	FVector HitLocation_OUT; // Out Parameter
	bool IsActorHit = GetSightRayHitLocation(HitLocation_OUT);

	// if it hits the landscape
	if (IsActorHit)
	{
		// Tell controlled tank to aim at this point
		
	}	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation_OUT) const
{
	auto MyPlayerController = GetWorld()->GetFirstPlayerController();
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);		
	

	FHitResult Hit;
	FVector PlayerViewPointLoc;
	FRotator PlayerViewPointRot;
	float Reach = 5000.0f;

	if (MyPlayerController != nullptr)
	{
		MyPlayerController->GetPlayerViewPoint(PlayerViewPointLoc, PlayerViewPointRot);
		FVector LineTraceEnd = PlayerViewPointRot.Vector() * Reach + PlayerViewPointLoc;
		FCollisionQueryParams TraceParams(TEXT(""), false, GetOwner());
		FCollisionResponseParams ResponseParams(ECR_Block);

		GetWorld()->LineTraceSingleByChannel(Hit, HitLocation_OUT, LineTraceEnd, ECC_Visibility, TraceParams, ResponseParams);
		auto Actor = Hit.GetActor();
		HitLocation_OUT = Hit.Location;
		
		if (Actor != nullptr)
		{			
			return true;
		}
		else
		{
			return false;
		}
	}
	else
		return false;	
}

