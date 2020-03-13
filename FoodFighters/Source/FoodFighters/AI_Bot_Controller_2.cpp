// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Bot_Controller_2.h"
#include "NPCCharacter.h"
//#include "Waypoint.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

 AAI_Bot_Controller_2::AAI_Bot_Controller_2()
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
	 GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AAI_Bot_Controller_2::OnPawnDetected);
	 //the  Perception Component attaches to the ConfigureSense which is a pointer to my SightConfig
	 GetPerceptionComponent()->ConfigureSense(*SightConfig);

}
void AAI_Bot_Controller_2::BeginPlay()
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

void AAI_Bot_Controller_2::Possess(APawn * Pawn)
{
	Super::Possess(Pawn);
}

void AAI_Bot_Controller_2::Tick(float DeltaSecounds)
{
	Super::Tick(DeltaSecounds);
	//ANPCCharacter* NCharacter = Cast<ANPCCharacter>(GetPawn());
////ai bot will move to the next waypoint if the these conditon are done 
	


		//if (NCharacter->NextWaypoint != nullptr)
		//{

		//	MoveToActor(NCharacter->NextWaypoint, 5.0f);


		//}
	
	
	////ai bot will move to the next waypoint if the these conditon are done 
	//if (NCharacter->NextWaypoint_2 != nullptr)
	//{

	//	MoveToActor(NCharacter->NextWaypoint_2, 5.0f);
	//	UE_LOG(LogTemp, Warning, TEXT(" going to waypont 2"));



	//}
	//

	//if (NCharacter->CURwaittime < 0)
	//{

	//	MoveToActor(NCharacter->NextWaypoint_Exit, 5.0f);
	//	Destroy();

	//}

}

FRotator AAI_Bot_Controller_2::GetControlRotation() const
{
	//will return ai bot pawn roatation in the z axis
	if (GetPawn() == nullptr)
	{
		return FRotator(0.0f, 0.0f, 0.0f);
	}
	return FRotator(0.0f, GetPawn()->GetActorRotation().Yaw, 0.0f);

}

void AAI_Bot_Controller_2::OnPawnDetected(TArray<AActor*> DectectedPlayer)
{
	/*if (DectectedPlayer.Num() > 0) 
	{
	
	}*/
}

