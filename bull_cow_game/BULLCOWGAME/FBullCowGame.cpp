#pragma once
#include "FBullCowGame.h"
#include<map>
#define TMap std::map //notice


using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}



void FBullCowGame::Reset()
{   
	const FString Hidden_Word = "plan";
	MyHiddenWord = Hidden_Word;
	MyCurrentTry = 1;
	bGameisWon = false;
	return;
}


FBullCowCount FBullCowGame::SubmitValidGuess(FString guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();

	for(int32 i=0;i<WordLength;i++) 
	{
		for (int32 j = 0; j < WordLength; j++)
		{
			if (guess[i] == MyHiddenWord[j])
			{
				if (i == j)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++; //
				}
			}
		}

	}
	if (BullCowCount.Bulls==WordLength)
	{
		bGameisWon = true;
	}
	else
	{
		bGameisWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLower(FString Word) const
{
	
	for (auto Letter : Word)
	{
		if(!islower(Letter))
		{
			return false;

		}
	}
}


int32 FBullCowGame::GetHiddenWordLength() const{return MyHiddenWord.length();}
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const{return bGameisWon;}

int32 FBullCowGame::GetMaxTries() const 
{
	TMap<int32, int32> WordLengthToMaxTries{ { 3,6 },{ 4,7 },{ 5,10 },{ 6,12 },{ 7,14 } };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString guess) const
{
	if (!IsIsogram(guess)) //isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLower(guess)) //lowercase
	{
		return EGuessStatus::Not_LowerCase;
	}
	else if (GetHiddenWordLength()!= guess.length())//length
	{
		return EGuessStatus::Wrong_Length;
	}
	else
		return EGuessStatus::OK;



	return EGuessStatus::OK;
}

char FBullCowGame::GetHint() const
{
	char Hint=MyHiddenWord.at(0);
	return Hint;
}
