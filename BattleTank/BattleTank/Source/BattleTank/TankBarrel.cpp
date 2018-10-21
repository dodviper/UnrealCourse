// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed) {
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);
	// Move the barrel the right amount this frame
	// given a max elevation speed, and the frame time
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees,MaxElevationDegrees);

	SetRelativeRotation(FRotator(Elevation, 0.f, 0.f));
}


