// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCCharacter.h"

// Sets default values
ANPCCharacter::ANPCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

void ANPCCharacter::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (NextWaypoint)
	{

		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" sit"));

		sit = true;
	}


	if (NextWaypoint_2)
	{

		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" sit2"));

		sit2 = true;
	}

	if (NextWaypoint_3)
	{

		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" sit3"));

		sit3 = true;
	}
}

void ANPCCharacter::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{



		sit = false;

		sit2 = false;


		sit3 = false;
	

}

void ANPCCharacter::EDeath()
{
}

void ANPCCharacter::ERespawn()
{
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

void ANPCCharacter::TakeDamageNormal()
{
}

