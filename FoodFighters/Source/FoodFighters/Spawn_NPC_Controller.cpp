// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawn_NPC_Controller.h"
#include "NPCCharacter.h"
#include "Classes/Engine/World.h"
#include "Public/TimerManager.h" 
#include "Kismet/KismetMathLibrary.h"/* makes Origin and BoxExtent into variables */


// Sets default values
ASpawn_NPC_Controller::ASpawn_NPC_Controller()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the Box Component to represent the spawn volume
	WhereToSpawn = CreateDefaultSubobject<UBoxComponent>(TEXT("WhereToSpawn"));
	RootComponent = WhereToSpawn;

	//Set the spawn delay range
	SpawnDelayRangeLow = 1.0f;
	SpawnDelayRangeHigh = 2.5f;
}

// Called when the game starts or when spawned
void ASpawn_NPC_Controller::BeginPlay()
{
	Super::BeginPlay();
	

	// spawn Between Max and min time 
	SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
	//Manages all timer in world 
	GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawn_NPC_Controller::SpawnNPC, SpawnDelay, false);

}

// Called every frame
void ASpawn_NPC_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawn_NPC_Controller::GetRandomPointInVolume()
{
	FVector SpawnOrigin = WhereToSpawn->Bounds.Origin;
	FVector SpawnExtent = WhereToSpawn->Bounds.BoxExtent;

	return UKismetMathLibrary::RandomPointInBoundingBox(SpawnOrigin, SpawnExtent);

}

void ASpawn_NPC_Controller::SpawnNPC()
{
	// If we have set something to spawn:
	if (WhatToSpawn != NULL)
	{
		// Check for a valid World: 
		UWorld* const World = GetWorld();
		if (World)
		{
			// Set the spawn parameters

			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;


			// Get a  location to spawn at
			FVector SpawnLocation = GetRandomPointInVolume();

			// Get a  rotation for the spawned item
			FRotator SpawnRotation;
			SpawnRotation.Yaw = 0;/*FMath::FRand() * 360.0f;*/
			SpawnRotation.Pitch =0 /*FMath::FRand() * 360.0f*/;
			SpawnRotation.Roll = 0/*FMath::FRand() * 360.0f*/;

			// spawn the pickup
			ANPCCharacter* SpawnedNPC = World->SpawnActor<ANPCCharacter>(WhatToSpawn, SpawnLocation, SpawnRotation, SpawnParams);
			//ACharacter
			
			//
			SpawnedNPC->TablePlacementManger = TablePlacementManger;
		
			//spawn between the values of SpawnDelayRangeLow and SpawnDelayRangeHigh
			SpawnDelay = FMath::FRandRange(SpawnDelayRangeLow, SpawnDelayRangeHigh);
			GetWorldTimerManager().SetTimer(SpawnTimer, this, &ASpawn_NPC_Controller::SpawnNPC, SpawnDelay, false);

		}
	}


}

void ASpawn_NPC_Controller::Setmanger()
{
	
}

