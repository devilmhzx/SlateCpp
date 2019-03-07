// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SlAiTypes.h"


/**
 * ��Ϸ���ý���
 */

class SCheckBox;
class SSlider;
class STextBlock;

//�޸���Ӣ��ί��
DECLARE_DELEGATE_OneParam(FChangeCulture, const ECultureTeam)
//�޸�����ί��
DECLARE_DELEGATE_TwoParams(FChangeVolume, const float, const float)

class SLATECPP_API SSlAiGameOptionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiGameOptionWidget)
	{}

	//����¼�
	SLATE_EVENT(FChangeCulture, ChangeCulture)

	SLATE_EVENT(FChangeVolume, ChangeVolume)

		SLATE_END_ARGS()

		/** Constructs this widget with InArgs */
		void Construct(const FArguments& InArgs);

private:
	//����CheckBox�¼�
	void ZhCheckBoxStateChanged(ECheckBoxState NewState);
	//Ӣ��CheckBox�¼�
	void EnCheckBoxStateChanged(ECheckBoxState NewState);
	//ͳһ������ʽ
	void StyleInitialized();

	//�����仯�¼�
	void MusicSliderChanged(float Value);
	//��Ч�仯�¼�
	void SoundSliderChanged(float Value);


private:
	//��ȡMenuStyle
	const struct  FSlAiMenuStyle* MenuStyle;

	//��ȡCheckBoxָ��
	TSharedPtr<SCheckBox> EnCheckBox;
	TSharedPtr<SCheckBox> ZhCheckBox;
	//����������
	TSharedPtr<SSlider> MuSlider;	//��������
	TSharedPtr<SSlider> SoSlider;	//��Ч
	//�������ٷֱ�
	TSharedPtr<STextBlock> MuTextBlock;
	TSharedPtr<STextBlock> SoTextBlock;
public:
	//ί�б���
	FChangeCulture ChangeCulture;
	FChangeVolume ChangeVolume;
};
