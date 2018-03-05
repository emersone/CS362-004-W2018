/* -----------------------------------------------------------------------
 * Name: Elizabeth Emerson
 * Filename: cardtest2.c
 * Class: CS 362
 * Assignment: Assignment 3
 * Date: 4 Feb 2018
 * Notes: This is for the Village card.
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "initGame.h"


//Prints out whether or not test was a success or failure.
int assertTrue(int x) {
	
	if (x == 1) {
		printf("Success! All works as expected.\n");
		return 1;
	}
	
	printf("Fail! There is a bug in your code.\n");
	return 0;
}


//This function tests the Village card if its implementation is INSIDE cardEffect().
int TestCardEffectVillage() {
	
	printf("Begin Village Card Test 1: tests implementation INSIDE of cardEffect().\n");
	
	struct gameState state;		//Create gameState object.	
	int currentPlayer = 0;		//Set currentPlayer to 0.
	int handPos = 0;			//Set hand position to 0.
	int result = 0;				//Set result to 0.

	//Initialize beginning cards.	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	//Check the state of the game prior to calling Village card.
	assertTrue(state.handCount[currentPlayer] == 5);
	assertTrue(state.deckCount[currentPlayer] == 5);
	assertTrue(state.numActions == 1);
	
	//Call Village card.
	result = cardEffect(village, 1, 2, 3, &state, handPos, NULL);

	//Check that return value of Village card is correct.
	assertTrue(result == 0);
	
	//Check that handCount and deckCount incremented/decremented as expected.
	assertTrue(state.handCount[currentPlayer] == 5);
	assertTrue(state.deckCount[currentPlayer] == 4);
	assertTrue(state.numActions == 3);
	
	printf("End Village Card Test 1.\n\n");
	return 0;
}


//This function tests the Village card if its implementation is OUTSIDE of cardEffect().
int TestVillage_card() {
	
	printf("Begin Village Card Test 2: tests implementation OUTSIDE of cardEffect().\n");
	
	struct gameState state;		//Create gameState object.
	int currentPlayer = 0;		//Set currentPlayer to 0.
	int handPos = 0;			//Set hand position to 0.
	int result = 0;				//Set result to 0.
	
	//Initialize beginning cards.
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	//Check the state of the game prior to calling Village card.
	assertTrue(state.handCount[currentPlayer] == 5);
	assertTrue(state.deckCount[currentPlayer] == 5);
	assertTrue(state.numActions == 1);
	
	//Call Village card.
	result = playVillage(&state, currentPlayer, handPos);
	
	//Check that return value of Village card is correct.
	assertTrue(result == 0);
	
	//Check that handCount and deckCount incremented/decremented as expected.
	assertTrue(state.handCount[currentPlayer] == 5);
	assertTrue(state.deckCount[currentPlayer] == 4);
	assertTrue(state.numActions == 3);
	
	printf("End Village Card Test 2.\n\n");
	return 0;
}





//This is the main function, it calls the relevant functions to test the Village card.
int main() {
	
	TestCardEffectVillage();
	TestVillage_card();
	return 0;
}