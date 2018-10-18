// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
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
	
private:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// start the tank moving the barrel so that a shot would hit where
	// the crosshair intersects the world
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& HitLocation) const; // true if hit landscape


	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.33333f;



};
