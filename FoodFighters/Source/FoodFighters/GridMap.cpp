// Fill out your copyright notice in the Description page of Project Settings.

#include "GridMap.h"
#include "DrawDebugHelpers.h"


// Sets default values
AGridMap::AGridMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	//set the root Component to root
	SetRootComponent(Scene);

	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));



}

// Called when the game starts or when spawned
void AGridMap::BeginPlay()
{
	Super::BeginPlay();
	// set location for grid map  
	GridLoc =	Scene->GetComponentLocation();
	
	//draws debug box to show size of grid map 
	DrawDebugBox(GetWorld(), GridLoc, FVector(GridSizeWorld.X, GridSizeWorld.Y, 5), FColor::Purple, true, 999, 0, 10);


	//return butoomleft conner of grid map 
	Gridbuttomleft();
	
	

	
}

// Called every frame
void AGridMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AGridMap::Gridtop()
{
}

void AGridMap::Gridbuttom()
{

}


//rerturns the buttom left corner of map
void AGridMap::Gridbuttomleft()
{
//gets the right side vule
	FVector rightx = Scene->GetRightVector() * GridSizeWorld.X;

//total size of right 
FVector totalright =  GridLoc - rightx ;

//gets the right side value
FVector forwardY = Scene->GetForwardVector() * GridSizeWorld.Y;

//use this 
FVector buttomlefttotal = rightx - forwardY;


//draws debug box to show size of grid map on buttm left
DrawDebugBox(GetWorld(), buttomlefttotal, FVector(20, 20, 5), FColor::Red, true, 999, 0, 10);

}

void AGridMap::Gridright()
{
}

void AGridMap::GridNumSize()
{

	//tile amount Xand Y
	float tilex = GridSizeWorld.X / TileSizeNumber;
	float tileY = GridSizeWorld.Y / TileSizeNumber;

	float x;
	float y;
	
	for (float i = 0; i < tileX; i++)
	{
		x = i;
	}
	
	for (float o = 0; o < tileY; o++)
	{
		 y = o;
	}
	

	//gets the right side vule
	FVector rightx = Scene->GetRightVector() * (x * TileSizeNumber);

	Gridbuttomleft() + rightx;


	//draws debug box to show size of grid map on buttm left
	DrawDebugBox(GetWorld(), buttomlefttotal, FVector(20, 20, 5), FColor::Red, true, 999, 0, 10);



}





