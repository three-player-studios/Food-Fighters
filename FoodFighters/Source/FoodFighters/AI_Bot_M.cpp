// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Bot_M.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "FoodFightersCharacter.h"
#include "items.h"
#include "AI_Bot_M_Prey.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "DrawDebugHelpers.h"

// Sets default values
AAI_Bot_M::AAI_Bot_M()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// will get charater roataion movement and set it at a rate of 600 on y axis  
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 600.0f, 0.0f);


	triggerC = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	triggerC->InitSphereRadius(96.0f);
	triggerC->SetCollisionProfileName(TEXT("trigger"));
	triggerC->SetupAttachment(RootComponent);

	triggerC->OnComponentBeginOverlap.AddDynamic(this, &AAI_Bot_M::OnOverlapBegin);
	triggerC->OnComponentEndOverlap.AddDynamic(this, &AAI_Bot_M::OnOverlapEnd);


	Head = CreateDefaultSubobject<UBoxComponent>(TEXT("headComponent"));
	Head->OnComponentBeginOverlap.AddDynamic(this, &AAI_Bot_M::OnOverlapBegin);
	Head->OnComponentEndOverlap.AddDynamic(this, &AAI_Bot_M::OnOverlapEnd);
	Head->SetCollisionProfileName(TEXT("headtrigger"));
	Head->SetupAttachment(RootComponent);

	EnemyMaxHealth = 30;
	EnemyHealthCurrent = EnemyMaxHealth;

}

void AAI_Bot_M::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

	if (&AFoodFightersCharacter::ActorToWorld)
	{
		/*GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" enemy is hit  by player overlap begin"));*/

	}
	/*if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" enemy is hit overlap begin"));
		}


<<<<<<< HEAD

=======
		if (&AFoodFightersCharacter::ActorToWorld)
		{
		//	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" enemy is hit  by player overlap begin"));

		}
>>>>>>> 4ac1e533fa6ebc84c67606fd3f87bc521ae64f6f


		if (&Aitems::ActorToWorld)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" enemy is hit  item overlap begin"));

		}

		if (&AAI_Bot_M_Prey::ActorToWorld)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" enemy is hit  by prey monster  overlap begin"));

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

void AAI_Bot_M::EDeath()
{
	if (EnemyHealthCurrent <= 0)
	{
		//ERespawn();
		//Destroy();

	}
}

void AAI_Bot_M::ERespawn()
{

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

	//EnemyHealthCurrent -= DeltaTime*4;
	//UE_LOG(LogTemp, Warning, TEXT(" my health is %f "), EnemyHealthCurrent);

	////EDeath();

}

// Called to bind functionality to input
void AAI_Bot_M::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAI_Bot_M::TakeDamageNormal() {
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" enemy is hit  by weapon overlap begin"));
	EnemyHealthCurrent--;
}

