// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectPool.h"
#include "UObject/ConstructorHelpers.h"
#include"GameFramework/Actor.h"
#include"Engine.h"

// Sets default values for this component's properties
UObjectPool::UObjectPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


AWater * UObjectPool::GetObject()
{
	for (AWater* PoolActor : Pool)
	{
		if (!PoolActor->IsActive()) {
			return PoolActor;
		}
	}
	return nullptr;
}

// Called when the game starts
void UObjectPool::BeginPlay()
{
	Super::BeginPlay();

	if (PooledObjectSub != NULL)
	{

		UWorld* const World = GetWorld();
		if (World) 
		{
			for (int i = 0; i < Sizeofpool; i++) 
			{
				AWater* PoolActor = GetWorld()->SpawnActor<AWater>(PooledObjectSub, FVector().ZeroVector, FRotator().ZeroRotator);
				PoolActor->SetActive(false);
				Pool.Add(PoolActor);
				UE_LOG(LogTemp, Warning, TEXT("added to pool"));
			
			}
		}
	}
	
}


// Called every frame
void UObjectPool::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

