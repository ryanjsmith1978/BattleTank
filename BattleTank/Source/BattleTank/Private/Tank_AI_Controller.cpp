// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank_AI_Controller.h"
#include "Tank.h"


ATank_AI_Controller::ATank_AI_Controller()
{

}

void ATank_AI_Controller::BeginPlay()
{
	AI_ControlledTank = Get_AIPawn();

	PlayerPawnTank = GetPlayerTank();

	if (PlayerPawnTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank Pawn is : %s"), *PlayerPawnTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Player Pawn Tank found"));
	}

}

ATank* ATank_AI_Controller::Get_AIPawn()
{
	return Cast<ATank>(GetPawn());
}

ATank * ATank_AI_Controller::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (PlayerPawn != nullptr)
	{
		return Cast<ATank>(PlayerPawn);
	}
	else
	{
		return nullptr;
	}
}
