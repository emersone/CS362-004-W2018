/* -----------------------------------------------------------------------
 * Name: Elizabeth Emerson
 * Filename: cardtest3.c
 * Class: CS 362
 * Assignment: Assignment 3
 * Date: 4 Feb 2018
 * Notes: This is for the Gardens card.
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

//Prints out whether or not test was a success or failure.
int assertTrue(int x) {
	
	if (x == 1) {
		printf("Success! The Gardens card returns -1 as expected. \n");
		return 1;
	}
	
	printf("Fail! The Gardens card should return -1, but does not.\n");
	return 0;
}


//This function tests the Gardens card if its implementation is INSIDE cardEffect().
int TestCardEffectGardens() {
	
	struct gameState state;		//Create gameState object.
	int handPos = 0;			//Set hand position to 0.
	int result = 0;				//Set result to 0.
	
	printf("Begin Gardens Card Test 1: tests implementation INSIDE of cardEffect().\n");
	
	//Call Gardens card.
	result = cardEffect(gardens, 1, 2, 3, &state, handPos, NULL);

	//Check that return value of Gardens card is correct.
	assertTrue(result == -1);
	
	printf("End Gardens Card Test 1.\n\n");
	return 0;
}


//This function tests the Gardens card if its implementation is OUTSIDE of cardEffect().
int TestGardens_card() {
	
	struct gameState state;		//Create gameState object.
	int currentPlayer = 0;		//Set currentPlayer to 0.
	int handPos = 0;			//Set hand position to 0.
	int result = 0;				//Set result to 0.
	
	printf("Begin Gardens Card Test 2: tests implementation OUTSIDE of cardEffect().\n");
		
	//Call Gardens card.
	result = gardens_card(&state, currentPlayer, handPos);
	
	//Check that return value of Gardens card is correct.
	assertTrue(result == -1);
	
	printf("End Gardens Card Test 2.\n\n");
	return 0;
}


//This is the main function, it calls the relevant functions to test the gardens card.
int main() {
	
	TestCardEffectGardens();
	TestGardens_card();
	return 0;
}