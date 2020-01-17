// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPCCharacter.h"
#include "NPC_AIController.generated.h"

/**
 * 
 */
UCLASS()
class FOODFIGHTERS_API ANPC_AIController : public AAIController
{
	GENERATED_BODY()
public:

		ANPC_AIController();
	
	virtual void BeginPlay() override;

	//runs when ai controller is in the character
	virtual void Possess(APawn* Pawn) override;

	//run every frame
	virtual void Tick(float DeltaSecounds) override;

	// will alow ai Possess componeent to always point in the direction the character is facing in 
	virtual FRotator GetControlRotation() const override;

	// will dectecte if player is around 
	UFUNCTION()
		void OnFoodDectected(TArray<AActor*> DectectedPlayer);

	// the radius of sight the ai bot can see 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float AIEyeRadius = 3500.0f;

	// how long the ai will remeber the player 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float AIEyeMemroy = 5.0f;

	// the radius of sight the ai bot can not see 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float AILostEyeRaduis = AIEyeRadius + 50.0f;

	// angle of sight 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float AIEyeAngle = 90.0f;

	// class that configres ai bot sight 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		class UAISenseConfig_Sight* SightConfig;

	// will dectecte if food is around or not 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		bool IsTheFoodDetected = false;



	// tells the distance of the player 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float DistanceFromFood = 0.0f;




};
