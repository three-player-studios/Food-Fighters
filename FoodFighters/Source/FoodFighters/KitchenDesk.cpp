// Fill out your copyright notice in the Description page of Project Settings.

#include "KitchenDesk.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include"Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h" 
#include "DrawDebugHelpers.h"
#include "AI_Bot_M.h"
#include "FoodFightersCharacter.h"

// Sets default values
AKitchenDesk::AKitchenDesk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DeskBox = CreateDefaultSubobject<UBoxComponent>(TEXT("	RootComponent"));
	RootComponent = DeskBox;

	DeskMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DeskMesh"));
	DeskMesh->SetupAttachment(RootComponent);


	DeskBox->OnComponentBeginOverlap.AddDynamic(this, &AKitchenDesk::OnOverlapBegin);
	DeskBox->SetCollisionProfileName(TEXT("Boxtrigger"));
	DeskBox->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AKitchenDesk::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKitchenDesk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKitchenDesk::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
}

