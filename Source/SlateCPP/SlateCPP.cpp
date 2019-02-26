// Fill out your copyright notice in the Description page of Project Settings.

#include "SlateCPP.h"
#include "Modules/ModuleManager.h"
#include "SlAiStyle.h"
#include <SlateStyleRegistry.h>

//IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, SlateCPP, "SlateCPP" );

void FSlateCppModule::StartupModule()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(SlAiStyle::GetStyleSetName());
	SlAiStyle::Initialize();
}

void FSlateCppModule::ShutdownModule()
{
	SlAiStyle::shutdown();
}


IMPLEMENT_PRIMARY_GAME_MODULE(FSlateCppModule, SlateCPP, "SlateCPP");