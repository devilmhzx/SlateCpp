// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <ISlateStyle.h>

/**
 * 
 */
class SLATECPP_API SlAiStyle
{
public:
	static void Initialize();

	static FName GetStyleSetName();

	static void shutdown();

	static const ISlateStyle& Get();

private:
	static TSharedRef<class FSlateStyleSet> Create();

	static TSharedPtr<FSlateStyleSet> SlAiStyleInstance;
};


