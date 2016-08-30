// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"

// #include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

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


void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	Turret = TurretToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector LaunchVelocity_OUT = FVector(0, 0, 0);
	FVector StartLocation = Barrel->GetComponentLocation();

	// Calculate the Out Launch Velocity 
	// if true, then call moveBarrelTowards passing in the velocity vector's normal - AimDirection
		
	// Calculates an launch velocity for a projectile to hit a specified point.	
	if (UGameplayStatics::SuggestProjectileVelocity(this, LaunchVelocity_OUT, StartLocation, HitLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		auto AimDirection = LaunchVelocity_OUT.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("Launch Velocity Vector is : %s and it's Normal Value is : %s"), 
			//*LaunchVelocity_OUT.ToString(), *AimDirection.ToString());
		MoveBarrelTowards(AimDirection);
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("AimDirection is : { 0, 0, 0}"));
	}

}

/// Call the barrel class for specific barrel properties to make the shot
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// work out difference between current AimDirection and barrel rotation
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;
		
	// given a max elevation speed, and the frame time
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}
// A launch velocity is equivalent to a velocity vector which includes the magnitude (the speed), and the direction

// Vector has magnitude (size) and direction.
// Vector Magnitude is calculated using Pythagoras (sqrt of x^2 + y^2)
// Vector with a magnitude of 1 is a UNIT VECTOR, which can be calculated by normalizing a vector (uses a point which can calculate a parallel plane).    


