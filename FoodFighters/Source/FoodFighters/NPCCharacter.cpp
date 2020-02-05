// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCCharacter.h"

// Sets default values
ANPCCharacter::ANPCCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 600.0f, 0.0f);

	triggerC = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	triggerC->InitSphereRadius(96.0f);
	triggerC->SetCollisionProfileName(TEXT("trigger"));
	triggerC->SetupAttachment(RootComponent);

	triggerC->OnComponentBeginOverlap.AddDynamic(this, &ANPCCharacter::OnOverlapBegin);
	triggerC->OnComponentEndOverlap.AddDynamic(this, &ANPCCharacter::OnOverlapEnd);


	Head = CreateDefaultSubobject<UBoxComponent>(TEXT("headComponent"));
	Head->OnComponentBeginOverlap.AddDynamic(this, &ANPCCharacter::OnOverlapBegin);
	Head->OnComponentEndOverlap.AddDynamic(this, &ANPCCharacter::OnOverlapEnd);
	Head->SetCollisionProfileName(TEXT("headtrigger"));
	Head->SetupAttachment(RootComponent);

	MAXwaittime = 100;
	CURwaittime = MAXwaittime;
}

void ANPCCharacter::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
}

void ANPCCharacter::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
}

// Called when the game starts or when spawned
void ANPCCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPCCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*CURwaittime -= DeltaTime * 4;*/
}

// Called to bind functionality to input
void ANPCCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

