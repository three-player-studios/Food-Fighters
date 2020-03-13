// Fill out your copyright notice in the Description page of Project Settings.

#include "Stove.h"


// Sets default values
AStove::AStove()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Stove Variables
	CookingFood = nullptr;
	CookCurrentTime = 0.0f;
	CookTotalTime = 0.0f;
	IsCooking = false;
	DoneCooking = false;

	// Pot Variables
	BoilingFood = nullptr;
	BoilCurrentTime = 0.0f;
	BoilTotalTime = 0.0f;
	IsBoiling = false;
	DoneBoiling = false;
}

// Called when the game starts or when spawned
void AStove::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStove::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsCooking == true)
	{
		CookFood();
	}
	if (IsBoiling == true)
	{
		BoilFood();
	}
}

void AStove::CookFood()
{
	CookCurrentTime += 1.0f;
	if (CookCurrentTime == CookTotalTime)
	{
		IsCooking = false;
		DoneCooking = true;
	}
}

void AStove::BoilFood()
{
	BoilCurrentTime += 1.0f;
	if (BoilCurrentTime == BoilTotalTime)
	{
		IsBoiling = false;
		DoneBoiling = true;
	}
}

bool AStove::StartCooking(AFoodFightersCharacter* Player)
{
	// First check if player is currently holding food
	if (Player->HeldFood == nullptr)
	{
		return false;
	}
	else
	{
		// Then add the food to Stove
		CookingFood = Player->HeldFood;
		IsCooking = true;
		DoneCooking = false;
		CookCurrentTime = 0.0f;
		CookTotalTime = CookingFood->CookTime;
		// Return true so we can use the attach the food to stove in blueprints
		return true;
	}
}

bool AStove::StartBoiling(AFoodFightersCharacter* Player)
{
	// First check if player is currently holding food
	if (Player->HeldFood == nullptr)
	{
		return false;
	}
	else
	{
		// Then add the food to Pot
		BoilingFood = Player->HeldFood;
		IsBoiling = true;
		DoneBoiling = false;
		BoilCurrentTime = 0.0f;
		BoilTotalTime = BoilingFood->CookTime;
		// Return true so we can use the attach the food to pot in blueprints
		return true;
	}
}