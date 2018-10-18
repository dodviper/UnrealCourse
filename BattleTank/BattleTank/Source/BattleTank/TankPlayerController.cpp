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
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation , ViewportSizeY * CrosshairYLocation);
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) {
		// linetrace along that look direction and see what we hit (up to some max range)

		if (GetLookVectorHitLocation(LookDirection, HitLocation)) {
			UE_LOG(LogTemp, Warning, TEXT("Hit: %s"), *HitLocation.ToString());
		}



	}
	
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {
	
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + LookDirection * LineTraceRange;


	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility
	)) {
		HitLocation = HitResult.Location;
		return true;
	}

	HitLocation = FVector(0.f);
	return false; 

	/*
	bool LineTraceSingleByChannel
	(
		struct FHitResult & OutHit,
		const FVector & Start,
		const FVector & End,
		ECollisionChannel TraceChannel,
		const FCollisionQueryParams & Params,
		const FCollisionResponseParams & ResponseParam
	)
	*/


}