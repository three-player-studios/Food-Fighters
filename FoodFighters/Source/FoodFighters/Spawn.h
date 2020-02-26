// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectPool.h"
#include "Water.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "Cup.h"
#include "Spawn.generated.h"

UCLASS()
class FOODFIGHTERS_API ASpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	UPROPERTY(EditAnywhere, Category = "object")
	class UBoxComponent* Spawnvol;

	UPROPERTY(EditAnywhere, Category = "object")
		UObjectPool* Objectpoler;

	UPROPERTY(EditAnywhere, Category = "object")
		ACup* cup;



	UPROPERTY(EditAnywhere, Category = "object")
		float TimeSpan  = 5;

	UPROPERTY(EditAnywhere, Category = "object")
		float SpawnCooldown = 5;

	FTimerHandle SpawnbCooldownTime;
	void SpawnObj();

};
