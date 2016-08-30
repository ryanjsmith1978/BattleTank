// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Tracks.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	
	UTracks();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FORCEINLINE float GetMaxDrivingForce() { return MaxDrivingForce; }

	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	// Max forward force to the tank body that is at the position of the track's origin.
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	float MaxDrivingForce;


	
};
