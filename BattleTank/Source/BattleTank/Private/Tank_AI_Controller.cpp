// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank_AI_Controller.h"
#include "Tank.h"


ATank_AI_Controller::ATank_AI_Controller()
{

}

void ATank_AI_Controller::BeginPlay()
{
	Super::BeginPlay();

	if (GetPlayerTank() != nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Player Tank Pawn is : %s"), *Get_AIPawn()->GetName());
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("No Player Pawn Tank found"));
	}

}

void ATank_AI_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//Get_AIPawn()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATank_AI_Controller::Get_AIPawn() const
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
