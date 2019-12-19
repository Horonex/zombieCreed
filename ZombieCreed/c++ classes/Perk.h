// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Math/Rotator.h"
#include "Perk.generated.h"

UCLASS()
class ZOMBIECREED_API APerk : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APerk();
	
	UPROPERTY(EditAnywhere)
		AActor* Player;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BottleMeshComponent;

	UPROPERTY(VisibleAnywhere)
		UBoxComponent* CBox;

	//Rotate the bottle
	UPROPERTY(BlueprintReadOnly)
		FRotator rotator;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void BuyPerk();
};
