// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

	UTankMovementComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(class UTracks* LeftTrackToSet, class UTracks* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendMoveForward(float Throw);
	
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendMoveRight(float Throw);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:

	class UTracks* LeftTrack = nullptr;
	class UTracks* RightTrack = nullptr;
		
};
