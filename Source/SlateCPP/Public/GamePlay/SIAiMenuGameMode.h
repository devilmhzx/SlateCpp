// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SIAiMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SLATECPP_API ASIAiMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASIAiMenuGameMode();

	virtual void BeginPlay() override;
};
