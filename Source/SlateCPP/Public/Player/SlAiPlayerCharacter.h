// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "SlAiPlayerCharacter.generated.h"

UCLASS()
class SLATECPP_API ASlAiPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASlAiPlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		class USpringArmComponent* CameraBoom;


	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		class UCameraComponent* ThirdCamera;

	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		UCameraComponent* FirstCamera;

private:
	//第一人称的骨骼模型
	UPROPERTY(VisibleAnywhere, Category = "SlAi")
		USkeletalMeshComponent* MeshFirst;

};
