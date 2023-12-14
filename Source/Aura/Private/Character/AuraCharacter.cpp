// I MADED THIS


#include "Character/AuraCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"
#include "AbilitySystemComponent.h"

AAuraCharacter::AAuraCharacter()
{
    UCharacterMovementComponent* movement = GetCharacterMovement();
    movement->bOrientRotationToMovement = true;
    movement->RotationRate = FRotator(0.f, RotationYawRate, 0.f);
    movement->bConstrainToPlane = true;
    movement->bSnapToPlaneAtStart = true;

    bUseControllerRotationPitch = false;
    bUseControllerRotationRoll = false;
    bUseControllerRotationYaw = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);
    InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();
    InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
    AAuraPlayerState* AuraPlayerState = GetPlayerStateChecked<AAuraPlayerState>();

    AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
    AttributeSet = AuraPlayerState->GetAttributeSet();

    AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState, this);
}
