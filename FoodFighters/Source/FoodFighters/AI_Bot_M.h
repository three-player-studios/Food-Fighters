// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "FoodFightersCharacter.h"
#include "items.h"
#include "AI_Bot_M_Prey.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "DrawDebugHelpers.h"
#include "AI_Bot_M.generated.h"


UCLASS()
class FOODFIGHTERS_API AAI_Bot_M : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI_Bot_M();

	//defines refence of the waypoint 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AWaypoint* NextWaypoint;


	//defines refence of the waypoint 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AWaypoint_2* NextWaypoint_2;

	//defines refence of the waypoint 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AWaypoint_3* NextWaypoint_3;

	//defines refence of the waypoint 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AWaypoint_Checkout* NextWaypoint_Checkout;

	//defines refence of the waypoint 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AWaypoint_Exit* NextWaypoint_Exit;


	//defines refence of the waypoint 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool sit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool sit2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool sit3;

	// tells the max of the enemy 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float EnemyMaxHealth ;

	// tells the current health of the enemy 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AI")
		float EnemyHealthCurrent;


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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Itemtrigger)
		class UBoxComponent* Head;


	//// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		void EDeath();

	UFUNCTION()
		void ERespawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void TakeDamageNormal();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float MAXwaittime;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float CURwaittime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float payment;

};
