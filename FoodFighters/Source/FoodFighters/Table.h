// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Food.h"
//#include "AI_Bot_Controller_M.h"
//#include "AI_Bot_M.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "FoodFightersCharacter.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Table.generated.h"

UCLASS()
class FOODFIGHTERS_API ATable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	// collision component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemPoints)
		class UBoxComponent* FoodBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemPoints)
		class UBoxComponent* FoodBox2;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemPoints)
		class UBoxComponent* FoodBox3;
	

	// make mesh component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* MyMesh;



	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AFood* fooditem;

	//// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	
};
