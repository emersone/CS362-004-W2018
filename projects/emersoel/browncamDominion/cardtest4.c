/* -----------------------------------------------------------------------
 * Name: Elizabeth Emerson
 * Filename: cardtest4.c
 * Class: CS 362
 * Assignment: Assignment 3
 * Date: 4 Feb 2018
 * Notes: This is for the Adventurer card.
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


//This function tests the Adventurer card if its implementation is INSIDE cardEffect().
//It tests if treasure cards are located in first and second positions in deck array.
int TestCardEffectAdventurer1() {
	
	printf("Begin Adventurer Card Test 1: tests implementation INSIDE of cardEffect() (Part 1).\n");
		
	struct gameState state;		//Create gameState object.
	int currentPlayer = 0;		//Set currentPlayer to 0.
	int result = 0;				//Set result to 0.
	int i = 0;
	
	//Initialize beginning cards.
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	//Set all cards to copper (ensures first and second positions in array are copper).
	for (i = 0; i < 5; i++) {
		state.deck[0][i] = copper;
	}
	
	//Check the state of the game prior to calling Adventurer card.
	assertTrue(state.handCount[currentPlayer] == 5);
	assertTrue(state.deckCount[currentPlayer] == 5);
	
	//Call Adventurer card.
	result = cardEffect(adventurer, 1, 2, 3, &state, 0, NULL);
	
	//Check that return value of Adventurer card is correct.
	assertTrue(result == 0);
	
	//Check that handCount and deckCount incremented/decremented as expected.
	assertTrue(state.handCount[currentPlayer] == 6);
	assertTrue(state.deckCount[currentPlayer] == 3);

	printf("End Adventurer Card Test 1.\n\n");
	return 0;
}


//This function tests the Adventurer card if its implementation is INSIDE cardEffect().
//It tests if non-treasure card is located in first positions in deck array.
int TestCardEffectAdventurer2() {
	
	printf("Begin Adventurer Card Test 1: tests implementation INSIDE of cardEffect() (Part 2).\n");
		
	struct gameState state;		//Create gameState object.
	int currentPlayer = 0;		//Set currentPlayer to 0.
	int result = 0;				//Set result to 0.
	int i = 0;
	
	//Initialize beginning cards.
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	//Set all cards to copper.
	for (i = 0; i < 5; i++) {
		state.deck[0][i] = copper;
	}
	
	//Insert non-copper card into first position of array.
	state.deck[0][4] = village;
	
	//Check the state of the game prior to calling Adventurer card.
	assertTrue(state.handCount[currentPlayer] == 5);
	assertTrue(state.deckCount[currentPlayer] == 5);
	
	//Call Adventurer card.
	result = cardEffect(adventurer, 1, 2, 3, &state, 0, NULL);
	
	//Check that return value of Adventurer card is correct.
	assertTrue(result == 0);
	
	//Check that handCount and deckCount incremented/decremented as expected.
	assertTrue(state.handCount[currentPlayer] == 6);
	assertTrue(state.deckCount[currentPlayer] == 2);

	printf("End Adventurer Card Test 1.\n\n");
	return 0;
}


//This function tests the Adventurer card if its implementation is INSIDE cardEffect().
//It tests if non-treasure card is located in first and positions in deck array.
int TestCardEffectAdventurer3() {
	
	printf("Begin Adventurer Card Test 1: tests implementation INSIDE of cardEffect() (Part 3).\n");
		
	struct gameState state;		//Create gameState object.
	int currentPlayer = 0;		//Set currentPlayer to 0.
	int result = 0;				//Set result to 0.
	int i = 0;
	
	//Initialize beginning cards.
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	//Set all cards to copper.
	for (i = 0; i < 5; i++) {
		state.deck[0][i] = copper;
	}
	
	//Insert non-copper cards into first and third positions of array.
	state.deck[0][4] = village;
	state.deck[0][2] = embargo;
	
	//Check the state of the game prior to calling Adventurer card.
	assertTrue(state.handCount[currentPlayer] == 5);
	assertTrue(state.deckCount[currentPlayer] == 5);
	
	//Call Adventurer card.
	result = cardEffect(adventurer, 1, 2, 3, &state, 0, NULL);
	
	//Check that return value of Adventurer card is correct.
	assertTrue(result == 0);
	
	//Check that handCount and deckCount incremented/decremented as expected.
	assertTrue(state.handCount[currentPlayer] == 6);
	assertTrue(state.deckCount[currentPlayer] == 1);

	printf("End Adventurer Card Test 1.\n\n");
	return 0;
}


//This function tests the Adventurer card if its implementation is INSIDE cardEffect().
//It tests if there are only non-treasure cards in the deck array.
int TestCardEffectAdventurer4() {
	
	printf("Begin Adventurer Card Test 1: tests implementation INSIDE of cardEffect() (Part 4).\n");
		
	struct gameState state;		//Create gameState object.
	int currentPlayer = 0;		//Set currentPlayer to 0.
	int result = 0;				//Set result to 0.
	int i = 0;
	
	//Initialize beginning cards.
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	//Set all cards to copper.
	for (i = 0; i < 5; i++) {
		state.deck[0][i] = copper;
	}
	
	//Insert non-copper card into second, third, and fourth positions of array.
	state.deck[0][1] = village;
	state.deck[0][2] = embargo;
	state.deck[0][3] = cutpurse;
	
	//Check the state of the game prior to calling Adventurer card.
	assertTrue(state.handCount[currentPlayer] == 5);
	assertTrue(state.deckCount[currentPlayer] == 5);
	
	//Call Adventurer card.
	result = cardEffect(adventurer, 1, 2, 3, &state, 0, NULL);
	
	//Check that return value of Adventurer card is correct.
	assertTrue(result == 0);
	
	//Check that handCount and deckCount incremented/decremented as expected.
	assertTrue(state.handCount[currentPlayer] == 6);
	assertTrue(state.deckCount[currentPlayer] == 0);

	printf("End Adventurer Card Test 1.\n\n");
	return 0;
}


//This function tests the Adventurer card if its implementation is OUTSIDE of cardEffect().
//It tests if treasure cards are located in first and second positions in deck array.
int TestAdventurer_card1() {
	
	printf("Begin Adventurer Card Test 2: tests implementation OUTSIDE of cardEffect() (Part 1).\n");
	
	struct gameState state;		//Create gameState object.
	int currentPlayer = 0;		//Set currentPlayer to 0.
	int result = 0;				//Set result to 0.
	int i = 0;
	
	//Initialize beginning cards.
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	//Set all cards to copper (ensures first and second positions in array are copper).
	for (i = 0; i < 5; i++) {
		state.deck[0][i] = copper;
	}
	
	//Check the state of the game prior to calling Adventurer card.
	assertTrue(state.handCount[currentPlayer] == 5);
	assertTrue(state.deckCount[currentPlayer] == 5);
	
	//Call Adventurer card.
	int temphand[MAX_HAND];
	result = playAdventurer(&state, 0, currentPlayer, temphand, 0);
	
	//Check that return value of Adventurer card is correct.
	assertTrue(result == 0);
	
	//Check that handCount and deckCount incremented/decremented as expected.
	assertTrue(state.handCount[currentPlayer] == 6);
	assertTrue(state.deckCount[currentPlayer] == 3);

	printf("End Adventurer Card Test 2.\n\n");
	return 0;
}


//This function tests the Adventurer card if its implementation is OUTSIDE of cardEffect().
//It tests if non-treasure card is located in first positions in deck array.
int TestAdventurer_card2() {
	
	printf("Begin Adventurer Card Test 2: tests implementation OUTSIDE of cardEffect() (Part 2).\n");
	
	struct gameState state;		//Create gameState object.
	int currentPlayer = 0;		//Set currentPlayer to 0.
	
	int result = 0;				//Set result to 0.
	int i = 0;
	
	//Initialize beginning cards.
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
		
	//Set all cards to copper.
	for (i = 0; i < 5; i++) {
		state.deck[0][i] = copper;
	}
	
	//Insert non-copper card into first position of array.
	state.deck[0][4] = village;
	
	//Check the state of the game prior to calling Adventurer card.
	assertTrue(state.handCount[currentPlayer] == 5);
	assertTrue(state.deckCount[currentPlayer] == 5);
	
	//Call Adventurer card.
	int temphand[MAX_HAND];
	result = playAdventurer(&state, 0, currentPlayer, temphand, 0);
	
	//Check that return value of Adventurer card is correct.
	assertTrue(result == 0);
	
	//Check that handCount and deckCount incremented/decremented as expected.
	assertTrue(state.handCount[currentPlayer] == 6);
	assertTrue(state.deckCount[currentPlayer] == 2);

	printf("End Adventurer Card Test 2.\n\n");
	return 0;
}


//This function tests the Adventurer card if its implementation is OUTSIDE of cardEffect().
//It tests if non-treasure card is located in first and positions in deck array.
int TestAdventurer_card3() {
	
	printf("Begin Adventurer Card Test 2: tests implementation OUTSIDE of cardEffect() (Part 3).\n");
	
	struct gameState state;		//Create gameState object.
	int currentPlayer = 0;		//Set currentPlayer to 0.
	
	int result = 0;				//Set result to 0.
	int i = 0;
	
	//Initialize beginning cards.
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
		
	//Set all cards to copper.
	for (i = 0; i < 5; i++) {
		state.deck[0][i] = copper;
	}
	
	//Insert non-copper cards into first and third positions of array.
	state.deck[0][4] = village;
	state.deck[0][2] = embargo;
	
	//Check the state of the game prior to calling Adventurer card.
	assertTrue(state.handCount[currentPlayer] == 5);
	assertTrue(state.deckCount[currentPlayer] == 5);
	
	//Call Adventurer card.
	int temphand[MAX_HAND];
	result = playAdventurer(&state, 0, currentPlayer, temphand, 0);
	
	//Check that return value of Adventurer card is correct.
	assertTrue(result == 0);
	
	//Check that handCount and deckCount incremented/decremented as expected.
	assertTrue(state.handCount[currentPlayer] == 6);
	assertTrue(state.deckCount[currentPlayer] == 1);

	printf("End Adventurer Card Test 2.\n\n");
	return 0;
}


//This function tests the Adventurer card if its implementation is OUTSIDE of cardEffect().
//It tests if there are only non-treasure cards in the deck array.
int TestAdventurer_card4() {
	
	printf("Begin Adventurer Card Test 2: tests implementation OUTSIDE of cardEffect() (Part 4).\n");
	
	struct gameState state;		//Create gameState object.
	int currentPlayer = 0;		//Set currentPlayer to 0.
	int result = 0;				//Set result to 0.
	int i = 0;
	
	//Initialize beginning cards.
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
		
	//Set all cards to copper.
	for (i = 0; i < 5; i++) {
		state.deck[0][i] = copper;
	}
	
	//Insert non-copper card into second, third, and fourth positions of array.
	state.deck[0][1] = village;
	state.deck[0][2] = embargo;
	state.deck[0][3] = cutpurse;
	
	//Check the state of the game prior to calling Adventurer card.
	assertTrue(state.handCount[currentPlayer] == 5);
	assertTrue(state.deckCount[currentPlayer] == 5);
	
	//Call Adventurer card.
	int temphand[MAX_HAND];
	result = playAdventurer(&state, 0, currentPlayer, temphand, 0);	
	//Check that return value of Adventurer card is correct.
	assertTrue(result == 0);
	
	//Check that handCount and deckCount incremented/decremented as expected.
	assertTrue(state.handCount[currentPlayer] == 6);
	assertTrue(state.deckCount[currentPlayer] == 0);

	printf("End Adventurer Card Test 2.\n\n");
	return 0;
}


//This is the main function, it calls the relevant functions to test the Village card.
int main() {
	
	TestCardEffectAdventurer1();
	TestCardEffectAdventurer2();
	TestCardEffectAdventurer3();
	TestCardEffectAdventurer4();
	TestAdventurer_card1();
	TestAdventurer_card2();
	TestAdventurer_card3();
	TestAdventurer_card4();
	return 0;
}