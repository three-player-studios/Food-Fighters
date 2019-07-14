// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Armor.generated.h"

UCLASS()
class FOODFIGHTERS_API AArmor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArmor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	//// Player hit box

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Itemtrigger)
		class UBoxComponent* ArmorBox;

	// make mesh component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* ArmorMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float BaseDEF;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float StatBooost1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float StatBooost2;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float StatBooost3;;




	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
	
};
