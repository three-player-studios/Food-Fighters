// Fill out your copyright notice in the Description page of Project Settings.

#include "INTERACT_TEST_OBJECT.h"


// Sets default values
AINTERACT_TEST_OBJECT::AINTERACT_TEST_OBJECT()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AINTERACT_TEST_OBJECT::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AINTERACT_TEST_OBJECT::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

