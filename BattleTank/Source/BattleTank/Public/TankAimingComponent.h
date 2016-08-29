// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetBarrelReference(class UTankBarrel* BarrelToSet);

	void SetTurretReference(class UTankTurret* TurretToSet);

	void MoveBarrelTowards(FVector AimDirection);
		
private:
	
	// Barrel StaticMesh declared here, defined in tank.cpp by referencing this function indirectly, and then the BP actually sets/call the func.
	class UTankBarrel* Barrel = nullptr;

	class UTankTurret* Turret = nullptr;
	

};
