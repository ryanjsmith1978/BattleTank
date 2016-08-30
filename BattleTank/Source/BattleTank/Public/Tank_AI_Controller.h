// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Tank_AI_Controller.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATank_AI_Controller : public AAIController
{
	GENERATED_BODY()
	
	// constructor for AI Controller
	ATank_AI_Controller();

	// begin play override
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	// returns the Pawn associated with an AI Controller
	class ATank* Get_AIPawn() const;

	// returns the player pawn tank
	class ATank* GetPlayerTank() const;

	

};
