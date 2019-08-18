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

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	WeaponMesh->SetupAttachment(RootComponent);


	WeaponBox->OnComponentBeginOverlap.AddDynamic(this, &AWeapons::OnOverlapBegin);

	StatBooost1 = 2;
	StatBooost2 = 2;
	StatBooost3 = 2;
	StatBooost4 = 2;
	StatBooost5 = 2;
	StatBooost6 = 2;
	EffectDanamge = 2;
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

	AAI_Bot_M* Eactor = Cast<AAI_Bot_M>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));;
	AFoodFightersCharacter* Player = Cast< AFoodFightersCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	// if weapon touches enemy them attck funiton will be called 
	if (&AAI_Bot_M::Head && !&AAI_Bot_M::GetMesh) {
		Attack();
	}



	if (Player->triggerCapsule)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("weapon in hand "));
		UE_LOG(LogTemp, Warning, TEXT("weapon stat %f"), Player->CURSPD);
		Player->CURDEX += StatBooost1;
		Player->CURLUCK += StatBooost2 + EffectDanamge;
		Player->CURSPD +=StatBooost3;
		Player->CURSTR += StatBooost4;
		Player->CURVIT += StatBooost5;
		Player->CURDEF += StatBooost6;
	}

}

void AWeapons::Attack()
{
	AFoodFightersCharacter* Player = Cast< AFoodFightersCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	AAI_Bot_M* Eactor = Cast<AAI_Bot_M>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));;

	// if attack is true then damage will be made 
	if (attacktrue) 
	{

		BaseDanamge = Player->CURSTR + Player->CURLUCK - Eactor->CURDEF - Eactor->Baselevel;
		 

		Eactor->TakeDamageNormal();

		if (Player->CRITCHANCE == FMath::FRandRange(10, 100))
		{

			BaseDanamge *= 2;

		}
	}
}

