/* -----------------------------------------------------------------------
 * Name: Elizabeth Emerson
 * Filename: unittest4.c
 * Class: CS 362
 * Assignment: Assignment 3
 * Date: 4 Feb 2018
 * Notes: This is for the whoseTurn() function.
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


//Tests the whoseTurn() function.
int testWhoseTurn() {
	struct gameState state;		//Create gameState object.
	int result;
	
	//Initialize beginning cards.
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
		
	state.whoseTurn = 0; 
	
	result = whoseTurn(&state);

	assertTrue(result==0);
	
	return 0;
}


//This is the main function.
int main() {
	testWhoseTurn();
	return 0;
}