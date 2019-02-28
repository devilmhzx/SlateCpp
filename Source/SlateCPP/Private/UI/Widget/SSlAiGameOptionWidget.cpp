// Fill out your copyright notice in the Description page of Project Settings.

#include "SSlAiGameOptionWidget.h"
#include "SlateOptMacros.h"
#include "SlAiStyle.h"
#include "SlAiMenuWidgetStyle.h"
#include <SBox.h>
#include <SOverlay.h>
#include <SImage.h>
#include <SBoxPanel.h>
#include <SCheckBox.h>
#include <STextBlock.h>
#include "SlAiDataHandle.h"
#include <SSlider.h>
#include <UnrealMathUtility.h>

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlAiGameOptionWidget::Construct(const FArguments& InArgs)
{

	//��ȡMenuStyle
	MenuStyle = &SlAiStyle::Get().GetWidgetStyle<FSlAiMenuStyle>("BPSlAiMenuStyle");

	ChildSlot
		[
			SNew(SBox)
			.WidthOverride(500.f)
		.HeightOverride(300.f)
		[
			SNew(SOverlay)

			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.Image(&MenuStyle->GameOptionBGBrush)
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(FMargin(50.f))
		[
			SNew(SVerticalBox)
			//��һ��
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillHeight(1.f)
		[
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillWidth(1.f)
		[
			SAssignNew(ZhCheckBox, SCheckBox)
			.OnCheckStateChanged(this, &SSlAiGameOptionWidget::ZhCheckBoxStateChanged)
		[
			SNew(STextBlock)
			.Font(MenuStyle->Font_40)
		.ColorAndOpacity(MenuStyle->FontColor_Black)
		.Text(NSLOCTEXT("SlAiMenu", "Chinese", "Chinese"))
		]
		]

	+ SHorizontalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillWidth(1.f)
		[
			SAssignNew(EnCheckBox, SCheckBox)
			.OnCheckStateChanged(this, &SSlAiGameOptionWidget::EnCheckBoxStateChanged)
		[
			SNew(STextBlock)
			.Font(MenuStyle->Font_40)
		.ColorAndOpacity(MenuStyle->FontColor_Black)
		.Text(NSLOCTEXT("SlAiMenu", "Enlish", "Enlish"))
		]
		]
		]

	//�ڶ���
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillHeight(1.f)
		[
			SNew(SOverlay)

			+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(MenuStyle->Font_40)
		.ColorAndOpacity(MenuStyle->FontColor_Black)
		.Text(NSLOCTEXT("SlAiMenu", "Music", "Music"))
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SBox)
			.WidthOverride(240.f)
		[
			SNew(SOverlay)

			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		.Padding(FMargin(30.f, 0.f))
		[
			SNew(SImage)
			.Image(&MenuStyle->SliderBarBrush)
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		[
			SAssignNew(MuSlider, SSlider)
			.Style(&MenuStyle->SliderStyle)
		.OnValueChanged(this, &SSlAiGameOptionWidget::MusicSliderChanged)
		]
		]
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		[
			SAssignNew(MuTextBlock, STextBlock)
			.Font(MenuStyle->Font_40)
		.ColorAndOpacity(MenuStyle->FontColor_Black)

		]
		]

	//������
	+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.FillHeight(1.f)
		[
			SNew(SOverlay)

			+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Font(MenuStyle->Font_40)
		.ColorAndOpacity(MenuStyle->FontColor_Black)
		.Text(NSLOCTEXT("SlAiMenu", "Sound", "Sound"))
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SBox)
			.WidthOverride(240.f)
		[
			SNew(SOverlay)

			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		.Padding(FMargin(30.f, 0.f))
		[
			SNew(SImage)
			.Image(&MenuStyle->SliderBarBrush)
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		[
			SAssignNew(SoSlider, SSlider)
			.Style(&MenuStyle->SliderStyle)
		.OnValueChanged(this, &SSlAiGameOptionWidget::SoundSliderChanged)
		]
		]
		]

	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		[
			SAssignNew(SoTextBlock, STextBlock)
			.Font(MenuStyle->Font_40)
		.ColorAndOpacity(MenuStyle->FontColor_Black)

		]
		]

		]
		]
		];

	StyleInitialized();
}

void SSlAiGameOptionWidget::StyleInitialized()
{
	//����ZhCheckBox��ʽ
	ZhCheckBox->SetUncheckedImage(&MenuStyle->UnCheckdBoxBrush);
	ZhCheckBox->SetUncheckedHoveredImage(&MenuStyle->UnCheckdBoxBrush);
	ZhCheckBox->SetUncheckedPressedImage(&MenuStyle->UnCheckdBoxBrush);
	ZhCheckBox->SetCheckedImage(&MenuStyle->CheckdBoxBrush);
	ZhCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckdBoxBrush);
	ZhCheckBox->SetCheckedPressedImage(&MenuStyle->CheckdBoxBrush);

	//����EnCheckBox��ʽ
	EnCheckBox->SetUncheckedImage(&MenuStyle->UnCheckdBoxBrush);
	EnCheckBox->SetUncheckedHoveredImage(&MenuStyle->UnCheckdBoxBrush);
	EnCheckBox->SetUncheckedPressedImage(&MenuStyle->UnCheckdBoxBrush);
	EnCheckBox->SetCheckedImage(&MenuStyle->CheckdBoxBrush);
	EnCheckBox->SetCheckedHoveredImage(&MenuStyle->CheckdBoxBrush);
	EnCheckBox->SetCheckedPressedImage(&MenuStyle->CheckdBoxBrush);

	switch (SlAiDataHandle::Get()->CurrentCulture)
	{
	case ECultureTeam::EN:
		EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
		ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
		break;
	case ECultureTeam::ZH:
		EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
		ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);
		break;
	}

	//����Ĭ��ֵ
	MuSlider->SetValue(0.5f);
	SoSlider->SetValue(0.5f);

	MuTextBlock->SetText(FText::FromString(FString("50%")));
	SoTextBlock->SetText(FText::FromString(FString("50%")));
}

void SSlAiGameOptionWidget::MusicSliderChanged(float Value)
{
	//��ʾ�ٷֱ�
	MuTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value * 100)) + FString("%")));

}

void SSlAiGameOptionWidget::SoundSliderChanged(float Value)
{
	//��ʾ�ٷֱ�
	SoTextBlock->SetText(FText::FromString(FString::FromInt(FMath::RoundToInt(Value * 100)) + FString("%")));

}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSlAiGameOptionWidget::ZhCheckBoxStateChanged(ECheckBoxState NewState)
{
	//���ñ�ѡ�еĿ�
	EnCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Checked);
	//�������ݿ�����ת��Ϊ����
	SlAiDataHandle::Get()->ChangeLocalizationCulture(ECultureTeam::ZH);
}

void SSlAiGameOptionWidget::EnCheckBoxStateChanged(ECheckBoxState NewState)
{
	//���ñ�ѡ�еĿ�
	EnCheckBox->SetIsChecked(ECheckBoxState::Checked);
	ZhCheckBox->SetIsChecked(ECheckBoxState::Unchecked);
	//�������ݿ�����ת��Ϊ����
	SlAiDataHandle::Get()->ChangeLocalizationCulture(ECultureTeam::EN);
}

