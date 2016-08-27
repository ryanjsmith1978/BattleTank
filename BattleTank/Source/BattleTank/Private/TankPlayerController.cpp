// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	if (GetPawn() != nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("The pawn controlled by the player is : %s"), *GetPawn()->GetName());
		return Cast<ATank>(GetPawn());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Error, no pawn"));
		return false;
	}
}

