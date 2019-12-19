// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Actor.h"
#include "SpawningManager.generated.h"
//#include "Engine/World.h"

class AZombie;
class ASpawner;
class UWorld;

UCLASS()
class ZOMBIECREED_API ASpawningManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawningManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle th;
	

public:
	UPROPERTY(editAnywhere, blueprintReadOnly)
	TArray<TSubclassOf<class AZombie>> zombies;



	UPROPERTY(editAnywhere, blueprintReadOnly)
	TArray<ASpawner*> spawners;

	TArray<AZombie*> availableZombies;

	UPROPERTY(editAnywhere)
	TSubclassOf<class AZombie> toSpawn;


	UPROPERTY(editAnywhere, blueprintReadOnly)
	int weight=0;

	UPROPERTY(editAnywhere, blueprintReadOnly)
		int zombieLeftInWave=0;

	UPROPERTY(editAnywhere, blueprintReadOnly)
		int waveCount=0;

	float waitTime=5;
	float time = 0;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	AZombie* SelectZombie();
	UFUNCTION(BlueprintCallable)
	ASpawner* SelectSpawner();

	bool SpawnZombie(AZombie* zombie, ASpawner* spawner);

	void SpawnWave(float DeltaTime);

	UFUNCTION(BlueprintCallable)
	void SetUpWave();

	UFUNCTION(BlueprintCallable)
	int GetWeightForWave(int wave);

	UFUNCTION(BlueprintCallable)
		void DecreasWeight(int decreasWeight);

	UFUNCTION(BlueprintCallable)
		void DecreasZombieLeft(int decreasWeight);


	UFUNCTION(BlueprintCallable)
		void Delay(float TimeSeconds);

	UFUNCTION(BlueprintCallable)
		void IncreasWave();

	void Dummy();

};
