// Fill out your copyright notice in the Description page of Project Settings.

#include "SIAiMenuGameMode.h"
#include "SlAiMenurController.h"
#include "SlAiMenuHUD.h"

ASIAiMenuGameMode::ASIAiMenuGameMode()
{
	PlayerControllerClass = ASlAiMenurController::StaticClass();
	HUDClass = ASlAiMenuHUD::StaticClass();
}


void ASIAiMenuGameMode::BeginPlay()
{
	Super::BeginPlay();
}
