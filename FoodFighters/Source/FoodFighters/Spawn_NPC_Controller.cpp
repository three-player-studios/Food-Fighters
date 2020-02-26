// Fill out your copyright notice in the Description page of Project Settings.

#include "Spawn_NPC_Controller.h"


// Sets default values
ASpawn_NPC_Controller::ASpawn_NPC_Controller()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawn_NPC_Controller::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawn_NPC_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

