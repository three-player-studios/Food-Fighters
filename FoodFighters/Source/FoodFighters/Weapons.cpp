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
	/*AAI_Bot_M* Character;

	if (&AAI_Bot_M::Head && !&AAI_Bot_M::GetMesh) {
		Character->EnemyHealthCurrent -= 1;
	}*/
}

