// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Sound/SoundCue.h"
#include "AI_Bot_Controller_M.generated.h"

/**
 * 
 */
UCLASS()
class FOODFIGHTERS_API AAI_Bot_Controller_M : public AAIController
{
	GENERATED_BODY()

public:
		AAI_Bot_Controller_M();


	virtual void BeginPlay() override;

	//runs when ai controller is in the character
	virtual void Possess(APawn* Pawn) override;

	//run every frame
	virtual void Tick(float DeltaSecounds) override;

	// will alow ai Possess componeent to always point in the direction the character is facing in 
	virtual FRotator GetControlRotation() const override;


	//void Sound();
	//void Sound2();
	//bool Damage();
	//bool Attack();



	// will dectecte if player is around 
	UFUNCTION()
		void OnPlayerDectected(TArray<AActor*> DectectedPlayer);

	// the radius of sight the ai bot can see 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float AIEyeRadius = 500.0f;

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

	// tells the distance of the player 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float DistanceFromPlayer = 0.0f;

	//// tells the max of the enemy 
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	//	float EnemyMaxHealth = 30;

	//// tells the current health of the enemy 
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
	//	float EnemyHealthCurrent;


	//UPROPERTY(BlueprintReadOnly, Category = "Audio")
	//	USoundCue* EnemyAudioCueTest;
	//UPROPERTY(BlueprintReadOnly, Category = "Audio")
	//	UAudioComponent* AudioComponent;

	//UPROPERTY(BlueprintReadOnly, Category = "Audio")
	//	USoundCue* EnemyAudioCueTest2;
	//UPROPERTY(BlueprintReadOnly, Category = "Audio")
	//	UAudioComponent* AudioComponent2;
	
	
};
