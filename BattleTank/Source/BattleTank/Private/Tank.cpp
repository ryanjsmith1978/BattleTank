
#include "BattleTank.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(TEXT("TankAimingComponent"));
	//TankMovement = CreateDefaultSubobject<UTankMovementComponent>(TEXT("TankMovement"));
	ReloadTimeInSeconds = 2.0f;
	LaunchSpeed = 7500.0f;
	LastFireTime = 0.0f;
	AcceptanceRadius = 3000.0f;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

		
}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	TankBarrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	if (!TurretToSet) { return; }
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	//UE_LOG(LogTemp, Warning, TEXT("Firing Projectile"))

	bool isReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTimeInSeconds;
	
	if (TankBarrel && isReloaded)
	{
		// Spawn a projectile at the location at the barrel
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = Instigator;

		FVector SpawnLocation = TankBarrel->GetSocketLocation("FireLocation");
		FRotator SpawnRotation = TankBarrel->GetSocketRotation("FireLocation");

		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, SpawnLocation, SpawnRotation, SpawnParams);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = GetWorld()->GetTimeSeconds();
	}
	else
	{
		return;
	}

}

float ATank::GetAcceptanceRadius()
{
	return AcceptanceRadius;
}

