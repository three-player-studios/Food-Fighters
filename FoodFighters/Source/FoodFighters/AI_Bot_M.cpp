// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Bot_M.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AAI_Bot_M::AAI_Bot_M()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	// will get charater roataion movement and set it at a rate of 600 on y axis  
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 600.0f, 0.0f);

}

// Called when the game starts or when spawned
void AAI_Bot_M::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI_Bot_M::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_Bot_M::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

