// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Classes/Components/BoxComponent.h"
#include "Spawn_NPC_Controller.generated.h"

UCLASS()
class FOODFIGHTERS_API ASpawn_NPC_Controller : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawn_NPC_Controller();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** The pickup to spawn*/
	UPROPERTY(EditAnywhere, Category = "Spawning")
		//TSubclassOf<class ANPCCharacter> WhatToSpawn;
	TSubclassOf<class ANPCCharacter> WhatToSpawn;


	
	//will handle when to spawn
	FTimerHandle SpawnTimer;
	
	/** Minimum spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float SpawnDelayRangeLow;

	/** Maximum spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float SpawnDelayRangeHigh;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	/** Find a random point within the BoxComponent */
	UFUNCTION(BlueprintPure, Category = "Spawning")
		FVector GetRandomPointInVolume();
private:
	//define box component 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* WhereToSpawn;

	/** Handle spawning a new pickup */
	void SpawnPickup();

	/** The current spawn delay */
	float SpawnDelay;

	
	
};
