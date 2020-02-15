// Fill out your copyright notice in the Description page of Project Settings.

#include "Armor.h"
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
AArmor::AArmor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	ArmorBox = CreateDefaultSubobject<UBoxComponent>(TEXT("	RootComponent"));
	RootComponent = ArmorBox;

	ArmorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ArmorMesh"));
	ArmorMesh->SetupAttachment(RootComponent);


	ArmorBox->OnComponentBeginOverlap.AddDynamic(this, &AArmor::OnOverlapBegin);
	ArmorBox->SetCollisionProfileName(TEXT("ArmorBoxtrigger"));
	ArmorBox->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void AArmor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArmor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AArmor::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AFoodFightersCharacter* Player = Cast< AFoodFightersCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	AAI_Bot_M* Eactor =  Cast<AAI_Bot_M>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));;

	if (&AAI_Bot_M::Head && !&AAI_Bot_M::GetMesh) {
		Player->CURHealth -= Eactor->BaseSTR +Player->CURDEF;
	}


	if (Player->triggerCapsule)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("ammor on body  "));

		Player->CURDEX += StatBooost1;
		Player->CURLUCK += StatBooost2;
		Player->CURSPD += StatBooost3;
		Player->CURSTR += StatBooost4;
		Player->CURVIT += StatBooost5;
		Player->CURDEF += StatBooost6;
	}


}

