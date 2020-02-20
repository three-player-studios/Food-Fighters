// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPCCharacter.h"
#include "AI_Bot_M.h"
#include "Waypoint.h"
#include "Waypoint_Exit.h"
#include "Waypoint_Checkout.h"
#include "Waypoint_3.h"
#include "Waypoint_2.h"
#include "Food.h"
#include "AI_Bot_Controller_2.generated.h"

/**
 * 
 */
UCLASS()
class FOODFIGHTERS_API AAI_Bot_Controller_2 : public AAIController
{
	GENERATED_BODY()
	
public:
	AAI_Bot_Controller_2();

	virtual void BeginPlay() override;

	//runs when ai controller is in the character
	virtual void Possess(APawn* Pawn) override;

	//run every frame
	virtual void Tick(float DeltaSecounds) override;

	// will alow ai Possess componeent to always point in the direction the character is facing in 
	virtual FRotator GetControlRotation() const override;

	UFUNCTION()
		void OnPawnDetected(TArray<AActor*> DectectedPlayer);


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

	// will dectecte if player is around or not 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		bool IsThePlayerDetected = false;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float DistanceToPlayer = 0.0f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		AWaypoint* chair_1;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		AWaypoint_2* chair_2;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		AWaypoint_3* chair_3;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		AWaypoint_Checkout* checkout;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		AWaypoint_Exit* exit;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		AAI_Bot_M* AiCharacter ;

	//// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	
};
