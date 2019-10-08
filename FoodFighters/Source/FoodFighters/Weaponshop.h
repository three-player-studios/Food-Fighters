// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weaponshop.generated.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "FoodFightersCharacter.generated.h"

UCLASS()
class FOODFIGHTERS_API AWeaponshop : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponshop();

	// collision component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemPoints)
		class USphereComponent* Spherecomponent;

	// make mesh component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* MyWeaponMesh;

	UPROPERTY(EditAnywhere)
		float SphereRadius;


	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


	
};
