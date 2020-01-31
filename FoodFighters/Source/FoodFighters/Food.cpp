// Fill out your copyright notice in the Description page of Project Settings.

#include "Food.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FoodFighters/FoodFightersCharacter.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereRadius = 100.0f;

	PointsItem = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	PointsItem->InitSphereRadius(SphereRadius);
	RootComponent = PointsItem;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	MyMesh->SetupAttachment(RootComponent);

	PointsItem->OnComponentBeginOverlap.AddDynamic(this, &AFood::OnOverlapBegin);


}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFood::OnInteract()
{

}

void AFood::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{


	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		OnInteract();
	}
}

