// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FoodFighters/items.h"
#include "FoodFighters/Food.h"
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




	// player stats and intreraction 
	// player name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
		FString PlayerName;
	// player image
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Info)
		UTexture2D* PlayerImage;
	// player inventory
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory)
		TArray<Aitems*> Inventory;
	// player inventory limit
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory)
		int InventoryMaxSize;
	// player inventory amount
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory)
		int InventoryCurrentSize;
	// player held food
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Food)
		AFood* HeldFood;

	//base stat
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float BaseHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float BaseStamina;
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
	UPROPERTY(VisibleAnywhere, BLueprintReadOnly, Category = Stat) // the goal post of exp needed to level up between levels
		float BaseLevelupCheckpoint;
	//Currnet stat
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float CURHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float CURStamina;
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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat) // current level up checkpoint 
		float CURLevelupCheckpoint;
	
	
	//// Player hit box
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Itemtrigger)
		class UCapsuleComponent* triggerCapsule;


	// make mesh component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* BODYMesh;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat)
		float CRITCHANCE;

	//// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	


	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);





	
	UFUNCTION()
		void LevelUP();

// CURRENT STAT GETTERS 
	UFUNCTION(BlueprintPure, Category = "Character Level") // cur lvl get
		float getCurrentLevel() const { return CURlevel; }
		 
	UFUNCTION(BlueprintPure, Category = "Character Health") // cur health get 
		float getCurrentHealth() const { return CURHealth; }

	UFUNCTION(BlueprintPure, Category = "Character Stamina") // cur stamina get 
		float getCurrentStamina() const { return CURStamina; }

	UFUNCTION(BlueprintPure, Category = "Character Defense") // cur def get 
		float getCurrentDefence() const { return CURDEF; }

	UFUNCTION(BlueprintPure, Category = "Character Dexterity") // cur dex get 
		float getCurrentDexterity() const { return CURDEX; }

	UFUNCTION(BlueprintPure, Category = "Character Luck") // cur luck get
		float getCurrentLuck() const { return CURLUCK; }
	
	UFUNCTION(BlueprintPure, Category = "Character Exp") // cur exp get
		float getCurrentEXP() const { return CUREXP; }

	UFUNCTION(BlueprintPure, Category = "Character Speed") // cur SPD get 
		float getCurrentSpeed() const { return CURSPD; }

	UFUNCTION(BlueprintPure, Category = "Character Strength") // cur STR get
		float getCurrentStrenght() const { return CURSTR; }

	UFUNCTION(BlueprintPure, Category = "Character Vitality") // cur VIT get 
		float getCurrentVitality() const { return CURVIT; }
// CURRENT STAT GETTERS//

// BASE STAT GETTERS 
	UFUNCTION(BlueprintPure, Category = "Character Level") // base lvl get
		float getBaseLevel() const { return Baselevel; }

	UFUNCTION(BlueprintPure, Category = "Character Health") // base health get 
		float getBaseHealth() const { return BaseHealth; }

	UFUNCTION(BlueprintPure, Category = "Character Stamina") // base stamina get 
		float getBaseStamina() const { return BaseStamina; }

	UFUNCTION(BlueprintPure, Category = "Character Defense") // Base def get 
		float getBasetDefence() const { return BaseDEF; }

	UFUNCTION(BlueprintPure, Category = "Character Dexterity") // Base dex get 
		float getBaseDexterity() const { return BaseDEX; }

	UFUNCTION(BlueprintPure, Category = "Character Luck") // Base luck get
		float getBaseLuck() const { return BaseLUCK; }

	UFUNCTION(BlueprintPure, Category = "Character Exp") // Base exp get
		float getBaseEXP() const { return BaseEXP; }

	UFUNCTION(BlueprintPure, Category = "Character Speed") // Base SPD get 
		float getBaseSpeed() const { return BaseSPD; }

	UFUNCTION(BlueprintPure, Category = "Character Strength") // Base STR get
		float getBaseStrenght() const { return BaseSTR; }

	UFUNCTION(BlueprintPure, Category = "Character Vitality") // Base VIT get 
		float getBaseVitality() const { return BaseVIT; }
// BASE STAT GETTERS//

// CURRENT STAT SETTERS 
	UFUNCTION(BlueprintCallable, Category = "Character Level")
		void setCurrentLevel(float newLevel) { CURlevel = newLevel; }

	UFUNCTION(BlueprintCallable, Category = "Character Health")
		void setCurrentHealth(float newHealth) { CURHealth = newHealth; }

	UFUNCTION(BlueprintCallable, Category = "Character Stamina")
		void setCurrentStamina(float newStamina) { CURStamina = newStamina; }

	UFUNCTION(BlueprintCallable, Category = "Character Defense")
		void setCurrentDefense(float newDefense) { CURDEF = newDefense; }

	UFUNCTION(BlueprintCallable, Category = "Character Dexterity")
		void setCurrentDexterity(float newDexterity) { CURDEX = newDexterity; }

	UFUNCTION(BlueprintCallable, Category = "Character Luck")
		void setCurrentLuck(float newLuck) { CURLUCK = newLuck; }

	UFUNCTION(BlueprintCallable, Category = "Character EXP")
		void setCurrentEXP(float newEXP) { CUREXP = newEXP; }

	UFUNCTION(BlueprintCallable, Category = "Character Speed") 
		void setCurrentSpeed(float newSpeed) { CURSPD = newSpeed; }

	UFUNCTION(BlueprintCallable, Category = "Character Strength")
		void setCurrentStrength(float newStrength) { CURSTR = newStrength; }

	UFUNCTION(BlueprintCallable, Category = "Character Vitaity")
		void setCurrentVitality(float newVitality) { CURVIT = newVitality; }
// CURRENT STAT SETTERS//

// BASE STAT SETTERS
	UFUNCTION(BlueprintCallable, Category = "Character Level")
		void setBaseLevel(float newLevel) { Baselevel = newLevel; }

	UFUNCTION(BlueprintCallable, Category = "Character Health")
		void setBaseHealth(float newHealth) { BaseHealth = newHealth; }

	UFUNCTION(BlueprintCallable, Category = "Character Stamina")
		void setBaseStamina(float newStamina) { BaseStamina = newStamina; }

	UFUNCTION(BlueprintCallable, Category = "Character Defense")
		void setBaseDefese(float newDefense) { BaseDEF = newDefense; }

	UFUNCTION(BlueprintCallable, Category = "Character Dexterity")
		void setBaseDexterity(float newDexterity) { BaseDEX = newDexterity; }

	UFUNCTION(BlueprintCallable, Category = "Character Luck")
		void setBaseLuck(float newLuck) { BaseLUCK = newLuck; }

	UFUNCTION(BlueprintCallable, Category = "Character EXP")
		void setBaseEXP(float newEXP) { BaseEXP = newEXP; }

	UFUNCTION(BlueprintCallable, Category = "Character Speed")
		void setBaseSpeed(float newSpeed) { BaseSPD = newSpeed; }

	UFUNCTION(BlueprintCallable, Category = "Character Stength")
		void setBaseStrength(float newStrength) { BaseSTR = newStrength; }

	UFUNCTION(BlueprintCallable, Category = "Character Vitality")
		void setBaseVitality(float newVitaltiy) { BaseVIT = newVitaltiy; }

	

// BASE STAT SETTERS//
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
	/** Inventory Functions **/
	UFUNCTION()
		void AddToInventory(Aitems* Item);
	UFUNCTION(BlueprintCallable)
		TArray<Aitems*> GetInventory();
};

