// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 游戏设置界面
 */

class SCheckBox;
class SSlider;

class SLATECPP_API SSlAiGameOptionWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiGameOptionWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:
	//中文CheckBox事件
	void ZhCheckBoxStateChanged(ECheckBoxState NewState);
	//英文CheckBox事件
	void EnCheckBoxStateChanged(ECheckBoxState NewState);
	//统一设置样式
	void StyleInitialized();

	//音量变化事件
	void MusicSliderChanged(float Value);
	//音效变化事件
	void SoundSliderChanged(float Value);


private:
	//获取MenuStyle
	const struct  FSlAiMenuStyle* MenuStyle;

	//获取CheckBox指针
	TSharedPtr<SCheckBox> EnCheckBox;
	TSharedPtr<SCheckBox> ZhCheckBox;
	//两个进度条
	TSharedPtr<SSlider> MuSlider;	//背景音乐
	TSharedPtr<SSlider> SoSlider;	//音效
	//进度条百分比
	TSharedPtr<STextBlock> MuTextBlock;
	TSharedPtr<STextBlock> SoTextBlock;
};
