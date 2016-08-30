
#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetBarrelReference(class UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetTurretReference(class UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "FIRING")
	void Fire();

	UFUNCTION(BlueprintPure, Category = "Firing")
	float GetAcceptanceRadius();

protected:

	UPROPERTY(BlueprintReadOnly)
	class UTankAimingComponent* TankAimingComponent = nullptr;
	
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	

	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed; // starting projectile launch speed

	UPROPERTY(EditAnywhere, Category = "Firing")
	TSubclassOf<class AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float AcceptanceRadius;

	double LastFireTime;

	class UTankBarrel* TankBarrel = nullptr;
		
};
