// Copyright Pola Nowak. All Rights Reserved.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> FrameAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_DoorFrame.SM_DoorFrame'"));
	FrameMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("FrameMeshComponent");
	FrameMeshComponent->SetStaticMesh(FrameAsset.Object);
	RootComponent = FrameMeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> DoorAsset(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Door.SM_Door'"));
	DoorMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("DoorMeshComponent");
	DoorMeshComponent->SetupAttachment(FrameMeshComponent);
	DoorMeshComponent->SetStaticMesh(DoorAsset.Object);
	DoorMeshComponent->SetRelativeLocation(FVector(0.0f, 45.0f, 0.0f));
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

