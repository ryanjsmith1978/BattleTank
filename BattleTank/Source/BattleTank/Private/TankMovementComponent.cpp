
#include "BattleTank.h"
#include "TankMovementComponent.h"
#include "Tracks.h"

UTankMovementComponent::UTankMovementComponent()
{

}
void UTankMovementComponent::Initialise(class UTracks* LeftTrackToSet, class UTracks* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendMoveRight(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

/// Requests new velocity: AI path that they are following.  In this case,  the velocity vector is normalized to get
/// optimal angle to the best case next vector by using the cosine angle to compute the dot product - or
/// the percentage of forward speed/reverse speed based on the cosine angle between the forward direction of AI, and desired direction of next vector.
void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// Direction Tank is facing
	FVector ForwardNormal = GetOwner()->GetActorForwardVector().GetSafeNormal();
	// Direction tank wants to move towards
	FVector VelocityNormal = MoveVelocity.GetSafeNormal();
	
	float DirectionProjection = FVector::DotProduct(ForwardNormal, VelocityNormal);
	UE_LOG(LogTemp, Warning, TEXT("The dot product is : %f"), DirectionProjection)
	IntendMoveForward(DirectionProjection);

	FVector RightThrow = FVector::CrossProduct(ForwardNormal, VelocityNormal);
	float RotationChange = RightThrow.Z;
	IntendMoveRight(RotationChange);
}


// *** THE DOT PRODUCT for this case ***
// Dot product will output a float, which is the percentage of max speed available ("How parallel is the forward vector to the aim vector")
// The float outputs on a sin curve that tells the AI to move towards max speed the
// closer it is to facing the same direction as the optimal destination Vector,
// and 0 speed when at a right angle from the player.
// The curve is a differential cosine curve meaning the changes changes every frame, but 
// also, the acceleration rate flattens out the closer it gets to 1 and -1 (max forward speed, and max reverse speed)

// *** The DOT PRODUCT in general *** [[[a * b = |a| * |b| * cos(theta]]]
// The DOT PRODUCT is a scalar value expressing the angular relationship between two vectors. 
// The dot product is thus the sum of the products of each component of the two vectors (a * b is the same as {(ax * bx) + (ay * by)} )
// cos(theta) is the angle between two vectors.  

// *** WORK = Force x Distance ***  - force needs to be in the same direction as Distance
// The dot product is used to calculate joules of work needed given a certain amount of force in a given direction over a distance in that same direction.
// Work equals Force vector * Distance vector (The Force Vector is not the total force but the force projection * Cos(theta))
// Force projection is the amount of force of needed for a particular vector component of that force vector (like the X axis of a Force Vector) 
// in the same direction of the distance vector.

// CROSS PRODUCT: [[[ a x b = ||a|| ||b|| sin(theta) * n ]]]
// Outputs a Vector.  Measures Perpendicularity. Order Matters.
// Maximum vector when vectors are perpendicular, and a zero vector when they are exactly parallel.
// Cross Product is an Orthogonal Vector to both.  (Think the Z-axis to the typical X and Y axis in a viewport)
// If the tank is 90 degrees to the left of us, the cross products demands max speed to rotate back to the right, and the opposite when on the other side.
// 