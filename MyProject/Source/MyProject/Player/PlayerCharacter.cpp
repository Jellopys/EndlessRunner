// Richard Hill


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "CustomComponents/PlayerMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;
	Capsule->SetCollisionProfileName("BlockAllDynamic");

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Character Mesh"));
	Mesh->SetupAttachment(Capsule);
	// Mesh->bCastDynamicShadow = true;
	// Mesh->CastShadow = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	MovementComponent = CreateDefaultSubobject<UPlayerMovementComponent>(TEXT("Movement Component"));
	MovementComponent->SetUpdatedComponent(Capsule);

	// HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
	// HealthComponent->OnTakeDamage.AddDynamic(this, &APlayerCharacter::OnDamageTaken);
	
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent)
	PlayerInputComponent->BindAction("MoveUp", IE_Pressed, this, &APlayerCharacter::MoveUp);
	PlayerInputComponent->BindAction("MoveDown", IE_Pressed, this, &APlayerCharacter::MoveDown);
	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &APlayerCharacter::MoveLeft);
	PlayerInputComponent->BindAction("Space", IE_Pressed, this, &APlayerCharacter::Space);
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

void APlayerCharacter::Space()
{
	UE_LOG(LogTemp,Warning, TEXT("SPACING"));
	// TODO: Shoot or whatever
}

