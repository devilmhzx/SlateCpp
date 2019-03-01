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
	
private:
	//��ȡJson�ļ����ַ���
	bool LoadStringFromFile(const FString& FileName, const FString& RelaPath, FString& ResultString);

private:
	//�浵�ļ���
	FString RecordDataFileName;
	//���·��
	FString RelativePath;


};
