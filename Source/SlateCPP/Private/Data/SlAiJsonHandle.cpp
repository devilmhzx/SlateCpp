// Fill out your copyright notice in the Description page of Project Settings.

#include "SlAiJsonHandle.h"
#include "SlAiHelper.h"

SlAiJsonHandle::SlAiJsonHandle()
{
	RecordDataFileName = FString("RecordData.json");

	RelativePath = FString("Res/ConfigData/");

}

bool SlAiJsonHandle::LoadStringFromFile(const FString& FileName, const FString& RelaPath, FString& ResultString)
{
	//���ж��ļ����Ƿ����
	if (!FileName.IsEmpty())
	{
		//��ȡ����·��
		FString AbsoPath = FPaths::ProjectContentDir() + RelaPath + FileName;
		if (FPaths::FileExists(AbsoPath))
		{
			if (FFileHelper::LoadFileToString(ResultString,*AbsoPath))
			{
				return true;
			}
			else
			{
				//���ز��ɹ�
				SlAiHelper::Debug(FString("Load Error") + AbsoPath);
			}
		}
		else
		{
			//����ļ�������
			SlAiHelper::Debug(FString("File Not Exist") + AbsoPath);
		}

	}
	return false;
}

