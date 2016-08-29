// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/ProjectileMovementComponent.h"
#include "TankProjectileMovementComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankProjectileMovementComponent : public UProjectileMovementComponent
{
	GENERATED_BODY()
	
public:

	UTankProjectileMovementComponent();
			
};
