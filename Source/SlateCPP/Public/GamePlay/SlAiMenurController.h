// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SlAiMenurController.generated.h"

/**
 *
 */
UCLASS()
class SLATECPP_API ASlAiMenurController : public APlayerController
{
	GENERATED_BODY()

public:
	ASlAiMenurController();

protected:
	virtual void BeginPlay() override;
};
