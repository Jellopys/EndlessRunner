// Richard Hill


#include "HealthComponent.h"
#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	
	World = GetWorld();
	GameMode = Cast<AEndlessGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	HandleImmunityTimer(DeltaTime);
}

void UHealthComponent::HandleImmunityTimer(float DeltaTime)
{
	if (!HasTempImmunity) return;
	
	if (TimeElapsed < ImmunityTime)
	{
		TimeElapsed += DeltaTime;
	}
	else
	{
		HasTempImmunity = false;
		UE_LOG(LogTemp, Warning, TEXT("Immunity Time over"));
	}
}

void UHealthComponent::UpdateHealth()
{
	if (HasTempImmunity) return;
	
	CurrentHealth -= 1;

	if(CurrentHealth == 0)
	{
		OnDeath();
	}
	else
	{
		OnHit();
	}
	
	if (!HasTempImmunity)
	{
		HasTempImmunity = true;
		TimeElapsed = 0;
	}
}

void UHealthComponent::OnHit()
{
	UE_LOG(LogTemp, Warning, TEXT("Hit"));
}

void UHealthComponent::OnDeath()
{
	GameMode->ResetGame();
}



