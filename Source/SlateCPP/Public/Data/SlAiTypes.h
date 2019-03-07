// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 定义语言切换数据类别
 */

UENUM()
enum class ECultureTeam:uint8
{
	EN = 0,
	ZH
};

//自定义一个Menu按钮类型
namespace EMenuItem
{
	enum Type
	{
		None,
		StartGame,
		GameOption,
		QuitGame,
		NewGame,
		LoadRecord,
		StartGameGoBack,
		GameOptionGoBack,
		NewGameGoBack,
		ChooseRecordGoBack,
		EnterGame,
		EnterRecord
	};
}

//Menu界面类型
namespace EMenuType
{
	enum Type
	{
		None,
		MainMenu,
		StartGame,
		GameOption,
		NewGame,
		ChooseRecord
	};
}

//Menu动画状态枚举
namespace EMenuAnim
{
	enum Type
	{
		Stop,	//停止动画
		Close,  //关闭Menu
		Open	//打开Menu
	};
}
