// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC_AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Waypoint.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h" 
#include "Food.h"
#include "NPCCharacter.h"
ANPC_AIController::ANPC_AIController()
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
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ANPC_AIController::OnFoodDectected);
															
	//the  Perception Component attaches to the ConfigureSense which is a pointer to my SightConfig
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
}

void ANPC_AIController::BeginPlay()
{
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

void ANPC_AIController::Possess(APawn * Pawn)
{



}

void ANPC_AIController::Tick(float DeltaSecounds)
{
	ANPCCharacter* NPCChar = Cast<	ANPCCharacter>(GetPawn());

	////// if thre Distance From the food is greater the AIEyeRadius then bot wiil see nothing 
	if (DistanceFromFood > AIEyeRadius)
	{
		IsTheFoodDetected = false;
		UE_LOG(LogTemp, Warning, TEXT("I dont see anything im just going to keep waiting"));
	}

	//ai bot will move to the next waypoint if the these conditon are done 
	if (NPCChar->NextWaypoint != nullptr && IsTheFoodDetected == false && NPCChar->CURwaittime > 0)
	{
		MoveToActor(NPCChar->NextWaypoint, 5.0f);
		UE_LOG(LogTemp, Warning, TEXT(" going to waypont"));
	}


	if (NPCChar->CURwaittime < 0) 
	{
	
		MoveToActor(NPCChar->NextWaypoint, 5.0f);

	}
}

FRotator ANPC_AIController::GetControlRotation() const
{
	return FRotator();
}

void ANPC_AIController::OnFoodDectected(TArray<AActor*> DectectedPlayer)
{
	//gets distance between ai bot and player 
	//for (size_t i = 0; i < DectectedFood.Num(); i++)
	//{
	//	DistanceFromFood = GetPawn()->GetDistanceTo(DectectedFood[i]);

	//	UE_LOG(LogTemp, Warning, TEXT("I see the food %f "), DistanceFromFood);
	//}
	//food is found 
	IsTheFoodDetected = true;
}
