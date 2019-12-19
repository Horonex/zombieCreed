// Fill out your copyright notice in the Description page of Project Settings.

#include "Perk.h"
#include "Engine.h"

// Sets default values
APerk::APerk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	BottleMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBottle"));
	RootComponent = MeshComponent;
	CBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	rotator.Add(0, 1, 0);
}

// Called when the game starts or when spawned
void APerk::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APerk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	BottleMeshComponent->AddLocalRotation(rotator);
}

void APerk::BuyPerk() {
	//auto player = Cast<APlayer_BP>(Player);
}
