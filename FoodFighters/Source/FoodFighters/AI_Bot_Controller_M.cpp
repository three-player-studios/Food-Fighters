// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Bot_Controller_M.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "AI_Bot_M.h"
#include "Waypoint.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h" 
#include "AI_Bot_M_Prey.h"
#include "FoodFightersCharacter.h"
#include "items.h"



AAI_Bot_Controller_M::AAI_Bot_Controller_M() 
{
	PrimaryActorTick.bCanEverTick = true;



	//Creates a component that configres ai bot sight 
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

	//Creates a component that gets the perception of the ai bot 
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent")));

	// the AI Sense Configre Sight Component  will get the SightRadius and make it  equal  to the AIEyeRadius
	SightConfig->SightRadius = AIEyeRadius;

	// the AI Sense Configre Sight Component  will get the loseSightRadius and make it  equal  to the AILostEyeRaduis
	SightConfig->LoseSightRadius = AILostEyeRaduis;

	// the AI Sense Configre Sight Component  will get  the angle of sight in degress and it will equal AIEyeAngle
	SightConfig->PeripheralVisionAngleDegrees = AIEyeAngle;

	//set the max amount of time ai bot will remeber player  
	SightConfig->SetMaxAge(AIEyeMemroy);


	// will detect if a player is an enemie, friend or neutral
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	//the  Perception Component attaches to  SetDominantSense which wil make eye  sight the most sense for my ai bot 
	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());

	// updates perception if the player is dected 
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AAI_Bot_Controller_M::OnPlayerDectected);
	//the  Perception Component attaches to the ConfigureSense which is a pointer to my SightConfig
	GetPerceptionComponent()->ConfigureSense(*SightConfig);

}

void AAI_Bot_Controller_M::BeginPlay()
{

	Super::BeginPlay();

	//comfirms if PerceptionComponent is working 
	if (GetPerceptionComponent() != nullptr) 
	{
		UE_LOG(LogTemp, Warning, TEXT("All System Set"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("All System not Set"));

	}
}

void AAI_Bot_Controller_M::Possess(APawn * Pawn)
{
	Super::Possess(Pawn);
}

void AAI_Bot_Controller_M::Tick(float DeltaSecounds)
{
	Super::Tick(DeltaSecounds);

	//Makes a pointers of my ai bot and make into a pawn  
	AAI_Bot_M* Character = Cast<AAI_Bot_M>(GetPawn());


	// if thre Distance From the Player is greater the AIEyeRadius then bot wiil see nothing 
	if (DistanceFromPlayer > AIEyeRadius)
	{
		IsThePlayerDetected = false;
		UE_LOG(LogTemp, Warning, TEXT("I dont see anything im just going to keep patroling"));
	}


	// if thre Distance From the item is greater the AIEyeRadius then bot wiil see nothing 
	if (DistanceFromItem > AIEyeRadius)
	{
		IsTheitemDetected = false;
		UE_LOG(LogTemp, Warning, TEXT("I dont see anything im just going to keep patroling"));
	}

	// if thre Distance From the Prey is greater the AIEyeRadius then bot wiil see nothing 
	if (DistanceFromPrey > AIEyeRadius)
	{
		IsThePreyDetected = false;
		UE_LOG(LogTemp, Warning, TEXT("I dont see anything im just going to keep patroling"));
	}



	 //ai bot will move to the next waypoint if it does not see the player  
	if (Character->NextWaypoint != nullptr && IsThePlayerDetected == false  && IsTheitemDetected == false && IsThePreyDetected == false)
	{
		MoveToActor(Character->NextWaypoint, 5.0f);
		UE_LOG(LogTemp, Warning, TEXT(" going to waypont"));


	}

	// if the player is seen ai bot will chase after player 
	else if (IsThePlayerDetected == true )
	{
		AFoodFightersCharacter* Player = Cast<AFoodFightersCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
		if (Character->EnemyHealthCurrent > Character->EnemyHealthCurrent / 2) {
			MoveToActor(Player, 5.0f);
			UE_LOG(LogTemp, Warning, TEXT("I see the player  must chase"));
		}
		else 
		{
			MoveToActor(Character->NextWaypoint, 5.0f);
			UE_LOG(LogTemp, Warning, TEXT(" running away "));
		}

	}


	// if the player is seen ai bot will chase after player 
	else if (IsTheitemDetected == true)
	{
		//Aitems * Item = Cast<Aitems>(U
	
		//	MoveToActor(Item, 5.0f);
		//	UE_LOG(LogTemp, Warning, TEXT("Im hungry must eat "));
	
	}



}

FRotator AAI_Bot_Controller_M::GetControlRotation() const
{
	//will return ai bot pawn roatation in the z axis
	if (GetPawn() == nullptr)
	{
		return FRotator(0.0f, 0.0f, 0.0f);
	}
	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);

}



void AAI_Bot_Controller_M::OnPlayerDectected(TArray<AActor*> DectectedPlayer)
{	
	//gets distance between ai bot and player 
	for (size_t i = 0; i < DectectedPlayer.Num(); i++)
	{
		DistanceFromPlayer = GetPawn()->GetDistanceTo(DectectedPlayer[i]);
		UE_LOG(LogTemp, Warning, TEXT("I see the player %f "),DistanceFromPlayer);
	}
	
	//player is found 
	IsThePlayerDetected = true;
}

void AAI_Bot_Controller_M::OnitemDectected(TArray<AActor*> Dectecteditem)
{
	//gets distance between ai bot and item 
	for (size_t i = 0; i < Dectecteditem.Num(); i++)
	{
		DistanceFromItem = GetPawn()->GetDistanceTo(Dectecteditem[i]);
		UE_LOG(LogTemp, Warning, TEXT("I see the item %f "), DistanceFromItem);
	}

	//item is found 
	IsTheitemDetected = true;
}

void AAI_Bot_Controller_M::OnPreyDectected(TArray<AActor*> DectectedPrey)
{
	//gets distance between ai bot and Prey
	for (size_t i = 0; i < DectectedPrey.Num(); i++)
	{
		DistanceFromPrey = GetPawn()->GetDistanceTo(DectectedPrey[i]);
		UE_LOG(LogTemp, Warning, TEXT("I see the prey %f "), DistanceFromPrey);
	}

	//item is found 
	IsThePreyDetected = true;

}

void AAI_Bot_Controller_M::AttckSound()
{
}

void AAI_Bot_Controller_M::WalkSound()
{
}

void AAI_Bot_Controller_M::DeathSound()
{
}

bool AAI_Bot_Controller_M::Damage()
{
	return false;
}

bool AAI_Bot_Controller_M::Attack()
{
	return false;
}
