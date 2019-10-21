// Fill out your copyright notice in the Description page of Project Settings.

#include "Weaponshop.h"


// Sets default values
AWeaponshop::AWeaponshop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	SphereRadius = 100;

	Spherecomponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));





}

void AWeaponshop::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UWorld* World = GetWorld();
	FString CurrentLevel = World->GetMapName().Mid(World->StreamingLevelsPrefix.Len());
	
	/*if () {}*/
	UGameplayStatics::OpenLevel(World, "MainMenu");
}
