// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "FoodFightersCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "items.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "GameFramework/SpringArmComponent.h"

//////////////////////////////////////////////////////////////////////////
// AFoodFightersCharacter

AFoodFightersCharacter::AFoodFightersCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)


	/////stuff arifa added
	triggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootComponent"));
	triggerCapsule->InitCapsuleSize(92.f, 96.0f);
	triggerCapsule->SetCollisionProfileName(TEXT("trigger"));
	triggerCapsule->SetupAttachment(RootComponent);



	triggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &AFoodFightersCharacter::OnOverlapBegin);
	triggerCapsule->OnComponentEndOverlap.AddDynamic(this, &AFoodFightersCharacter::OnOverlapEnd);



	Baselevel = 0;
	BaseHealth = 100;
	BaseDEF = 10;
	BaseDEX = 10;
	BaseLUCK = 10;
	BaseEXP = 0;
	BaseSPD = 500;
	BaseSTR = 10;
	BaseVIT = 10;
	BaseLevelupCheckpoint = 100;

	CURlevel = Baselevel;
	CURHealth = BaseHealth;
	CURDEF = BaseDEF;
	CURDEX = BaseDEX;
	CURLUCK = BaseLUCK;
	CUREXP = BaseEXP;
	CURSPD = BaseSPD;
	CURSTR = BaseSTR;
	CURVIT = BaseVIT;
	CURLevelupCheckpoint = BaseLevelupCheckpoint;

}

//////////////////////////////////////////////////////////////////////////
// Input

void AFoodFightersCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AFoodFightersCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFoodFightersCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AFoodFightersCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AFoodFightersCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AFoodFightersCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AFoodFightersCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AFoodFightersCharacter::OnResetVR);
}




///arifa added this hit box collision
void AFoodFightersCharacter::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		/*if (GEngine) 
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("overlap begin"));
		}*/
		if (&AAI_Bot_M::triggerC && !&AAI_Bot_M::GetMesh) {
			CURHealth -= 2;
		}


		if(&AAI_Bot_M::Head && !&AAI_Bot_M::GetMesh) {
			CURHealth -= 2;
		}
	}
}
///arifa added this hit box collision
void AFoodFightersCharacter::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("overlap end"));
		}
	}

}

//level function for player
void AFoodFightersCharacter::LevelUP()
{
	// player exp reaches a certain point then player levels up
	if (CUREXP >= CURLevelupCheckpoint) 
	{
	
		CURlevel = Baselevel + 1;
		CURHealth = BaseHealth ;
		CURDEF = BaseDEF + FMath::FRandRange(1,10);
		CURDEX = BaseDEX + FMath::FRandRange(1, 10);
		CURLUCK = BaseLUCK + FMath::FRandRange(1, 10);
		CUREXP = CUREXP - CURLevelupCheckpoint;
		CURSPD = BaseSPD + FMath::FRandRange(1, 10);
		CURSTR = BaseSTR + FMath::FRandRange(1, 10);
		CURVIT = BaseVIT + FMath::FRandRange(1, 10);;
	
		CURLevelupCheckpoint += BaseLevelupCheckpoint; // adds 100 to each level up
	}

}





void AFoodFightersCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AFoodFightersCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void AFoodFightersCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void AFoodFightersCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AFoodFightersCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AFoodFightersCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AFoodFightersCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
