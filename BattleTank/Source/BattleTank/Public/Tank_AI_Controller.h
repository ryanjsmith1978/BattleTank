// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
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
	
	// returns the Pawn associated with an AI Controller
	ATank* Get_AIPawn();

	// returns the player pawn tank
	ATank* GetPlayerTank() const;

	// ATank pointer points to an AI controlled tank if available, otherwise null
	ATank* AI_ControlledTank = nullptr;

	// ATank pointer points to the player pawn tank
	ATank* PlayerPawnTank = nullptr;
	
};
