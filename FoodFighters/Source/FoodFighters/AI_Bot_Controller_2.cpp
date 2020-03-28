// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Bot_Controller_2.h"
#include "NPCCharacter.h"
#include "Kismet/KismetMathLibrary.h"
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
	//////ai bot will move to the next waypoint if the these conditon are done 
	//
	//// if thre Distance From the Player is greater the AIEyeRadius then bot wiil see nothing 
	//if (DistanceToPlayer > AIEyeRadius)
	//{
	//	IsThePlayerDetected = false;
	//	UE_LOG(LogTemp, Warning, TEXT("I dont see anything im just going to keep patroling"));
	//}

	//// ai bot will move to the next waypoint if it does not see the player  
	//if ( IsThePlayerDetected == false)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("I dont see anything im just going to keep patroling"));
	//}
	//// if the player is seen ai bot will chase after player 
	//else if (IsThePlayerDetected == true)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("I  see you %f "), NCharacter->GetActorLocation());

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
	//gets distance between ai bot and player 
	for (size_t i = 0; i < DectectedPlayer.Num(); i++)
	{
		DistanceToPlayer = GetPawn()->GetDistanceTo(DectectedPlayer[i]);
		UE_LOG(LogTemp, Warning, TEXT("I see the player %f "), DistanceToPlayer);
	}

	//player is found 
	IsThePlayerDetected = true;

}


