// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI_Bot_M_Prey.generated.h"

UCLASS()
class FOODFIGHTERS_API AAI_Bot_M_Prey : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI_Bot_M_Prey();

	//defines refence of the waypoint 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AWaypoint* NextWaypoint;

	// tells the max of the enemy 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
		float PEnemyMaxHealth = 30;

	// tells the current health of the enemy 
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
		float PEnemyHealthCurrent;


	//playername
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		FString EnemyName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float Baselevel;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float BaseSTR;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float BaseDEF;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float BaseSPD;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float BaseVIT;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float BaseDEX;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float BaseLUCK;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float BaseEXP;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float randlevl;


	//Currnet stat
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float CURSTR;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float CURDEF;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float CURSPD;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float CURVIT;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float CURDEX;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float CURLUCK;




	//// Player hit box
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Itemtrigger)
		class USphereComponent* triggerC;



	//// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
