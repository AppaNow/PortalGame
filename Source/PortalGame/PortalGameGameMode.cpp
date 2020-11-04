// Copyright Epic Games, Inc. All Rights Reserved.

#include "PortalGameGameMode.h"
#include "PortalGameHUD.h"
#include "PortalGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

APortalGameGameMode::APortalGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = APortalGameHUD::StaticClass();
}
