// Fill out your copyright notice in the Description page of Project Settings.

#include "Waypoint_2.h"
#include"NPCCharacter.h"
#include "AI_Bot_M.h"
// Sets default values
AWaypoint_2::AWaypoint_2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//Creates USceneComponent
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//set the root Component to root
	SetRootComponent(Root);
	//Creates UBoxComponent
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Tigger"));

	//BoxComponent attches to RootComponent
	BoxComponent->SetupAttachment(GetRootComponent());

	////BoxComponent attches to an overlap component which connets to OnPlayerEnter function 
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AWaypoint_2::OnPlayerEnter);

}

// Called when the game starts or when spawned
void AWaypoint_2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWaypoint_2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWaypoint_2::OnPlayerEnter(UPrimitiveComponent * OverlapComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AAI_Bot_M* Character = nullptr;
	ANPCCharacter* NCharacter = nullptr;
	//neew

	if (OtherActor != nullptr)
	{

		//Character = Cast<AAI_Bot_M>(OtherActor);
		//NCharacter = Cast<ANPCCharacter>(OtherActor);

		//if (Character != nullptr)
		//{
		//	Character->NextWaypoint_2 = NextWaypoint_2;
		//	full = true;
		//}

		//if (NCharacter != nullptr)
		//{
		//	NCharacter->NextWaypoint_2 = NextWaypoint_2;
		//	full = true;
		//}


	}
}

