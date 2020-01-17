// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Water.generated.h"

UCLASS()
class FOODFIGHTERS_API AWater : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWater();
	virtual void SetLifeSpan(float Time) override;
	void SetActive(bool InActive);
	bool IsActive();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	float TimeSpan = 30;
	FTimerHandle LifeSpanTimer;
	bool Active;
	void DeActive();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
