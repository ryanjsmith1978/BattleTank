// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tracks.h"

UTracks::UTracks()
{
	PrimaryComponentTick.bCanEverTick = true;
	// 40 ton tank at 10 m/s/s.  Force = Mass * Acceleration
	MaxDrivingForce = 400000.0f;
}
void UTracks::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	// Calculate Slippage Speed
	float SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	// work out required acceleration this frame to correct
	FVector CorrectAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	// calculate and apply the sideways friction (F = ma)
	auto getTankBase = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());

	auto CorrectionForce = (getTankBase->GetMass() * CorrectAcceleration) / 2;

	getTankBase->AddForce(CorrectionForce);
}

void UTracks::SetThrottle(float Throttle)
{
	FString Name = GetName();
	
	// Calculate force applied by whatever direction the tank is facing
	FVector ForceApplied = GetForwardVector() * Throttle * MaxDrivingForce;
	FVector ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation, NAME_None);
}
