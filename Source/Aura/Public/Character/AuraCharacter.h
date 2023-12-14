// I MADED THIS

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();
	
	virtual void PossessedBy(AController* NewController);
	virtual void OnRep_PlayerState() override;
	
private:
	UPROPERTY(EditAnywhere)
	float RotationYawRate = 400.f;

	void InitAbilityActorInfo();
};
