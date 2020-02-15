// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC_AIController.h"

ANPC_AIController::ANPC_AIController()
{
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
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ANPC_AIController::OnPlayerDectected);
	//the  Perception Component attaches to the ConfigureSense which is a pointer to my SightConfig
	GetPerceptionComponent()->ConfigureSense(*SightConfig);

}

void ANPC_AIController::BeginPlay()
{
}

void ANPC_AIController::Possess(APawn * Pawn)
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

void ANPC_AIController::Tick(float DeltaSecounds)
{
	//Makes a pointers of my ai bot and make into a pawn  
	ANPCCharacter* Character = Cast<ANPCCharacter>(GetPawn());
	AAI_Bot_M* NCharacter = Cast<AAI_Bot_M>(GetPawn());


	////// if thre Distance From the Player is greater the AIEyeRadius then bot wiil see nothing 
	if (DistanceFromPlayer > AIEyeRadius)
	{
		IsThePlayerDetected = false;
		UE_LOG(LogTemp, Warning, TEXT("I dont see anything im just going to keep patroling"));
	}


	//ai bot will move to the next waypoint if the these conditon are done 
	if (Character->NextWaypoint != nullptr)
	{

		MoveToActor(Character->NextWaypoint, 5.0f);
		UE_LOG(LogTemp, Warning, TEXT(" going to waypont"));


	}


	if (Character->sit == true)
	{
		//ai bot will move to the next waypoint if the these conditon are done 
		if (Character->NextWaypoint_2 != nullptr)
		{

			MoveToActor(Character->NextWaypoint_2, 5.0f);
			UE_LOG(LogTemp, Warning, TEXT(" going to waypont 2"));


		}
	}


	if (Character->sit2 == true)
	{
		//ai bot will move to the next waypoint if the these conditon are done 
		if (Character->NextWaypoint_3 != nullptr)
		{

			MoveToActor(Character->NextWaypoint_3, 5.0f);
			UE_LOG(LogTemp, Warning, TEXT(" going to waypont 3"));


		}
	}


	if (Character->CURwaittime < 0)
	{

		MoveToActor(Character->NextWaypoint_Exit, 5.0f);
		Destroy();

	}
	
}

FRotator ANPC_AIController::GetControlRotation() const
{
	if (GetPawn() == nullptr)
	{
		return FRotator(0.0f, 0.0f, 0.0f);
	}
	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);

}

void ANPC_AIController::AttckSound()
{
}

void ANPC_AIController::WalkSound()
{
}

void ANPC_AIController::DeathSound()
{
}

bool ANPC_AIController::Damage()
{
	return false;
}

bool ANPC_AIController::Attack()
{
	return false;
}

void ANPC_AIController::OnPlayerDectected(TArray<AActor*> DectectedPlayer)
{
}

void ANPC_AIController::OnPreyDectected(TArray<AActor*> DectectedPrey)
{
}

void ANPC_AIController::OnPlayerFound()
{
}

void ANPC_AIController::OnPreyFound()
{
}
