// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "INTERACT_TEST_OBJECT.generated.h"

UCLASS()
class FOODFIGHTERS_API AINTERACT_TEST_OBJECT : public AActor, public Interactable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AINTERACT_TEST_OBJECT();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction");
	virtual OnInteract_Implementation(AActor* Caller);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction");
	void StartFocus();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction");
	void EndFocus();
	
	
};
