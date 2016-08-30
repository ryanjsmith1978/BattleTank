// Dual Control schemes are possible: we have to set a local variable for throttle in the tank movement component, 
// and consume it every frame.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:

	UTankMovementComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(class UTracks* LeftTrackToSet, class UTracks* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendMoveForward(float Throw);
	
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void IntendMoveRight(float Throw);

	// Called from the pathfinding logic built in to UE4 API by the AI Controllers.
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:

	class UTracks* LeftTrack = nullptr;
	class UTracks* RightTrack = nullptr;
		
};
