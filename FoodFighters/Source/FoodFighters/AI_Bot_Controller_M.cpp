// Fill out your copyright notice in the Description page of Project Settings.

#include "AI_Bot_Controller_M.h"




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

	/*OnPlayerFound();*/
	//OnPreyFound();

	//Makes a pointers of my ai bot and make into a pawn  
	AAI_Bot_M* Character = Cast<AAI_Bot_M>(GetPawn());


	////// if thre Distance From the Player is greater the AIEyeRadius then bot wiil see nothing 
	if (DistanceFromPlayer > AIEyeRadius)
	{
		IsThePlayerDetected = false;
		UE_LOG(LogTemp, Warning, TEXT("I dont see anything im just going to keep patroling"));
	}


	//ai bot will move to the next waypoint if the these conditon are done 
	if (Character->NextWaypoint != nullptr && IsTheFoodDetected == false)
	{

		MoveToActor(Character->NextWaypoint, 5.0f);
		UE_LOG(LogTemp, Warning, TEXT(" going to waypont"));


	}


	if (Character->sit ==true)
	{
		//ai bot will move to the next waypoint if the these conditon are done 
		if (Character->NextWaypoint_2 != nullptr && IsTheFoodDetected == false)
		{

			MoveToActor(Character->NextWaypoint_2, 5.0f);
			UE_LOG(LogTemp, Warning, TEXT(" going to waypont 2"));


		}
	}
	

	if (Character->sit2 == true)
	{
		//ai bot will move to the next waypoint if the these conditon are done 
		if (Character->NextWaypoint_3 != nullptr && IsTheFoodDetected == false)
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

	////ai bot will move to the next waypoint if it does not see the player  
	//if (Character->NextWaypoint != nullptr && IsThePlayerDetected == false)
	//{
	//	MoveToActor(Character->NextWaypoint, 5.0f);
	//	UE_LOG(LogTemp, Warning, TEXT(" going to waypont"));
	//}
	//else if (IsThePlayerDetected == true) 
	//{
	//	AFoodFightersCharacter* Player = Cast<AFoodFightersCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//	MoveToActor(Player, 5.0f);
	//}

	////// if the player is seen ai bot will chase after player 
	//if (Character->EnemyHealthCurrent > Character->EnemyMaxHealth / 2 && IsThePlayerDetected == true)
	//{
	//	AFoodFightersCharacter* Player = Cast<AFoodFightersCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//	MoveToActor(Player, 5.0f);
	//	UE_LOG(LogTemp, Warning, TEXT("I can figt"));
	//}

	//else if (Character->EnemyHealthCurrent < Character->EnemyMaxHealth / 2 && IsThePlayerDetected == true)
	//{
	//	MoveToActor(Character->NextWaypoint, 5.0f);
	//	UE_LOG(LogTemp, Warning, TEXT(" running away "));
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



void AAI_Bot_Controller_M::OnPlayerDectected(TArray<AActor*> DectectedPlayer)
{
	////gets distance between ai bot and player 
	//for (size_t i = 0; i < DectectedPlayer.Num(); i++)
	//{
	//	DistanceFromPlayer = GetPawn()->GetDistanceTo(DectectedPlayer[i]);

	//	UE_LOG(LogTemp, Warning, TEXT("I see the player %f "), DistanceFromPlayer);
	//}
	////player is found 
	//IsThePlayerDetected = true;
}

void AAI_Bot_Controller_M::OnPreyDectected(TArray<AActor*> DectectedPrey)
{
	////gets distance between ai bot and player 
	//for (size_t i = 0; i < DectectedPrey.Num(); i++)
	//{
	//	DistanceFromPrey = GetPawn()->GetDistanceTo(DectectedPrey[i]);

	//	UE_LOG(LogTemp, Warning, TEXT("I see the player %f "), DistanceFromPrey);
	//}
	////player is found 
	//IsThePreyDetected = true;
}

void AAI_Bot_Controller_M::OnPlayerFound()
{

	////Makes a pointers of my ai bot and make into a pawn  
	//AAI_Bot_M* Character = Cast<AAI_Bot_M>(GetPawn());

	////// if thre Distance From the Player is greater the AIEyeRadius then bot wiil see nothing 
	//if (DistanceFromPlayer > AIEyeRadius)
	//{
	//	IsThePlayerDetected = false;
	//	UE_LOG(LogTemp, Warning, TEXT("I dont see anything im just going to keep patroling"));
	//}

	////ai bot will move to the next waypoint if it does not see the player  
	//if (Character->NextWaypoint != nullptr && IsThePlayerDetected == false)
	//{
	//	MoveToActor(Character->NextWaypoint, 5.0f);
	//	UE_LOG(LogTemp, Warning, TEXT(" going to waypont"));
	//}
	//else if (IsThePlayerDetected == true) 
	//{
	//	AFoodFightersCharacter* Player = Cast<AFoodFightersCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//	MoveToActor(Player, 5.0f);
	//}

	////// if the player is seen ai bot will chase after player 
	//if (Character->EnemyHealthCurrent > Character->EnemyMaxHealth / 2 && IsThePlayerDetected == true)
	//{
	//	AFoodFightersCharacter* Player = Cast<AFoodFightersCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//	MoveToActor(Player, 5.0f);
	//	UE_LOG(LogTemp, Warning, TEXT("I can figt"));
	//}

	//else if (Character->EnemyHealthCurrent < Character->EnemyMaxHealth / 2 && IsThePlayerDetected == true)
	//{
	//	MoveToActor(Character->NextWaypoint, 5.0f);
	//	UE_LOG(LogTemp, Warning, TEXT(" running away "));
	//}
}

void AAI_Bot_Controller_M::OnPreyFound()
{
	////Makes a pointers of my ai bot and make into a pawn  
	//AAI_Bot_M* Character = Cast<AAI_Bot_M>(GetPawn());

	////// if thre Distance From the Player is greater the AIEyeRadius then bot wiil see nothing 
	//if (DistanceFromPrey > AIEyeRadius)
	//{
	//	IsThePreyDetected = false;
	//	UE_LOG(LogTemp, Warning, TEXT("I dont see any prey im just going to keep patroling"));
	//}

	////ai bot will move to the next waypoint if it does not see the player  
	//if (Character->NextWaypoint != nullptr && IsThePreyDetected == false)
	//{
	//	MoveToActor(Character->NextWaypoint, 5.0f);
	//	UE_LOG(LogTemp, Warning, TEXT(" going to waypont"));
	//}


	//////// if the player is seen ai bot will chase after player 
	//if (Character->EnemyHealthCurrent > Character->EnemyMaxHealth / 2 && IsThePreyDetected == true)
	//{
	//	AAI_Bot_M_Prey* Prey = Cast<AAI_Bot_M_Prey>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//	MoveToActor(Prey, 5.0f);
	//	UE_LOG(LogTemp, Warning, TEXT("I found food"));
	//}

	//else if (Character->EnemyHealthCurrent < Character->EnemyMaxHealth / 2 && IsThePreyDetected == true)
	//{
	//	MoveToActor(Character->NextWaypoint, 5.0f);
	//	UE_LOG(LogTemp, Warning, TEXT(" running away "));
	//}
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
