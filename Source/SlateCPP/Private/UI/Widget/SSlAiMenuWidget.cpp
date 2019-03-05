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
#include "Common/SlAiHelper.h"
#include "SSlAiGameOptionWidget.h"
#include "SlAiDataHandle.h"
#include "SSlAiNewGameWidget.h"
#include "SSlAiChooseRecordWidget.h"

struct MenuGroup
{
	//�˵�����
	FText MenuName;
	//�˵��߶�
	float MenuHeight;
	//�������
	TArray<TSharedPtr<SCompoundWidget>> ChildWidget;
	//���캯��
	MenuGroup(const FText Name, const float Height, TArray<TSharedPtr<SCompoundWidget>>* Children)
	{
		MenuName = Name;
		MenuHeight = Height;
		for (TArray<TSharedPtr<SCompoundWidget>>::TIterator It(*Children); It; ++It)
		{
			ChildWidget.Add(*It);
		}
	}
};


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiMenuWidget::Construct(const FArguments& InArgs)
{
	//��ȡMenuStyle
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");
	//Ĭ�ϵ��ñ��ػ��ı���ʽΪen
	//FInternationalization::Get().SetCurrentCulture(TEXT("en"));

	ChildSlot
		[
			SAssignNew(RootSizeBox, SBox)
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(FMargin(0.f, 50.f, 0.f, 0.f))
		[
			SNew(SImage)
			.Image(&MenuStyle->MenuBackgroundBrush)
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.Padding(FMargin(0.f, 25.f, 0.f, 0.f))
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

	+ SOverlay::Slot()
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
			SAssignNew(TitleText, STextBlock)
			.Font(SlAiStyle::Get().GetFontStyle("MenuItemFont"))
		.Text(NSLOCTEXT("SlAiMenu", "Menu", "Menu"))
		]
		]
		]

	+ SOverlay::Slot()
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Center)
		.Padding(FMargin(0.f, 130.f, 0.f, 0.f))
		[
			SAssignNew(ContentBox, SVerticalBox)
		]
			]
		];

	//���ر��widget
	//ContentBox->AddSlot()
		//[
			//SNew(SSlAiMenuItemWidget)
			//.ItemText(NSLOCTEXT("SlAiMenu", "StartGame", "StartGame"))
			//.ItemType(EMenuItem::StartGame)
			//.OnClicked(this,&SSlAiMenuWidget::MenuItemOnClicked)
			//--------------------------------------
			//SNew(SSlAiGameOptionWidget)
			//��ί��
			//.ChangeCulture(this, &SSlAiMenuWidget::ChangeCulture)
			//.ChangeVolume(this, &SSlAiMenuWidget::ChangeVolume)
			//--------------------------------------
			//SNew(SSlAiChooseRecordWidget)
		//];

	InitalizedMenuList();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSlAiMenuWidget::MenuItemOnClicked(EMenuItem::Type ItemType)
{
	//TitelText->SetText(NSLOCTEXT("SlAiMenu", "StartGame", "StartGame"));
	//SlAiHelper::Debug(TEXT("HHHHH"));
}

void SSlAiMenuWidget::ChangeCulture(ECultureTeam Culture)
{
	SlAiDataHandle::Get()->ChangeLocalizationCulture(Culture);
}

void SSlAiMenuWidget::ChangeVolume(const float MusciVolume, const float SoundVolume)
{
	SlAiDataHandle::Get()->ResetMenuVolume(MusciVolume, SoundVolume);
}

void SSlAiMenuWidget::InitalizedMenuList()
{
	//ʵ����������
	TArray<TSharedPtr<SCompoundWidget>> MainMenuList;
	//��ʼ��Ϸ
	MainMenuList.Add(
		SNew(SSlAiMenuItemWidget)
		.ItemText(NSLOCTEXT("SlAiMenu", "StartGame", "StartGame"))
		.ItemType(EMenuItem::StartGame)
		.OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked)
	);
	//��Ϸ����
	MainMenuList.Add(
		SNew(SSlAiMenuItemWidget)
		.ItemText(NSLOCTEXT("SlAiMenu", "GameOption", "GameOption"))
		.ItemType(EMenuItem::GameOption)
		.OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked)
	);
	//�˳���Ϸ
	MainMenuList.Add(
		SNew(SSlAiMenuItemWidget)
		.ItemText(NSLOCTEXT("SlAiMenu", "QuitGame", "QuitGame"))
		.ItemType(EMenuItem::QuitGame)
		.OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked)
	);

	MenuMap.Add(EMenuType::MainMenu, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "Menu", "Menu"), 510.f, &MainMenuList)));

	//��ʼ��Ϸ����
	TArray<TSharedPtr<SCompoundWidget>> StartGameList;
	//����Ϸ
	StartGameList.Add(
		SNew(SSlAiMenuItemWidget)
		.ItemText(NSLOCTEXT("SlAiMenu", "NewGame", "NewGame"))
		.ItemType(EMenuItem::NewGame)
		.OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked)
	);
	//������Ϸ
	StartGameList.Add(
		SNew(SSlAiMenuItemWidget)
		.ItemText(NSLOCTEXT("SlAiMenu", "LoadRecord", "LoadRecord"))
		.ItemType(EMenuItem::LoadRecord)
		.OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked)
	);
	//����
	StartGameList.Add(
		SNew(SSlAiMenuItemWidget)
		.ItemText(NSLOCTEXT("SlAiMenu", "GoBack", "GoBack"))
		.ItemType(EMenuItem::StartGameGoBack)
		.OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked)
	);

	MenuMap.Add(EMenuType::StartGame, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "StartGame", "StartGame"), 510.f, &StartGameList)));

	//��Ϸ���ý���
	TArray<TSharedPtr<SCompoundWidget>> GameOpthionList;
	//ʵ������Ϸ���õ�Widget
	SAssignNew(GameOptionWidget, SSlAiGameOptionWidget)
		.ChangeCulture(this, &SSlAiMenuWidget::ChangeCulture)
		.ChangeVolume(this, &SSlAiMenuWidget::ChangeVolume);
	//��ӿؼ�������
	GameOpthionList.Add(GameOptionWidget);
	//���GoBack��ť
	GameOpthionList.Add(
		SNew(SSlAiMenuItemWidget)
		.ItemText(NSLOCTEXT("SlAiMenu", "GoBack", "GoBack"))
		.ItemType(EMenuItem::GameOptionGoBack)
		.OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked)
	);

	MenuMap.Add(EMenuType::GameOption, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "GameOption", "GameOption"), 610.f, &GameOpthionList)));

	//��ʼ����Ϸ����
	TArray<TSharedPtr<SCompoundWidget>> NewGameList;
	SAssignNew(NewGameWidget, SSlAiNewGameWidget);
	NewGameList.Add(NewGameWidget);
	NewGameList.Add(
		SNew(SSlAiMenuItemWidget)
		.ItemText(NSLOCTEXT("SlAiMenu", "EnterGame", "EnterGame"))
		.ItemType(EMenuItem::EnterGame)
		.OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked)
	);
	NewGameList.Add(
		SNew(SSlAiMenuItemWidget)
		.ItemText(NSLOCTEXT("SlAiMenu", "GoBack", "GoBack"))
		.ItemType(EMenuItem::NewGameGoBack)
		.OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked)
	);

	MenuMap.Add(EMenuType::NewGame, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "NewGame", "NewGame"), 510.f, &NewGameList)));

	//ѡ��浵����
	TArray<TSharedPtr<SCompoundWidget>> ChooseRecordList;
	SAssignNew(ChooseRecordWidget, SSlAiChooseRecordWidget);
	ChooseRecordList.Add(
		SNew(SSlAiMenuItemWidget)
		.ItemText(NSLOCTEXT("SlAiMenu", "EnterRecord", "EnterRecord"))
		.ItemType(EMenuItem::ChooseRecordGoBack)
		.OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked)
	);
	ChooseRecordList.Add(
		SNew(SSlAiMenuItemWidget)
		.ItemText(NSLOCTEXT("SlAiMenu", "GoBack", "GoBack"))
		.ItemType(EMenuItem::ChooseRecordGoBack)
		.OnClicked(this, &SSlAiMenuWidget::MenuItemOnClicked)
	);

	MenuMap.Add(EMenuType::ChooseRecord, MakeShareable(new MenuGroup(NSLOCTEXT("SlAiMenu", "LoadRecord", "LoadRecord"), 510.f, &ChooseRecordList)));

	//Ĭ�����������˵�
	ChooseWidget(EMenuType::MainMenu);
}

void SSlAiMenuWidget::ChooseWidget(EMenuType::Type WidgetType)
{
	//�Ƴ��������
	ContentBox->ClearChildren();
	//���MenuType�ǲ���none
	if (WidgetType == EMenuType::None)
	{
		return;
	}
	//ѭ��������
	for (TArray<TSharedPtr<SCompoundWidget>>::TIterator It((*MenuMap.Find(WidgetType))->ChildWidget); It; ++It)
	{
	ContentBox->AddSlot().AutoHeight()
		[
			(*It)->AsShared()
		];
	}
	//���ı���
	TitleText->SetText((*MenuMap.Find(WidgetType))->MenuName);
	//�޸�Size
	ResetWidgetSize(600.f, (*MenuMap.Find(WidgetType))->MenuHeight);
}

//������޸ĸ߶ȣ�����-1
void SSlAiMenuWidget::ResetWidgetSize(float NewWidget, float NewHeight)
{
	RootSizeBox->SetWidthOverride(NewWidget);
	if (NewHeight<0)
	{
		return;
	}
	RootSizeBox->SetHeightOverride(NewHeight);
}

