// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Bot_M.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "FoodFightersCharacter.h"
#include "items.h"
#include "AI_Bot_M_Prey.h"

// Sets default values
AAI_Bot_M::AAI_Bot_M()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// will get charater roataion movement and set it at a rate of 600 on y axis  
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 600.0f, 0.0f);


	triggerC = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	triggerC->InitSphereRadius( 96.0f);
	triggerC->SetCollisionProfileName(TEXT("trigger"));
	triggerC->SetupAttachment(RootComponent);

	triggerC->OnComponentBeginOverlap.AddDynamic(this, &AAI_Bot_M::OnOverlapBegin);
	triggerC->OnComponentEndOverlap.AddDynamic(this, &AAI_Bot_M::OnOverlapEnd);



}

void AAI_Bot_M::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	if (&AFoodFightersCharacter::ActorToWorld)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" enemy is hit  by player overlap begin"));

	}
	/*if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" enemy is hit overlap begin"));
		}


		


		if (&Aitems::ActorToWorld)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" enemy is hit  item overlap begin"));

		}

		if (&AAI_Bot_M_Prey::ActorToWorld)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" enemy is hit  by prey monster  overlap begin"));

		}

	}*/
}

void AAI_Bot_M::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	/*if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" enemy is not hit overlap end"));
		}
	}*/
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

