// Fill out your copyright notice in the Description page of Project Settings.

#include "KitchenDesk.h"


// Sets default values
AKitchenDesk::AKitchenDesk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	/*PrimaryActorTick.bCanEverTick = true;

	DeskBox = CreateDefaultSubobject<UBoxComponent>(TEXT("	RootComponent"));
	RootComponent = DeskBox;

	DeskMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DeskMesh"));
	DeskMesh->SetupAttachment(RootComponent);


	DeskBox->OnComponentBeginOverlap.AddDynamic(this, &AKitchenDesk::OnOverlapBegin);
	DeskBox->SetCollisionProfileName(TEXT("DeskBoxBoxtrigger"));
	DeskBox->SetupAttachment(RootComponent);*/

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

