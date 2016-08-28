// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:


private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	ATank* GetControlledTank() const;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector &HitLocation_OUT);

	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection);

	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation_OUT);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crosshairs", meta = (AllowPrivateAccess = "true"))
	float CrosshairXLocation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crosshairs", meta = (AllowPrivateAccess = "true"))
	float CrosshairYLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crosshairs", meta = (AllowPrivateAccess = "true"))
	float LineTraceRange;
		
};
