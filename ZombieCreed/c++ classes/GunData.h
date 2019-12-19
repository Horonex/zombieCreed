// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GunData.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIECREED_API UGunData : public UDataAsset
{
	GENERATED_BODY()
public:
    UPROPERTY(editAnywhere,blueprintReadOnly)
    float fireRate = 1;
    UPROPERTY(editAnywhere, blueprintReadOnly)
    float fireRateMultiplier = 1;
    UPROPERTY(editAnywhere, blueprintReadOnly)
    float damageMultiplier = 1;
    UPROPERTY(editAnywhere, blueprintReadOnly)
    int ammoInClip = 30;
    UPROPERTY(editAnywhere, blueprintReadOnly)
    int level = 0;
	UPROPERTY(editAnywhere, blueprintReadOnly)
	float level1Stat;
	UPROPERTY(editAnywhere, blueprintReadOnly)
	float level2Stat;
	UPROPERTY(editAnywhere, blueprintReadOnly)
	float level3Stat;
	UPROPERTY(editAnywhere, blueprintReadOnly)
	FString level1Type;
	UPROPERTY(editAnywhere, blueprintReadOnly)
	FString level2Type;
	UPROPERTY(editAnywhere, blueprintReadOnly)
	FString level3Type;



};
