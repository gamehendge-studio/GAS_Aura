// I MADED THIS


#include "Character/AuraCharacterBase.h"
#include "Aura/Aura.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AAuraCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraCharacterBase::SetMeshHighlighted(USkeletalMeshComponent* MeshToHighlight, bool Highlighted)
{
	if (MeshToHighlight == nullptr)
		return;

	MeshToHighlight->SetRenderCustomDepth(Highlighted);
	MeshToHighlight->SetCustomDepthStencilValue(Highlighted ? CUSTOM_DEPTH_RED : 0);
}
