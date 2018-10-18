// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Error, TEXT("PlayerController not possessing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *ControlledTank->GetName());
	}


}

// Tick
	// Super
	// AimTowardsCrosshair()

void ATankPlayerController::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );
	AimTowardsCrosshair();
	
}

ATank* ATankPlayerController::GetControlledTank() const{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // out parameter

	if (GetSightRayHitLocation(HitLocation)) { 
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
		// TODO tell controlled tank to aim at this point
	}


	// Get world location if linetrace through crosshair
	// If it hits the landscape
	// tell controlled tank to aim at this point

}


// if it hits the landscape through crosshair, we return true
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const {
	// Find the crosshair position
	// de-project the screen position of the crosshair to a world direction
	// linetrace along that look direction and see what we hit (up to some max range)

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation , ViewportSizeY * CrosshairYLocation);
	
	return true;
}