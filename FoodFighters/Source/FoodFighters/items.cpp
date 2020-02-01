// Fill out your copyright notice in the Description page of Project Settings.

#include "items.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"
#include "FoodFightersCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"

// Sets default values
Aitems::Aitems()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereRadius = 100.0f;

	PointsItem = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	PointsItem->InitSphereRadius(SphereRadius);
	RootComponent = PointsItem;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	MyMesh->SetupAttachment(RootComponent);

	PointsItem->OnComponentBeginOverlap.AddDynamic(this, &Aitems::OnOverlapBegin);

}

void Aitems::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		// Remove Object
		AFoodFightersCharacter* player = Cast<AFoodFightersCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
		if (player)
		{
			player->AddToInventory(this);
			// Destroy();
		}
	}
}

