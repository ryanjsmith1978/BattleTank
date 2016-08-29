// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

UTankBarrel::UTankBarrel()
{
	
}

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// move the Turret the right amount this frame
	// given a max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);
	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	float Elevation = FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);	

	SetRelativeRotation(FRotator(Elevation, 0.0f, 0.0f));
}

