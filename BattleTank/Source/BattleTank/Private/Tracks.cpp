// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tracks.h"

UTracks::UTracks()
{
	// 40 ton tank at 10 m/s/s.  Force = Mass * Acceleration
	MaxDrivingForce = 400000.0f;
}

void UTracks::SetThrottle(float Throttle)
{
	FString Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle is : %f"), *Name, Throttle);

	// Calculate force applied by whatever direction the tank is facing
	FVector ForceApplied = GetForwardVector() * Throttle * MaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation, NAME_None);
}
