#pragma once
#include <string>
#include <list>

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
	Not_Lowercase
};


// all values initialized to 0
class FBullCowGame 
{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;
	
	void Reset(); // TODO make a more rich return value
	FBullCowCount SubmitValidGuess(FString);


private:
	// see constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	char WordChoices[10][7] = {"candle", "planes", "boiler", "depart", "coaxed", "rights", "urgent", "drowsy", "sweaty", "united"};
	bool bGameIsWon;
	
	
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};