// Fill out your copyright notice in the Description page of Project Settings.

#include "Cup.h"
#include "Kismet/GameplayStatics.h" 
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include"Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "ObjectPool.h"
#include "Water.h"

// Sets default values
ACup::ACup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	raduis = 100;
	CupSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CupSphere->InitSphereRadius(raduis);
	CupSphere->SetCollisionProfileName(TEXT("Boxtrigger"));
	RootComponent = CupSphere;
	CupSphere->OnComponentBeginOverlap.AddDynamic(this, &ACup::OnOverlapBegin);


//RootComponent = CupBox;

	CupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	CupMesh->BodyInstance.SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
	CupMesh->SetNotifyRigidBodyCollision(true);
	CupMesh->SetupAttachment(RootComponent);
	Objectpoler = CreateDefaultSubobject<UObjectPool>(TEXT("pooler"));
	trigger = false;
}

// Called when the game starts or when spawned
void ACup::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnbCooldownTime, this, &ACup::SpawnObj, SpawnCooldown, false);

	
}

void ACup::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	//{


	//	// Turn off the light  
	//	UE_LOG(LogTemp, Warning, TEXT("Objecet collide"));
	//
	//	trigger = true;	
	///*	Destroy();*/
	//}
	//else {
	//	UE_LOG(LogTemp, Warning, TEXT("Objecet failed to collide"));

	//}
		 if (trigger == false)
	{

		FRotator rot;
		FVector spawnloc = this->CupSphere->GetComponentLocation();
		AWater* poolactor = Objectpoler->GetObject();

		UE_LOG(LogTemp, Warning, TEXT("Objecet collide"));
		UE_LOG(LogTemp, Warning, TEXT("trigger false"));
		if (poolactor == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("All System not Set"), poolactor);

			GetWorldTimerManager().SetTimer(SpawnbCooldownTime, this, &ACup::SpawnObj, SpawnCooldown, false);
			return;

		}

		poolactor->SetActorLocation(spawnloc);
		poolactor->SetLifeSpan(TimeSpan);
		poolactor->SetActive(true);
		poolactor->SetActorRotation(rot);
		GetWorldTimerManager().SetTimer(SpawnbCooldownTime, this, &ACup::SpawnObj, SpawnCooldown, false);
		UE_LOG(LogTemp, Warning, TEXT("Spawned"));
		trigger = true;
	}
		
		 
		 if (trigger == true)
		 {
			 SpawnObj();
		 }
		
}


	




void ACup::SpawnObj()
{

	if (trigger == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Objecet failed to collide"));
		UE_LOG(LogTemp, Warning, TEXT("trigger true"));
		FRotator rot;
		FVector spawnloc = this->CupSphere->GetComponentLocation();
		AWater* poolactor = Objectpoler->GetObject();
		UE_LOG(LogTemp, Warning, TEXT("trigger true"), poolactor);
		if (poolactor == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("All System not Set"), poolactor);

			GetWorldTimerManager().SetTimer(SpawnbCooldownTime, this, &ACup::SpawnObj, SpawnCooldown, false);
			return;

		}

		poolactor->SetActorLocation(spawnloc);
		poolactor->SetLifeSpan(TimeSpan);
		poolactor->SetActive(false);
		poolactor->SetActorRotation(rot);
		GetWorldTimerManager().SetTimer(SpawnbCooldownTime, this, &ACup::SpawnObj, SpawnCooldown, false);
		UE_LOG(LogTemp, Warning, TEXT("Not Spawned"));
		trigger = false;
		UE_LOG(LogTemp, Warning, TEXT("trigger false"));

	}
	

}

// Called every frame
void ACup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}





















/*AWater* poolactor = Objectpoler->GetObject();
 if (trigger == false)
{
	poolactor->SetActive(false);
}
*/