// Richard Hill


#include "PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "CustomComponents/PlayerMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;
	Capsule->SetCollisionProfileName("BlockAllDynamic");

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Character Mesh"));
	Mesh->SetupAttachment(Capsule);
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	MovementComponent = CreateDefaultSubobject<UPlayerMovementComponent>(TEXT("Movement Component"));
	MovementComponent->SetUpdatedComponent(Capsule);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
	GameMode = Cast<AEndlessGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &APlayerCharacter::GetP2MovComp,
		1, false, 0.2f);
	
	// GetP2MovComp();
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent)

	PlayerInputComponent->BindAction("MoveUpP1", IE_Pressed, this, &APlayerCharacter::MoveUp);
	PlayerInputComponent->BindAction("MoveDownP1", IE_Pressed, this, &APlayerCharacter::MoveDown);
	PlayerInputComponent->BindAction("MoveRightP1", IE_Pressed, this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAction("MoveLeftP1", IE_Pressed, this, &APlayerCharacter::MoveLeft);
	
	PlayerInputComponent->BindAction("MoveUpP2", IE_Pressed, this, &APlayerCharacter::MoveUp2);
	PlayerInputComponent->BindAction("MoveDownP2", IE_Pressed, this, &APlayerCharacter::MoveDown2);
	PlayerInputComponent->BindAction("MoveRightP2", IE_Pressed, this, &APlayerCharacter::MoveRight2);
	PlayerInputComponent->BindAction("MoveLeftP2", IE_Pressed, this, &APlayerCharacter::MoveLeft2);
}

void APlayerCharacter::UpdateHealth(int IncomingHealth)
{
	
}

UPlayerMovementComponent* APlayerCharacter::GetP2MovementComponent()
{
	return MovementComponent;
}

void APlayerCharacter::MoveUp()
{
	MovementComponent->MoveUp();
}

void APlayerCharacter::MoveDown()
{
	MovementComponent->MoveDown();
}

void APlayerCharacter::MoveRight()
{
	MovementComponent->MoveRight();
}

void APlayerCharacter::MoveLeft()
{
	MovementComponent->MoveLeft();
}

void APlayerCharacter::GetP2MovComp()
{
	P2MovementComp = GameMode->GetP2MovementComp();
}

void APlayerCharacter::MoveUp2()
{
	if (P2MovementComp != nullptr)
		P2MovementComp->MoveUp();
}

void APlayerCharacter::MoveDown2()
{
	if (P2MovementComp != nullptr)
		P2MovementComp->MoveDown();
}

void APlayerCharacter::MoveRight2()
{
	if (P2MovementComp != nullptr)
		P2MovementComp->MoveRight();
}

void APlayerCharacter::MoveLeft2()
{
	if (P2MovementComp != nullptr)
		P2MovementComp->MoveLeft();
}



