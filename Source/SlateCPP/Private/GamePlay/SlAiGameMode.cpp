// Fill out your copyright notice in the Description page of Project Settings.

#include "SlAiGameMode.h"
#include "SlAiGameHUD.h"
#include "SlAiPlayerController.h"
#include "SlAiPlayerCharacter.h"
#include "SlAiPlayerState.h"


ASlAiGameMode::ASlAiGameMode()
{
	//允许开启Tick函数
	PrimaryActorTick.bCanEverTick = true;
	//添加组件
	HUDClass = ASlAiGameHUD::StaticClass();
	PlayerControllerClass = ASlAiPlayerController::StaticClass();
	PlayerStateClass = ASlAiPlayerState::StaticClass();
	DefaultPawnClass = ASlAiPlayerCharacter::StaticClass();


}

void ASlAiGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ASlAiGameMode::BeginPlay()
{
	Super::BeginPlay();


}
