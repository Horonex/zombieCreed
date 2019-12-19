// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class AZombie;

UCLASS()
class ZOMBIECREED_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	USceneComponent* sceneComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	


	void SpawnZombie(TSubclassOf<class AZombie> zombie);

};
