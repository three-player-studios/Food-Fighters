// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapons.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include"Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h" 
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

	WeaponBox = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
	RootComponent = WeaponBox;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);
	

	WeaponBox->OnComponentBeginOverlap.AddDynamic(this, &AWeapons::OnOverlapBegin);
	WeaponBox->SetCollisionProfileName(TEXT("WeaponBox trigger"));
	WeaponBox->SetupAttachment(RootComponent);


	float StatBooost1 = FMath::FRandRange(1, 10);
	float StatBooost2 = FMath::FRandRange(1, 10);
	float StatBooost3 = FMath::FRandRange(1, 10);
	float StatBooost4 = FMath::FRandRange(1, 10);
	float StatBooost5 = FMath::FRandRange(1, 10);
	float StatBooost6 = FMath::FRandRange(1, 10);
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
			AAI_Bot_M* Eactor = Cast<AAI_Bot_M>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));;
			AFoodFightersCharacter* Player = Cast< AFoodFightersCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
			
			// if weapon touches enemy them attck funiton will be called 
			if (&AAI_Bot_M::Head && !&AAI_Bot_M::GetMesh) {
				Attack();
			}

		}
	
	}
}

void AWeapons::Attack()
{
	AFoodFightersCharacter* Player = Cast< AFoodFightersCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	AAI_Bot_M* Eactor = Cast<AAI_Bot_M>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));;

	// if attack is true then damage will be made 
	if (attacktrue) {

		BaseDanamge = Player->CURSTR + Player->CURLUCK - Eactor->CURDEF - Eactor->Baselevel;


		if (Player->CRITCHANCE == FMath::FRandRange(10, 100))
		{
		
			BaseDanamge *= 2;
		
		}


	}

}

