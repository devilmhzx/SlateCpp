// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlAiTypes.h"

/**
 *
 */
class SLATECPP_API SlAiDataHandle
{
public:
	SlAiDataHandle();

	static void Initialize();

	static TSharedPtr<SlAiDataHandle> Get();

	//�޸�����
	void ChangeLocalizationCulture(ECultureTeam Culture);

public:

	ECultureTeam CurrentCulture;
private:
	//��������
	static TSharedPtr<SlAiDataHandle> Create();

private:

	static TSharedPtr<SlAiDataHandle> DataInstance;
};
