// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "NPCCharacter.generated.h"

UCLASS()
class FOODFIGHTERS_API ANPCCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPCCharacter();

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
		bool sittingdown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool sittingdown2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool sittingdown3;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);



	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float MAXwaittime;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float CURwaittime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float payment;

	
};
