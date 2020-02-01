// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapons.generated.h"

UCLASS()
class FOODFIGHTERS_API AWeapons : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapons();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// name of the object
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemInfo)
		FString Name;

	// image of the object
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ItemInfo)
		UTexture2D* Image;

	//// Player hit box
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Itemtrigger)
		class UBoxComponent* WeaponBox;

	// make mesh component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float BaseDanamge;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float StatBooost1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float StatBooost2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float StatBooost3;;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float StatBooost4;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float StatBooost5;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float StatBooost6;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float EffectDanamge;
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		bool attacktrue = false;

	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void Attack();
};
