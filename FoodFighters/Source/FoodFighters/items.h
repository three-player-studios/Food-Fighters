// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "items.generated.h"


//General Log
DECLARE_LOG_CATEGORY_EXTERN(LogMyGame, Log, All);


UCLASS()
class FOODFIGHTERS_API Aitems : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aitems();

	// name of the object
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemInfo)
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemInfo)
		UTexture2D* Image;

	UPROPERTY(EditAnywhere)
		float PonitsystemCount;

	// collision component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemPoints)
		class USphereComponent* PointsItem;

	// make mesh component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* MyMesh;

	UPROPERTY(EditAnywhere)
		float SphereRadius;

	// called when the objected is interacted with
	UFUNCTION()
		virtual void OnInteract();

	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
