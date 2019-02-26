// Fill out your copyright notice in the Description page of Project Settings.

#include "SlAiStyle.h"
#include <SlateStyleRegistry.h>
#include <SlateGameResources.h>


TSharedPtr<FSlateStyleSet> SlAiStyle::SlAiStyleInstance = nullptr;

void SlAiStyle::Initialize()
{
	if (!SlAiStyleInstance.IsValid())
	{
		SlAiStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*SlAiStyleInstance);
	}
}

FName SlAiStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("SlAiStyle"));
	return StyleSetName;
}

void SlAiStyle::shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*SlAiStyleInstance);
	ensure(SlAiStyleInstance.IsUnique());
	SlAiStyleInstance.Reset();
}

const ISlateStyle & SlAiStyle::Get()
{
	// TODO: 在此处插入 return 语句

	return *SlAiStyleInstance;
}

TSharedRef<class FSlateStyleSet> SlAiStyle::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(SlAiStyle::GetStyleSetName(), "/Game/UI/Style", "/Game/UI/Style");
	StyleRef->Set("MenuItemFont", FSlateFontInfo("Roboto-Regular.ttf", 50));
	return StyleRef;
}
