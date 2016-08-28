// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"

// #include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAimingComponent::SetBarrelReference(class UTankBarrel* BarrelToSet)
{
	// Barrel StaticMesh declared here, defined in tank.cpp by referencing this function indirectly, and then the BP actually sets/call the func.
	Barrel = BarrelToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector LaunchVelocity_OUT;
	FVector StartLocation = Barrel->GetSocketLocation(FName("FireLocation"));

	// Calculate the Out Launch Velocity 
	// if true, then call move barrel towards passing in the vectors out parameter LaunchVelocity GetSafeNormal() - AimDirection

	// Calculates an launch velocity for a projectile to hit a specified point. 
	if (UGameplayStatics::SuggestProjectileVelocity(this, LaunchVelocity_OUT, StartLocation, HitLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		auto AimDirection = LaunchVelocity_OUT.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
}

// Call the barrel class for specific barrel properties to make the shot
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// work out difference between current barrel rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;	
	// move the barrel the right amount this frame
	
	// given a max elevation speed, and the frame time
	
	Barrel->Elevate(5);
		
}