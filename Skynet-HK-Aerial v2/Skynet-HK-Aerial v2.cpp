// Skynet HK-Aerial.cpp
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int randomNum = rand();
	int enemyLocation = (randomNum % 64) + 1;
	int ping = 1, searchGridHighNumber = 64, searchGridLowNumber = 1;
	int targetLocationPrediction = 0;
	int playerGuess, guessLow = 0, guessHigh = 0;
	int randomGuess = (randomNum % 64) + 1;
	int linearGuess = 1;
	bool isHit = false;

	//Start Message
	cout << "INITIALIZING... START\n\nWelcome to the SKYNET HK-Aerial Drone Demo!\n\nThe enemy is at locale #" << enemyLocation << " on grid 8x8 with 64 locales\n\nTest in Progress..";

	//Start player's input
	cout << "\n\nLOADING... Human Test Initiated. Please enter your guess for the enemies location\n\n";

	do 
	{
		cout << "Enter Locale: ";
		cin >> playerGuess;
		cout << "\n\nSkynet HK-Aerial sending out signal ping #" << ping;			
		cout << "\nHighest Guess: " << guessHigh;
		cout << "\nLowest Guess: " << guessLow;

		//Checks if player hit the enemy
		if(playerGuess == enemyLocation){
			cout << "\n\nEnemy was at locale #" << enemyLocation;
			cout << "\nTarget neutralized at locale #" << playerGuess;
			cout << "\nHuman took " << ping << " attempts to find and neutralize the enemy\n\n";
			isHit = true;
			break;
		}
		//Tells the player they aimed too low and then adds a number to help them adjust aim
		if (playerGuess < enemyLocation) {
			cout << "\n\nEnemy Missed! You were too low, try again";
			guessLow = playerGuess;
			ping++;
		}
		//Tells the player they aimed too high and then adds a number to help them adjust aim
		if (playerGuess > enemyLocation) {
			cout << "\n\nEnemy Missed! You were too high, try again";
			guessHigh = playerGuess;
			ping++;
		}

	} while (isHit == false);

	isHit = false;
	ping = 1;

	//Enter the dumb random guess AI!
	cout << "Starting Random Search AI...";

	do 
	{
		//Ai hits the enemy
		if (randomGuess == enemyLocation) {
			cout << "\n\nEnemy was at locale #" << enemyLocation;
			cout << "\nTarget neutralized at locale #" << randomGuess;
			cout << "\nRandom AI took " << ping << " attempts to find and neutralize the enemy\n\n";
			isHit = true;
			break;
		}
		//AI was too low
		if (randomGuess < enemyLocation) {
			cout << "\n\nRandomAIwas too low! Running again...";
			randomNum = rand();
			ping++;
		}
		//Ai was too High
		if (randomGuess > enemyLocation) {
			cout << "\n\nRandomAIwas too high! Running again...";
			randomNum = rand();
			ping++;
		}
	} while (isHit == false);

	isHit = false;
	ping = 1;

	//Enter the linear search AI
	cout << "Starting Linear Search AI...";

	do 
	{
		//AI hit the enemy
		if (linearGuess == enemyLocation) {
			cout << "\n\nEnemy was at locale #" << enemyLocation;
			cout << "\nTarget neutralized at locale #" << randomGuess;
			cout << "\nLinear AI took " << ping << " attempts to find and neutralize the enemy\n\n";
			isHit = true;
			break;
		}
		//Ai was too low
		if (linearGuess < enemyLocation) {
			linearGuess++;
			ping++;
		}
		//Ai was too high
		if (linearGuess > enemyLocation) {
			linearGuess--;
			ping++;
		}
	} while (isHit == false);

	isHit = false;
	ping = 1;

	cout << "Starting Bianary Search AI...";
	//"do-while" loop to carry out the search and update variables as needed during the search
	do
	{
		//Outputs the ping message
		int targetLocationPrediction = ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
		cout << "\n\nSkynet HK-Aerial sending out signal ping #" << ping;

		//First check to see if we hit the target, if so it breaks the loop
		if (targetLocationPrediction == enemyLocation) {
			cout << "\n\nEnemy was at locale #" << enemyLocation;
			cout << "\nTarget neutralized at locale #" << targetLocationPrediction;
			cout << "\nSkynet HK-Aerial System v0.0.1 took " << ping << " attempts to find and neutralize the enemy\n\n";
			isHit = true;
			break;
		}
		//Second check, adjusts the low check number to get closer to the target
		if (targetLocationPrediction < enemyLocation) {
			cout << "\n\nThe target's predicted location of locale #" << searchGridLowNumber << " was lower than the enemy's actual position at locale #" << enemyLocation;
			searchGridLowNumber = targetLocationPrediction;
			ping++;
		}
		//Third check, adjusts the high check number to get closer to the target
		if (targetLocationPrediction > enemyLocation) {
			cout << "\n\nThe target's predicted location of locale #" << searchGridHighNumber << " was higher than the enemy's actual position at locale #" << enemyLocation;
			searchGridHighNumber = targetLocationPrediction;
			ping++;
		}
	//Sets the parameters for the loop
	} while (isHit == false && targetLocationPrediction <= 64);
}