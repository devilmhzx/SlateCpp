// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SlAiTypes.h"





/**
 * 主UI
 */
class SLATECPP_API SSlAiMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiMenuWidget)
	{}



	SLATE_END_ARGS()

		/** Constructs this widget with InArgs */
		void Construct(const FArguments& InArgs);

private:
	//绑定到各个MenuItem的方法
	void MenuItemOnClicked(EMenuItem::Type ItemType);

	//修改语言
	void ChangeCulture(ECultureTeam Culture);

	//修改音量
	void ChangeVolume(const float MusciVolume, const float SoundVolume);

	//初始化所有的控件
	void InitalizedMenuList();

	//选择显示的界面
	void ChooseWidget(EMenuType::Type WidgetType);

	//修改菜单的大小
	void ResetWidgetSize(float NewWidget, float NewHeight);

private:
	//保存根节点
	TSharedPtr<class SBox> RootSizeBox;

	//获取MenuStyle
	const struct  FSlAiMenuStyle* MenuStyle;

	//保存标题
	TSharedPtr<class STextBlock> TitleText;

	//保存垂直列表
	TSharedPtr<class SVerticalBox> ContentBox;

	//保存菜单组
	TMap<EMenuType::Type, TSharedPtr<struct MenuGroup>> MenuMap;
	//游戏设置Widget的指针
	TSharedPtr<class SSlAiGameOptionWidget> GameOptionWidget;
	//新游戏控件指针
	TSharedPtr<class SSlAiNewGameWidget> NewGameWidget;
	//选择存档控件指针
	TSharedPtr<class SSlAiChooseRecordWidget> ChooseRecordWidget;
};
