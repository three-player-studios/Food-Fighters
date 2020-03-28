// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/BillboardComponent.h"
#include "GridMap.generated.h"


UCLASS()
class FOODFIGHTERS_API AGridMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridMap();


	// the radius of sight the ai bot can see 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
		FVector GridLoc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
		FVector2D GridSizeWorld;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
		float TileSizeNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
		float  tileX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
		float tileY;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Grid")
		USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Grid")
		UBillboardComponent* Billboard;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Grid")
		FBox debugbox;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	UFUNCTION(BlueprintCallable, BlueprintCallable, Category = "Grid")
	void Gridtop();

	UFUNCTION(BlueprintCallable, BlueprintCallable, Category = "Grid")
	void Gridbuttom();
	
	UFUNCTION(BlueprintCallable, BlueprintCallable, Category = "Grid")
	void Gridbuttomleft();
	
	UFUNCTION(BlueprintCallable, BlueprintCallable, Category = "Grid")
	void Gridright();

	UFUNCTION(BlueprintCallable, BlueprintCallable, Category = "Grid")
		void GridNumSize();


};
