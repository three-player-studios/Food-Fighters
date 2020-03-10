// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Food.h"
#include "Stove.generated.h"

UCLASS()
class FOODFIGHTERS_API AStove : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStove();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	/* STOVE VARIABLES */
	// Food currently cooking inside
	AFood* CookingFood;

	// Current time being cooked
	float CookCurrentTime;

	// Total Time needed to be cooked
	float CookTotalTime;

	// Check is something is cooking
	bool IsCooking;

	/* POT VARIABLES */
	// Food being boiled in the pot
	AFood* BoilingFood;

	// Current time being cooked
	float BoilCurrentTime;

	// Total Time needed to be cooked
	float BoilTotalTime;

	// Check is something is boiling
	bool IsBoiling;

	UFUNCTION()
		void CookFood();
	UFUNCTION()
		void BoilFood();
	UFUNCTION()
		void PotSound();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		AFood* GetCookingFood();

	UFUNCTION(BlueprintCallable)
		bool GetIsCooking();

	UFUNCTION(BlueprintCallable)
		AFood* GetBoilingFood();

	UFUNCTION(BlueprintCallable)
		bool GetIsBoiling();

	UFUNCTION(BlueprintCallable)
		void StartCooking(AFood* Food);
	
	UFUNCTION(BlueprintCallable)
		void StartBoiling(AFood* Food);
};
