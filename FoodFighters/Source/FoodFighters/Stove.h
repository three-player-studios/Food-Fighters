// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FoodFighters/FoodFightersCharacter.h"
#include "FoodFighters/Food.h"
#include "Stove.generated.h"

UCLASS()
class FOODFIGHTERS_API AStove : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AStove();

	/* STOVE VARIABLES */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stove)
		AFood* CookingFood;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stove)
		float CookCurrentTime;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stove)
		float CookTotalTime;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stove)
		bool IsCooking;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Stove)
		bool DoneCooking;

	/* POT VARIABLES */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Pot)
		AFood* BoilingFood;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Pot)
		float BoilCurrentTime;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Pot)
		float BoilTotalTime;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Pot)
		bool IsBoiling;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Pot)
		bool DoneBoiling;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void CookFood();
	UFUNCTION()
		void BoilFood();

	int seconds;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		bool StartCooking(AFoodFightersCharacter* Player);

	UFUNCTION(BlueprintCallable)
		bool StartBoiling(AFoodFightersCharacter* Player);
};
