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

	if (AI_ControlledTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled Tank Pawn is : %s"), *GetPawn()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No AI Controlled Tank found"));
	}

}

ATank* ATank_AI_Controller::Get_AIPawn()
{
	return Cast<ATank>(GetPawn());
}