// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include"Components/BoxComponent.h"
#include "AI_Waypoint.generated.h"

UCLASS()
class FOODFIGHTERS_API AAI_Waypoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAI_Waypoint();


	//defines USceneComponent
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* Root;
	//defines UBoxComponent
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* BoxComponent;

	//defines refence of the waypoint 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AAI_Waypoint* NextWaypoint;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//function that confirms if ai bot eneters the waypoint
	UFUNCTION()
		void OnPlayerEnter(UPrimitiveComponent* OverlapComponent, AActor* OtherActor,
			UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult &SweepResult);
	
	
};
