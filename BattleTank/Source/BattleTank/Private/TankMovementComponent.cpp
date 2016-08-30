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
	// Direction Tank is facing
	FVector ForwardNormal = GetOwner()->GetActorForwardVector().GetSafeNormal();
	// Direction tank wants to move towards
	FVector VelocityNormal = MoveVelocity.GetSafeNormal();
	
	float DirectionProjection = FVector::DotProduct(ForwardNormal, VelocityNormal);
	IntendMoveForward(DirectionProjection);
}
