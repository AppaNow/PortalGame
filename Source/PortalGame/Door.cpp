// Copyright Pola Nowak. All Rights Reserved.

#include "Door.h"
#include "Components/BoxComponent.h"


// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> FrameAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_DoorFrame.SM_DoorFrame'"));
	FrameMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrameMeshComponent"));
	FrameMeshComponent->SetStaticMesh(FrameAsset.Object);
	RootComponent = FrameMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> DoorAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Door.SM_Door'"));
	DoorMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMeshComponent"));
	DoorMeshComponent->SetupAttachment(FrameMeshComponent);
	DoorMeshComponent->SetStaticMesh(DoorAsset.Object);
	DoorMeshComponent->SetRelativeLocation(FVector(0.0f, 45.0f, 0.0f));

	OpenBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("OpenBoxComponent"));
	OpenBoxComponent->SetupAttachment(FrameMeshComponent);
	OpenBoxComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
	OpenBoxComponent->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	OpenBoxComponent->BodyInstance.SetCollisionProfileName(TEXT("PawnTrigger"));

	OpenBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ADoor::OnBoxBeginOverlap);
	OpenBoxComponent->OnComponentEndOverlap.AddDynamic(this, &ADoor::OnBoxEndOverlap);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoor::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Open();
}

void ADoor::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Close();
}

void ADoor::Open()
{
	DoorMeshComponent->SetRelativeLocation(FVector(0.0f, 145.0f, 0.0f));
}

void ADoor::Close()
{
	DoorMeshComponent->SetRelativeLocation(FVector(0.0f, 45.0f, 0.0f));
}
