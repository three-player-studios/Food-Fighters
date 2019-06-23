// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FoodFightersCharacter.generated.h"



UCLASS(config=Game)
class AFoodFightersCharacter : public ACharacter
{
	GENERATED_BODY()


public:
	AFoodFightersCharacter();


	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;




	//PLayer stats and intreraction 
	//playername
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		FString Playername;

	//base stat
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float BaseHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float Baselevel ;
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
		float CURHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float CURlevel;
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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float CUREXP;

	//// Player hit box
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Itemtrigger)
		class UCapsuleComponent* triggerCapsule;



	//// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	
	UFUNCTION()
		void LevelUP();





protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

