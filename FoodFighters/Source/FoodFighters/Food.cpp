// Fill out your copyright notice in the Description page of Project Settings.

#include "Food.h"
#include "FoodFighters/FoodFightersCharacter.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	////Creates USceneComponent
	//Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	////set the root Component to root
	//SetRootComponent(Root);
	////Creates UBoxComponent
	//BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Tigger"));

	////BoxComponent attches to RootComponent
	//BoxComponent->SetupAttachment(GetRootComponent());

	//////BoxComponent attches to an overlap component which connets to OnPlayerEnter function 
	//BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AFood::OnOverlapBegin);

	SphereRadius = 100.0f;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	CollisionSphere->InitSphereRadius(SphereRadius);
	CollisionSphere->SetCollisionProfileName("Trigger");
	RootComponent = CollisionSphere;




	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	MyMesh->SetupAttachment(RootComponent);

	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AFood::OnOverlapBegin);

	foodplace = false;
	foodplace2 = false;
	foodplace3 = false;

}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFood::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
//	ATable* table = nullptr;
//	AFood * foodItem = nullptr;
//
//	table = Cast<ATable>(OtherActor);
//
//	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
//	{
//
//		
//		if (table->FoodBox2) 
//		{
//			foodItem->GetActorLocation() = table->GetActorLocation();
//			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" food is on table 2"));
//		}
//		
//
//		if (table->FoodBox3)
//		{
//			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT(" food is on table 3"));
//		}
//	}
//
}

