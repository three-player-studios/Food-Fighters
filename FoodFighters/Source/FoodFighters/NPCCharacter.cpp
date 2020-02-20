// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ANPCCharacter::ANPCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationRoll = false;


	// will get charater roataion movement and set it at a rate of 600 on y axis  
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 600.0f, 0.0f);


	MAXwaittime = 100;
	CURwaittime = MAXwaittime;
	sit = false;
	sit2 = false;
	sit3 = false;

}


// Called when the game starts or when spawned
void ANPCCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*CURwaittime -= DeltaTime * 4;*/
}

// Called to bind functionality to input
void ANPCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANPCCharacter::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (NextWaypoint)
	{

		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" enemy is hit  by player overlap begin"));

		sit = true;
	}


	if (NextWaypoint_2)
	{

		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" enemy is hit  by player overlap begin"));

		sit2 = true;
	}

	if (NextWaypoint_3)
	{

		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" enemy is hit  by player overlap begin"));

		sit3 = true;
	}
}

void ANPCCharacter::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	sit = false;

	sit2 = false;


	sit3 = false;
}


