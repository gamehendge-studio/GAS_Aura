// I MADED THIS


#include "Character/AuraEnemy.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraEnemy::AAuraEnemy()
{
    GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

    AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

    AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemy::HighlightActor()
{
    SetMeshHighlighted(GetMesh(), true);
    SetMeshHighlighted(Weapon, true);
}

void AAuraEnemy::UnHighlightActor()
{
    SetMeshHighlighted(GetMesh(), false);
    SetMeshHighlighted(Weapon, false);
}

void AAuraEnemy::BeginPlay()
{
    Super::BeginPlay();

    AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
