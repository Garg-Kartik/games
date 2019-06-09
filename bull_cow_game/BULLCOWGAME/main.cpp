#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

FBullCowGame BCGame;

void GameIntro();
void PlayGame(); 
Ftext GetValidGuess();
bool PlayAgain();
void PrintGameSummary();


int main()
{
	bool bPlayAgain = false;
	do
	{
		GameIntro();
		PlayGame();
		bPlayAgain = PlayAgain();
	} while (bPlayAgain);
		
	return 0;
}

void GameIntro()
{
	std::cout << "Welcome to BULLS and COWS game, a fun word game.\n";
		std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl; 
	std::cout<<"BULLS= Number of matching letters in same position\nCOWS= number of matching letters in different position\n\n";
	std::cout << "Do you have what it takes to guess the " << BCGame.GetHiddenWordLength() << " letter isogram I am thinking of?\n\n\n";
	
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries=BCGame.GetMaxTries();

	// TODO change from for to while loop

	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry()<=MaxTries)
	{Ftext guess =GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(guess); 
		std::cout << "Bulls: " << BullCowCount.Bulls << " Cows: " << BullCowCount.Cows << "\n\n\n";
		
	}
	PrintGameSummary();
	return;
}

Ftext GetValidGuess()
{
	Ftext guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	int32 CurrentTry = BCGame.GetCurrentTry();
	do {

		
		std::cout << "Try " << CurrentTry <<" of "<< BCGame.GetMaxTries()<< " Enter your Guess : ";
		std::getline(std::cin, guess);
		Status = BCGame.CheckGuessValidity(guess);

		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word\n\n ";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an Isogram i.e. a word with all different letters\n\n";
			break;
		case EGuessStatus::Not_LowerCase:
			std::cout << "Please enter an lowercase letter\n\n";
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);

	Ftext response = "";
	if (CurrentTry == 3)
	{
		std::cout << "Do you want a hint(y/n)?";
		std::getline(std::cin, response);
	}
	while (response=="y")
	{
		char FirstLetter=BCGame.GetHint();
		std::cout << "The First letter of the word is " << FirstLetter<< std::endl;
		break;
	}
	
	return guess;

}
	 

 bool PlayAgain()
 {
	 BCGame.Reset(); //sasd
	 std::cout << "Do you want to play again(y/n)?";
	 Ftext response = "";
	 std::getline(std::cin, response);
	 return (response[0] == 'y') || (response[0] == 'Y');
 }


 void PrintGameSummary()
 {
	 if (BCGame.IsGameWon() == true)
	 {
		 std::cout << "Congratulations, you WON the Game\n";
	 }
	 else 
	 {
		 std::cout << "Sorry, you lost the game\n";
	 }
 }