// Fill out your copyright notice in the Description page of Project Settings.

#include "Water.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Actor.h"

// Sets default values
AWater::AWater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetActorEnableCollision(false);

}

void AWater::SetLifeSpan(float Time)
{
	TimeSpan = Time;
	GetWorldTimerManager().SetTimer(LifeSpanTimer, this, &AWater::DeActive, TimeSpan, false);
}

void AWater::SetActive(bool InActive)
{
	Active = InActive;
	SetActorHiddenInGame(!InActive);
}

bool AWater::IsActive()
{
	return Active;
}

// Called when the game starts or when spawned
void AWater::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWater::DeActive()
{
	SetActive(false);
}

// Called every frame
void AWater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

