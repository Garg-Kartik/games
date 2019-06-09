#pragma once
#include<string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};
enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_LowerCase,

};

class FBullCowGame 
{
	
public:
		FBullCowGame();  //constructor

		int32 GetMaxTries() const;
		int32 GetHiddenWordLength() const;
		int32 GetCurrentTry() const;
		bool IsGameWon() const;
		EGuessStatus CheckGuessValidity(FString) const;
		char GetHint() const;

		void Reset(); // TODO make a more rich returrn value

		//provide method to count bulls and cows
		FBullCowCount SubmitValidGuess(FString guess); //

private:

	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameisWon;
	bool IsIsogram(FString) const;
	bool IsLower(FString) const;

};