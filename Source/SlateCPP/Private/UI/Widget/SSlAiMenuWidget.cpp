// Fill out your copyright notice in the Description page of Project Settings.

#include "SSlAiMenuWidget.h"
#include "SlateOptMacros.h"
#include "SlAiStyle.h"
#include "SlAiMenuWidgetStyle.h"
#include <SBox.h>
#include <SImage.h>
#include <STextBlock.h>
#include <SBoxPanel.h>
#include "SSlAiMenuItemWidget.h"
#include "SlAiTypes.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiMenuWidget::Construct(const FArguments& InArgs)
{
	//获取MenuStyle
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");
	//默认调用本地化文本格式为en
	//FInternationalization::Get().SetCurrentCulture(TEXT("en"));
	
	ChildSlot
	[
		SAssignNew(RootSizeBox,SBox)
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(FMargin(0.f,50.f,0.f,0.f))
			[
				SNew(SImage)
				.Image(&MenuStyle->MenuBackgroundBrush)
			]

			+SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			.Padding(FMargin(0.f,25.f,0.f,0.f))
			[
				SNew(SImage)
				.Image(&MenuStyle->LeftIconBrush)
			]

			+ SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Center)
			.Padding(FMargin(0.f, 25.f, 0.f, 0.f))
			[
				SNew(SImage)
				.Image(&MenuStyle->RightIconBrush)
			]

			+SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)
			[
				SNew(SBox)
				.WidthOverride(400.f)
				.HeightOverride(100.f)
				[
					SNew(SBorder)
					.BorderImage(&MenuStyle->TileBorderBrush)
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
					SAssignNew(TitelText,STextBlock)
					.Font(SlAiStyle::Get().GetFontStyle("MenuItemFont"))
					.Text(NSLOCTEXT("SlAiMenu","Menu","Menu"))
					]
				]
			]

			+SOverlay::Slot()
				.VAlign(VAlign_Top)
				.HAlign(HAlign_Center)
				.Padding(FMargin(0.f, 130.f, 0.f, 0.f))
				[
					SAssignNew(ContentBox,SVerticalBox)
				]
		]
	];
	RootSizeBox->SetWidthOverride(600.f);
	RootSizeBox->SetHeightOverride(510.f);
	//加载别的widget
	ContentBox->AddSlot()
		[
			SNew(SSlAiMenuItemWidget)
			.ItemText(NSLOCTEXT("SlAiMenu", "StartGame", "StartGame"))
			.ItemType(EMenuItem::StartGame)
			.OnClicked(this,&SSlAiMenuWidget::MenuItemOnClicked)
		];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSlAiMenuWidget::MenuItemOnClicked(EMenuItem::Type ItemType)
{
	TitelText->SetText(NSLOCTEXT("SlAiMenu", "StartGame", "StartGame"));
}
