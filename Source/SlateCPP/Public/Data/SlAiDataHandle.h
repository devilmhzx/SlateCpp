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
	//�޸Ĳ˵�����
	void ResetMenuVolume(float MusicVol, float SoundVol);


public:
	//����
	ECultureTeam CurrentCulture;
	//����
	float MusicVolume;
	float SoundVolume;
	//�浵����
	TArray<FString> RecordDataList;

private:
	//��������
	static TSharedPtr<SlAiDataHandle> Create();

	//����enum���ͻ�ȡ�ַ���
	template<typename TEnum>
	FString GetEnumValueAsString(const FString& Name, TEnum Value);

	//�����ַ�������ȡEnumֵ
	template<typename TEnum>
	TEnum GetEnumValueFromString(const FString& Name,FString Value);

	//��ʼ���浵����
	void InitRecordData();

private:

	static TSharedPtr<SlAiDataHandle> DataInstance;
};

