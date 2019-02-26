// Fill out your copyright notice in the Description page of Project Settings.

#include "SlAiMenurController.h"

ASlAiMenurController::ASlAiMenurController()
{
	bShowMouseCursor = true;
}

void ASlAiMenurController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeUIOnly InputMode;
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	SetInputMode(InputMode);
}
