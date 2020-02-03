// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPCCharacter.h"
#include"Components/BoxComponent.h"
#include "Waypoint_Exit.generated.h"

UCLASS()
class FOODFIGHTERS_API AWaypoint_Exit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWaypoint_Exit();


	//defines USceneComponent
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* Root;
	//defines UBoxComponent
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* BoxComponent;

	//defines refence of the waypoint 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AWaypoint_Exit* NextWaypoint_Exit;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool full;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	UFUNCTION()
		void OnPlayerEnter(UPrimitiveComponent* OverlapComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult &SweepResult);
};
