// Copyright Pola Nowak. All Rights Reserved.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FrameMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("FrameMeshComponent");
	RootComponent = FrameMeshComponent;

	DoorMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("DoorMeshComponent");
	DoorMeshComponent->SetupAttachment(FrameMeshComponent);
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

