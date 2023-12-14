// I MADED THIS


#include "Actor/AuraEffectActor.h"
#include "Components/SphereComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraEffectActor::AAuraEffectActor()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();	

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectActor::OnBeginOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectActor::OnEndOverlap);
}

void AAuraEffectActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: apply gameplay effect! const_cast is a hack!
	IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor);
	if (ASCInterface == nullptr)
		return;

	const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(
		ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass())
	);

	UAuraAttributeSet* MuteableAuraAttributeSet = const_cast<UAuraAttributeSet*>(AuraAttributeSet);
	MuteableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.f);
}

void AAuraEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}