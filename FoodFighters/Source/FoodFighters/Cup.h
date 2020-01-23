// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include"Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "ObjectPool.h"
#include "Water.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"


#include "Cup.generated.h"

UCLASS()
class FOODFIGHTERS_API ACup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class USphereComponent* CupSphere;

	UPROPERTY(EditAnywhere, Category = Mesh)
		class UStaticMeshComponent* CupMesh;

	UPROPERTY(EditAnywhere, Category = rad)
		float raduis;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	UPROPERTY(EditAnywhere, Category = "object")
		bool trigger;




	///spawnn

	UPROPERTY(EditAnywhere, Category = "object")
		UObjectPool* Objectpoler;

	UPROPERTY(EditAnywhere, Category = "object")
		float TimeSpan = 5;

	UPROPERTY(EditAnywhere, Category = "object")
		float SpawnCooldown = 5;

	FTimerHandle SpawnbCooldownTime;
	void SpawnObj();



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
