// Richard Hill

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyProject/GameMode/EndlessGameMode.h"
#include "HealthComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MYPROJECT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UHealthComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY()
	AEndlessGameMode* GameMode;
	UPROPERTY()
	UWorld* World;
	UPROPERTY()
	bool HasTempImmunity;
	UPROPERTY()
	float TimeElapsed;
	UPROPERTY()
	float ImmunityTime = 3;

	// Functions
	UFUNCTION()
	void HandleImmunityTimer(float DeltaTime);
	UFUNCTION(BlueprintCallable)
	void UpdateHealth();
};
