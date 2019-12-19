// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawningManager.h"
#include "Zombie.h"
#include "Spawner.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/World.h"
#include "Engine.h"

// Sets default values
ASpawningManager::ASpawningManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawningManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawningManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

AZombie * ASpawningManager::SelectZombie()
{
	auto sum = 0;
	auto currSum = 0;
	for (int i = 0; i < availableZombies.Num(); i++)
	{
		// 60/ zombie.wheigt
		sum+=60/availableZombies[i]->weight;
		// sum all
	}

	// random from 0 to sum
	auto r = FMath::RandRange(0, sum);
	
	for (int i = 0; i < availableZombies.Num(); i++)
	{
		currSum += 60 / availableZombies[i]->weight;
		if (r < currSum)
		{
			// return choice
			return availableZombies[i];
		}
	}


	return nullptr;

}

 ASpawner * ASpawningManager::SelectSpawner()
{
	//sort spawner by distance to player
	//from last score is index^2
	// sum all
	// random from 0 to sum
	// return choice

	int max= FMath::Exp2(spawners.Num())-1;
	auto currSum = 0;

	auto r = FMath::RandRange(0, max);

	for (int i = 0; i < spawners.Num(); i++)
	{
		currSum += FMath::Exp2(i);
		if (r < currSum)
		{
			return spawners[i];
		}
	}
	
	return spawners[0];
}

bool ASpawningManager::SpawnZombie(AZombie * zombie, ASpawner * spawner)
{
	//spawner.trySpawn(zombie)
	//if zombie spawned return true
	//else return false
	return false;
}

void ASpawningManager::SpawnWave(float DeltaTime)
{
	////wait
	//time += DeltaTime;
	//if (time > waitTime)
	//{
	//	time -= waitTime;
	//	auto z = SelectZombie();
	//	waitTime = Cast<AZombie>(z)->weight;

	//	//spawn
	//	SpawnZombie(z, SelectSpawner());
	//}
}

void ASpawningManager::SetUpWave()
{
	weight = GetWeightForWave(waveCount);
	zombieLeftInWave = weight;


	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("weight %d zliw %d"),weight,zombieLeftInWave));

}

int ASpawningManager::GetWeightForWave(int wave)
{
	return wave * 3 + 5;
}

void ASpawningManager::DecreasWeight(int decreasWeight)
{
	weight -= decreasWeight;
}

void ASpawningManager::DecreasZombieLeft(int decreasWeight)
{
	zombieLeftInWave -= decreasWeight;
}

void ASpawningManager::Delay(float TimeSeconds)
{

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Delay Begin"));


	GetWorldTimerManager().SetTimer(th,this, &ASpawningManager::Dummy, 0, false,TimeSeconds);

	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("will clear timer"));
	//GetWorldTimerManager().ClearTimer(th);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Delay Done"));

	return;
}

void ASpawningManager::IncreasWave()
{
	waveCount++;
}

void ASpawningManager::Dummy()
{
}


//bool ASpawningManager::Wait(float sec)
//{
//	FTimerManager tm = GetWorldTimerManager();// timeManager= GetWorld()->GetTimerManager();
//
//	usleep
//
//
//}

