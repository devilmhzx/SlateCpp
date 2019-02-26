// Fill out your copyright notice in the Description page of Project Settings.

#include "SSlAiMenuHUDWidget.h"
#include "SlateOptMacros.h"
#include <SButton.h>
#include <SImage.h>
#include "SlAiStyle.h"
#include "SlAiMenuWidgetStyle.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiMenuHUDWidget::Construct(const FArguments& InArgs)
{
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");
	ChildSlot
	[
		// Populate the widget
		SNew(SImage)
		.Image(&MenuStyle->MenuHUDBackgroundBrush)
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
