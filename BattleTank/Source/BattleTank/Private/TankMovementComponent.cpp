// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankMovementComponent.h"
#include "Tracks.h"

UTankMovementComponent::UTankMovementComponent()
{

}
void UTankMovementComponent::Initialise(class UTracks* LeftTrackToSet, class UTracks* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendMoveRight(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	FString VelocityString = MoveVelocity.GetSafeNormal().ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s request move velocity is %s"), *GetOwner()->GetName(), *VelocityString);
}
