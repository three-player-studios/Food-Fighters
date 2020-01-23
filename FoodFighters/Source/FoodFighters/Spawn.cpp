//// Fill out your copyright notice in the Description page of Project Settings.
//
//#include "Spawn.h"
//#include "Kismet/GameplayStatics.h" 
//#include "Components/BoxComponent.h"
//#include "GameFramework/Actor.h"
//#include "GameFramework/Pawn.h"
//#include"Engine.h"
//#include "UObject/ConstructorHelpers.h"
//#include "ObjectPool.h"
//#include "Water.h"
//
//// Sets default values
//ASpawn::ASpawn()
//{
// 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//	Spawnvol = CreateDefaultSubobject<UBoxComponent>(TEXT("spawnvol"));
//	RootComponent = Spawnvol;
//	Objectpoler = CreateDefaultSubobject<UObjectPool>(TEXT("pooler"));
//
//}
//
//// Called when the game starts or when spawned
//void ASpawn::BeginPlay()
//{
//	Super::BeginPlay();
//
//	GetWorldTimerManager().SetTimer(SpawnbCooldownTime, this, &ASpawn::SpawnObj, SpawnCooldown, false);
//
//	
//}
//
//
//// Called every frame
//void ASpawn::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}
//
//
//
//void ASpawn::SpawnObj()
//{
//	//ACharacter* myChar = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
//
//		UWorld* world = GetWorld();
//		FActorSpawnParameters spawnPar;
//		spawnPar.Owner = this;
//		FRotator rot;
//		/*FVector spawnloc = this->Spawnvol->GetComponentLocation();*/
//		FVector spawnloc = cup->GetActorLocation();
//		AWater* poolactor = Objectpoler->GetObject();
//		if (poolactor == nullptr)
//		{
//			UE_LOG(LogTemp, Warning, TEXT("All System not Set"));
//
//			GetWorldTimerManager().SetTimer(SpawnbCooldownTime, this, &ASpawn::SpawnObj, SpawnCooldown, false);
//			return;
//
//		}
//
//
//
//			// poolactor->SetActorLocation(myChar->GetNavAgentLocation());
//			poolactor->SetActorLocation(spawnloc);
//			poolactor->SetLifeSpan(TimeSpan);
//			poolactor->SetActive(true);
//			//poolactor->SetActorRotation(myChar->GetActorRotation());
//			poolactor->SetActorRotation(rot);
//			GetWorldTimerManager().SetTimer(SpawnbCooldownTime, this, &ASpawn::SpawnObj, SpawnCooldown, false);
//			UE_LOG(LogTemp, Warning, TEXT("Spawned"));
//	
//}
//
