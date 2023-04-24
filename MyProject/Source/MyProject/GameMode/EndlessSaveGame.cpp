// Fill out your copyright notice in the Description page of Project Settings.


#include "EndlessSaveGame.h"

UEndlessSaveGame::UEndlessSaveGame()
{
	
}

void UEndlessSaveGame::AddHighScore(int Score)
{
	if (HighScoreList.Num() < 10)
	{
		HighScoreList.Add(Score);
	}
	else if (Score > HighScoreList[9])
	{
		SortHighScoreList(Score);
	}
}

void UEndlessSaveGame::SortHighScoreList(int Score)
{
	for (int i : HighScoreList)
	{
		if (Score > i)
		{
			HighScoreList.Insert(Score, 0);
			HighScoreList.RemoveAt(10);
			break;
		}
	}
}

TArray<int> UEndlessSaveGame::GetHighScoreList()
{
	return HighScoreList;
}
