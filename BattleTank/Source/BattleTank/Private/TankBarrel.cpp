// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

UTankBarrel::UTankBarrel()
{
	
}

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// move the barrel the right amount this frame
	// given a max elevation speed, and the frame time
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	SetRelativeRotation(FRotator(RawNewElevation, 0.0f, 0.0f));
}

