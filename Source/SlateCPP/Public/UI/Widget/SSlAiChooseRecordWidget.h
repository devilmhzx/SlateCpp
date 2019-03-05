// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"


/**
 * 
 */
class SLATECPP_API SSlAiChooseRecordWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiChooseRecordWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//更新存档名
	void UpdateRecordName();

private:
	//获取MenuStyle
	const struct  FSlAiMenuStyle* MenuStyle;
	//存档下拉菜单
	TSharedPtr<class STextComboBox> RecordComboBox;
	//存档字符指针数组
	TArray<TSharedPtr<FString>> OptionsSource;


};
