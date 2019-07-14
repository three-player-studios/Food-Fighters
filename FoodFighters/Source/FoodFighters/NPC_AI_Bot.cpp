// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC_AI_Bot.h"


// Sets default values
ANPC_AI_Bot::ANPC_AI_Bot()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPC_AI_Bot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC_AI_Bot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC_AI_Bot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

