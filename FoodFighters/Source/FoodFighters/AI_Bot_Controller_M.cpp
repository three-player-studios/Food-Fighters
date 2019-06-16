// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Bot_Controller_M.h"
#include "Perception/AIPerceptionComponent.h"// A libary that contains the Perception of ai
#include "Perception/AISenseConfig_Sight.h"// A libary that configers ai sight 
#include "AI_Bot_M.h"
#include "AI_Waypoint.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "FoodFightersCharacter.h"


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


	EnemyHealthCurrent = EnemyMaxHealth;
}

void AAI_Bot_Controller_M::BeginPlay()
{
	//comfirms if PerceptionComponent is working 
	if (GetPerceptionComponent() != nullptr) {
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

	// ai bot will move to the next waypoint if it does not see the player  
	if (Character->NextWaypoint != nullptr && IsThePlayerDetected == false)
	{
		MoveToActor(Character->NextWaypoint, 5.0f);
	}


	// if the player is seen ai bot will chase after player 
	else if (IsThePlayerDetected == true)
	{
		AFoodFightersCharacter* Player = Cast< AFoodFightersCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		MoveToActor(Player, 5.0f);

	}
		///* if the player is in raidus and health is greater
		//then cetain ammount then ai bot will attack if not then it will not attack*/
		//if (AIEyeRadius <= 100 && EnemyHealthCurrent >= 10)
		//{
		//	Attack();
		//}
		//else
		//{
		//	!Attack();
		//}

		
		
		
	//	/* if the player is in raidus and health is greater
	//	then cetain ammount then ai bot will attack if not then it will not attack*/
	//	if (Damage)
	//	{
	//		EnemyHealthCurrent - 2;

	//	}
	//}


	//if (Attack)
	//{

	//	//playerhealth - 1;

	//}
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

void AAI_Bot_Controller_M::Sound()
{
}

void AAI_Bot_Controller_M::Sound2()
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


//Function that will dectecte player distance 
void  AAI_Bot_Controller_M::OnPlayerDectected(TArray<AActor*> DectectedPlayer)
{
	//gets distance between ai bot and player 
	for (size_t i = 0; i < DectectedPlayer.Num(); i++)
	{
		DistanceFromPlayer = GetPawn()->GetDistanceTo(DectectedPlayer[i]);
		UE_LOG(LogTemp, Warning, TEXT("I see the player %f "), DistanceFromPlayer);
	}

	//player is found 
	IsThePlayerDetected = true;


}
