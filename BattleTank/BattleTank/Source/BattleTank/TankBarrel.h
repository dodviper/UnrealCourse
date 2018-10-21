// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
public:
	GENERATED_BODY()

	//so -1 is max downward movement and +1 is max up movement
	void Elevate(float RelativeSpeed);
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 10;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 30;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = 0;
};