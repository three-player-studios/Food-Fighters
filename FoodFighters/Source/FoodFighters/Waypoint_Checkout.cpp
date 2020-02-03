// Fill out your copyright notice in the Description page of Project Settings.

#include "Waypoint_Checkout.h"


// Sets default values
AWaypoint_Checkout::AWaypoint_Checkout()
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
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AWaypoint_Checkout::OnPlayerEnter);

}

// Called when the game starts or when spawned
void AWaypoint_Checkout::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWaypoint_Checkout::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWaypoint_Checkout::OnPlayerEnter(UPrimitiveComponent * OverlapComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	ANPCCharacter* Character = nullptr;

	//neew
	full = true;
	if (OtherActor != nullptr)
	{

		Character = Cast<ANPCCharacter>(OtherActor);
		if (Character != nullptr)
		{
			Character->NextWaypoint_Checkout = NextWaypoint_Checkout;

		}
	}
}

