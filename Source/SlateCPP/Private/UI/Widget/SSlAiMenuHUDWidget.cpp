// Fill out your copyright notice in the Description page of Project Settings.

#include "SSlAiMenuHUDWidget.h"
#include "SlateOptMacros.h"
#include <SButton.h>
#include <SImage.h>
#include "SlAiStyle.h"
#include "SlAiMenuWidgetStyle.h"
#include <SOverlay.h>
#include <SDPIScaler.h>
#include "../../../Public/GamePlay/UI/Widget/SSlAiMenuWidget.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiMenuHUDWidget::Construct(const FArguments& InArgs)
{
	//获取编辑器的MenuStyle
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");
	//绑定缩放规则方法
	UIScaler.Bind(this, &SSlAiMenuHUDWidget::GetUIScaler);

	ChildSlot
	[
		SNew(SDPIScaler)
		.DPIScale(UIScaler)
		[
		SNew(SOverlay)
		+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		//.Padding(FMargin(30.f))
		[
			SNew(SImage)
			.Image(&MenuStyle->MenuHUDBackgroundBrush)
		]

		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		//.Expose(ImageSlot)
		//.Padding(FMargin(30.f))
		[
			//SNew(SImage)
			//.Image(&MenuStyle->MenuBackgroundBrush)
			SAssignNew(MenuWidget,SSlAiMenuWidget)
		]

		//+SOverlay::Slot()
		//.HAlign(HAlign_Left)
		//.VAlign(VAlign_Top)
		//[
		//	SNew(SButton)
		//	.OnClicked(this,&SSlAiMenuHUDWidget::OnClick)
		//]
		//]
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

float SSlAiMenuHUDWidget::GetUIScaler() const
{
	return GetViewportSize().Y / 1080.f;
}

FVector2D SSlAiMenuHUDWidget::GetViewportSize() const
{
	FVector2D Result(1920, 1080);
	if (GEngine&&GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(Result);
	}
	return Result;
}

//FReply SSlAiMenuHUDWidget::OnClick()
//{
//	ImageSlot->HAlign(HAlign_Right).VAlign(VAlign_Bottom);
//	return FReply::Handled();
//}
