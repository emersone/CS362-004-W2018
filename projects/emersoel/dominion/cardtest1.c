/* -----------------------------------------------------------------------
 * Name: Elizabeth Emerson
 * Filename: cardtest.c
 * Class: CS 362
 * Assignment: Assignment 3
 * Date: 4 Feb 2018
 * Notes: This is for the Smithy card.
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "initGame.h"


//
int assertTrue(int x) {
	
	if (x == 1) {
		printf("Success! All works as expected.\n");
		return 1;
	}
	
	printf("Fail! There is a bug in your code.\n");
	return 0;
}


//This function tests the Smithy card if its implementation is INSIDE cardEffect().
int TestCardEffectSmithy() {
	
	printf("Begin Smithy Card Test 1: tests implementation INSIDE of cardEffect().\n");
	
	struct gameState state;		//Create gameState object.	
	int currentPlayer = 0;		//Set currentPlayer to 0.
	int handPos = 0;			//Set hand position to 0.
	int result = 0;				//Set result to 0.

	//Initialize beginning cards.	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	//Check the state of the game prior to calling Smithy card.
	assertTrue(state.handCount[currentPlayer] == 5);
	assertTrue(state.deckCount[currentPlayer] == 5);
	
	//Call Smithy card.
	result = cardEffect(smithy, 1, 2, 3, &state, handPos, NULL);

	//Check that return value of Smithy card is correct.
	assertTrue(result == 0);
	
	//Check that handCount and deckCount incremented/decremented as expected.
	assertTrue(state.handCount[currentPlayer] == 7);
	assertTrue(state.deckCount[currentPlayer] == 2);
	
	printf("End Smithy Card Test 1.\n\n");
	return 0;
}


//This function tests the Smithy card if its implementation is OUTSIDE of cardEffect().
int TestSmithy_card() {
	
	printf("Begin Smithy Card Test 2: tests implementation OUTSIDE of cardEffect().\n");
	
	struct gameState state;		//Create gameState object.
	int currentPlayer = 0;		//Set currentPlayer to 0.
	int handPos = 0;			//Set hand position to 0.
	int result = 0;				//Set result to 0.
	
	//Initialize beginning cards.
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	//Check the state of the game prior to calling Smithy card.
	assertTrue(state.handCount[currentPlayer] == 5);
	assertTrue(state.deckCount[currentPlayer] == 5);
	
	//Call Smithy card.
	result = smithy_card(&state, currentPlayer, handPos);

	//Check that return value of Smithy card is correct.
	assertTrue(result == 0);
	
	//Check that handCount and deckCount incremented/decremented as expected.
	assertTrue(state.handCount[currentPlayer] == 7);
	assertTrue(state.deckCount[currentPlayer] == 2);

	
	printf("End Smithy Card Test 2.\n\n");
	return 0;
}





//This is the main function, it calls the relevant functions to test the Smithy card.
int main() {
	
	TestCardEffectSmithy();
	TestSmithy_card();
	return 0;
}



	



	


