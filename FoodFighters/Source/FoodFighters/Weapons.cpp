// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapons.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include"Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "DrawDebugHelpers.h"
#include "AI_Bot_M.h"
#include "AI_Bot_M_Prey.h"
#include "FoodFightersCharacter.h"

// Sets default values
AWeapons::AWeapons()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("	WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);

	WeaponBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponBox Component"));
	WeaponBox->OnComponentBeginOverlap.AddDynamic(this, &AWeapons::OnOverlapBegin);
	WeaponBox->SetCollisionProfileName(TEXT("WeaponBox trigger"));
	WeaponBox->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AWeapons::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AWeapons::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AWeapons::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr)) {
		if (OtherActor->ActorHasTag(TEXT("Bad"))) {
			//for (TActorIterator<AStaticMeshActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
			//{
			//	// Same as with the Object Iterator, access the subclass instance with the * or -> operators.
			//	AStaticMeshActor *Mesh = *ActorItr;
			//	ClientMessage(ActorItr->GetName());
			//	ClientMessage(ActorItr->GetActorLocation().ToString());
			//	if (ActorItr == AAI_Bot_M && AAI_Bot_M == OtherActor) {
			//		&ActorItr->TakeDamageNormal;
			//	}
			//}
		}
	
	}
}

