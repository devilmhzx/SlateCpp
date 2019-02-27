// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SlAiTypes.h"

/**
 *
 */

//����ί��
DECLARE_DELEGATE_OneParam(FItemClicked,const EMenuItem::Type)

class SLATECPP_API SSlAiMenuItemWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlAiMenuItemWidget)
	{}

	SLATE_ATTRIBUTE(FText, ItemText)

		SLATE_ATTRIBUTE(EMenuItem::Type, ItemType)

		//�����¼�
		SLATE_EVENT(FItemClicked,OnClicked)

		SLATE_END_ARGS()

		/** Constructs this widget with InArgs */
		void Construct(const FArguments& InArgs);

	//��д�����OnMouseButtonDown����
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	//��д��ť�����ķ���
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	//��д����뿪�ķ���
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;


private:
	//�����¼�ί��
	FItemClicked OnClicked;
	//���水ť����
	EMenuItem::Type ItemType;
	//��ȡMenuStyle
	const struct FSlAiMenuStyle* MenuStyle;

	//��ť�Ƿ��Ѿ�����
	bool IsMouseButtonDown;

private:
	//��ȡ��ɫ
	FSlateColor GetTintColor() const;
};
