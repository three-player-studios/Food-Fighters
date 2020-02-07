// Fill out your copyright notice in the Description page of Project Settings.

#include "Table.h"


// Sets default values
ATable::ATable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FoodBox = CreateDefaultSubobject<UBoxComponent>(TEXT("FoodComponent"));
	FoodBox2 = CreateDefaultSubobject<UBoxComponent>(TEXT("FoodComponent2"));
	FoodBox3 = CreateDefaultSubobject<UBoxComponent>(TEXT("FoodComponent3"));


	RootComponent = FoodBox;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	MyMesh->SetupAttachment(RootComponent);

	foodplace =false;
	foodplace2 = false;
	foodplace3 = false;

}

// Called when the game starts or when spawned
void ATable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATable::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{




}

void ATable::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
}

