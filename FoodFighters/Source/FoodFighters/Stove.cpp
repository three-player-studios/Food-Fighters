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

	// Pot Variables
	BoilCurrentTime = 0.0f;
	BoilTotalTime = 0.0f;
	IsBoiling = false;
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
}

void AStove::CookFood()
{
	CookCurrentTime += 1.0f;
	if (CookCurrentTime == CookTotalTime)
	{
		IsCooking = false;
	}
}

void AStove::BoilFood()
{

}

void AStove::PotSound()
{

}

AFood* AStove::GetCookingFood()
{
	return CookingFood;
}

void AStove::StartCooking(AFood* Food)
{
	if (IsCooking == true)
	{
		// Have the option to cancel the currently cooking food
	}
	else
	{
		CookingFood = Food;
		IsCooking = true;
		CookTotalTime = 10.0f;
	}
}

void AStove::StartBoilingFood(TArray<AFood*> FoodItems)
{

}

void AStove::AddItemToPot(AFood* Food)
{
	
}