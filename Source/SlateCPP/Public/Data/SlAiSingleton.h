// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * ����ģ��ĵ���ģʽ
 */

template<class T>
class SLATECPP_API SlAiSingleton
{
public:
	static TSharedPtr<T> Get();

private:
	static void Initialize();

	static TSharedRef<T> Create();

private:
	static TSharedPtr<T> TInstance;
};

