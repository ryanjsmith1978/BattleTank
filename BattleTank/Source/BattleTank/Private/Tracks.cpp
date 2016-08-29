// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tracks.h"

UTracks::UTracks()
{

}

void UTracks::SetThrottle(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle is : %f"), *Name, Throttle);

}
