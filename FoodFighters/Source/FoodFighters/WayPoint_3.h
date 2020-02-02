// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"Components/BoxComponent.h"
#include "WayPoint_3.generated.h"

UCLASS()
class FOODFIGHTERS_API AWayPoint_3 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWayPoint_3();


	//defines USceneComponent
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* Root;
	//defines UBoxComponent
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* BoxComponent;

	//defines refence of the waypoint 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AWayPoint_3* NextWaypoint;


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
