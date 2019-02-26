// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "SlateWidgetStyleContainerBase.h"
#include <SlateBrush.h>

#include "SlAiMenuWidgetStyle.generated.h"

/**
 *
 */
USTRUCT()
struct SLATECPP_API FSlAiMenuStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

		FSlAiMenuStyle();
	virtual ~FSlAiMenuStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FSlAiMenuStyle& GetDefault();

	//���ڱ���ͼƬ
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush MenuHUDBackgroundBrush;
	//ָ��Menu����ͼƬ
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush MenuBackgroundBrush;
	//Menu��ͼ���Brush
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush LeftIconBrush;
	//Menu��ͼ���Brush
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush RightIconBrush;
	//Menu����Border��Brush
	UPROPERTY(EditAnywhere, Category = MenuHUD)
		FSlateBrush TileBorderBrush;
};

/**
 */
UCLASS(hidecategories = Object, MinimalAPI)
class USlAiMenuWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:
	/** The actual data describing the widget appearance. */
	UPROPERTY(Category = Appearance, EditAnywhere, meta = (ShowOnlyInnerProperties))
		FSlAiMenuStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast<const struct FSlateWidgetStyle*>(&WidgetStyle);
	}
};
