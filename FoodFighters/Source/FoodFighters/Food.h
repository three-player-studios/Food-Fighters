// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Food.generated.h"

UCLASS()
class FOODFIGHTERS_API AFood : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFood();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// name of the object
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemInfo)
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemInfo)
		UTexture2D* Image;

	// collision component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemPoints)
		class USphereComponent* CollisionSphere;

	UPROPERTY(EditAnywhere)
		float SphereRadius;
};
