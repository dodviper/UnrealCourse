// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
public:
	GENERATED_BODY()
	void Rotate(float RelativeSpeed);
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 15.f;
	
	
};