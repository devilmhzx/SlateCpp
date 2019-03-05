// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SlAiTypes.h"





/**
 * ��UI
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
	//�󶨵�����MenuItem�ķ���
	void MenuItemOnClicked(EMenuItem::Type ItemType);

	//�޸�����
	void ChangeCulture(ECultureTeam Culture);

	//�޸�����
	void ChangeVolume(const float MusciVolume, const float SoundVolume);

	//��ʼ�����еĿؼ�
	void InitalizedMenuList();

	//ѡ����ʾ�Ľ���
	void ChooseWidget(EMenuType::Type WidgetType);

	//�޸Ĳ˵��Ĵ�С
	void ResetWidgetSize(float NewWidget, float NewHeight);

private:
	//������ڵ�
	TSharedPtr<class SBox> RootSizeBox;

	//��ȡMenuStyle
	const struct  FSlAiMenuStyle* MenuStyle;

	//�������
	TSharedPtr<class STextBlock> TitleText;

	//���洹ֱ�б�
	TSharedPtr<class SVerticalBox> ContentBox;

	//����˵���
	TMap<EMenuType::Type, TSharedPtr<struct MenuGroup>> MenuMap;
	//��Ϸ����Widget��ָ��
	TSharedPtr<class SSlAiGameOptionWidget> GameOptionWidget;
	//����Ϸ�ؼ�ָ��
	TSharedPtr<class SSlAiNewGameWidget> NewGameWidget;
	//ѡ��浵�ؼ�ָ��
	TSharedPtr<class SSlAiChooseRecordWidget> ChooseRecordWidget;
};
