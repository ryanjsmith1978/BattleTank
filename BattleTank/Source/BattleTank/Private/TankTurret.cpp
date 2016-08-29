// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// move the Turret the right amount this frame
	// given a max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);
	float RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float NewRotation = RelativeRotation.Yaw + RotationChange;
	
	SetRelativeRotation(FRotator(0.0f, NewRotation, 0.0f));
}
