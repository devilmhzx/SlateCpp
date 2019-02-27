// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SlAiTypes.h"


/**
 * 
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


private:
	//������ڵ�
	TSharedPtr<class SBox> RootSizeBox;

	//��ȡMenuStyle
	const struct  FSlAiMenuStyle* MenuStyle;

	//�������
	TSharedPtr<class STextBlock> TitelText;

	//���洹ֱ�б�
	TSharedPtr<class SVerticalBox> ContentBox;

};
