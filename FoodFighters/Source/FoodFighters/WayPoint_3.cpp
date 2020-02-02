// Fill out your copyright notice in the Description page of Project Settings.

#include "WayPoint_3.h"


// Sets default values
AWayPoint_3::AWayPoint_3()
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
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AWayPoint_3::OnPlayerEnter);

}

// Called when the game starts or when spawned
void AWayPoint_3::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWayPoint_3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWayPoint_3::OnPlayerEnter(UPrimitiveComponent * OverlapComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//AAI_Bot_M* Character = nullptr;

	////neew
	//full = true;
	//if (OtherActor != nullptr)
	//{

	//	Character = Cast<AAI_Bot_M>(OtherActor);
	//	if (Character != nullptr)
	//	{
	//		Character->NextWaypoint = NextWaypoint;

	//	}
	//}
}

