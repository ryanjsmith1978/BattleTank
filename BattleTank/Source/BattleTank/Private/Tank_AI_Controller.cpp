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
}

void ATank_AI_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// move towards the player
		MoveToActor(PlayerTank, ControlledTank->GetAcceptanceRadius());

		// aim at the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//ControlledTank->Fire();
	}
}

ATank* ATank_AI_Controller::Get_AIPawn() const
{
	auto AIPawn = Cast<ATank>(GetPawn());
	return AIPawn;
}

ATank* ATank_AI_Controller::GetPlayerTank() const
{
	auto PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	return PlayerPawn;
}
