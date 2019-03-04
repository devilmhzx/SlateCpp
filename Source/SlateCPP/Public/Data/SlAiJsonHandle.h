// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlAiTypes.h"
#include "Json.h"


/**
 * 
 */
class SLATECPP_API SlAiJsonHandle
{
public:
	SlAiJsonHandle();
	
	//解析存档方法,此处的参数为JS文件里对应的参数类型
	void RecordDataJsonRead(FString& Culture, float& MusicVolume, float& SoundVolume, TArray<FString>& ReacordDataList);

	//修改存档
	void UpdateRecordData(FString Culture, float MusicVolume, float SoundVolume, TArray<FString>* RecordDataList);

private:
	//读取Json文件到字符串
	bool LoadStringFromFile(const FString& FileName, const FString& RelaPath, FString& ResultString);

	//FJsonObject转换为Json格式的字符串
	bool GetFStringInJsonData(const TSharedPtr<FJsonObject>& JsonObj, FString& JsonStr);


	//保存字符串到文件
	bool WriteFileWithJsonData(const FString& JsonStr, const FString& RelaPath, const FString& FileName);

private:
	//存档文件名
	FString RecordDataFileName;
	//相对路径
	FString RelativePath;


};
