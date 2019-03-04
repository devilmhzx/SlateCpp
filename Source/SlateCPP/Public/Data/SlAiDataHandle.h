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

	//修改中文
	void ChangeLocalizationCulture(ECultureTeam Culture);
	//修改菜单音量
	void ResetMenuVolume(float MusicVol, float SoundVol);


public:
	//语言
	ECultureTeam CurrentCulture;
	//音量
	float MusicVolume;
	float SoundVolume;
	//存档数据
	TArray<FString> RecordDataList;

private:
	//创建单例
	static TSharedPtr<SlAiDataHandle> Create();

	//根据enum类型获取字符串
	template<typename TEnum>
	FString GetEnumValueAsString(const FString& Name, TEnum Value);

	//根据字符串来获取Enum值
	template<typename TEnum>
	TEnum GetEnumValueFromString(const FString& Name,FString Value);

	//初始化存档数据
	void InitRecordData();

private:

	static TSharedPtr<SlAiDataHandle> DataInstance;
};

