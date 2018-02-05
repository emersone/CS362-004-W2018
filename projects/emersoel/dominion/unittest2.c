/* -----------------------------------------------------------------------
 * Name: Elizabeth Emerson
 * Filename: unittest2.c
 * Class: CS 362
 * Assignment: Assignment 3
 * Date: 4 Feb 2018
 * Notes: This is for the fullDeckCount() function.
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

//Tests the fullDeckCount() function.
//Disc: 0
//Deck: 0
//Hand: 0 
int testFullDeckCount1() {
	
	struct gameState state;		//Create gameState object.
	int result;
	
	//Initialize beginning cards.
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initializeGame(2, k, 567, &state);
		
	result = fullDeckCount(0, adventurer, &state);

	assertTrue(result==0);
	
	return 0;
}

//Tests the fullDeckCount() function.
//Disc: 0
//Deck: 0
//Hand: 1 
int testFullDeckCount2() {
	
	struct gameState state;		//Create gameState object.
	int result;
	
	//Initialize beginning cards.
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	state.hand[0][0] = adventurer;
	
	result = fullDeckCount(0, adventurer, &state);

	assertTrue(result==1);
	
	return 0;
}

//Tests the fullDeckCount() function.
//Disc: 0
//Deck: 1
//Hand: 0 
int testFullDeckCount3() {
	
	struct gameState state;		//Create gameState object.
	int result;
	
	//Initialize beginning cards.
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	state.deck[0][0] = adventurer;
	
	result = fullDeckCount(0, adventurer, &state);

	assertTrue(result==1);
	
	return 0;
}

//Tests the fullDeckCount() function.
//Disc: 1
//Deck: 0
//Hand: 0 
int testFullDeckCount4() {
	
	struct gameState state;		//Create gameState object.
	int result;
	
	//Initialize beginning cards.
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	state.discardCount[0]++;
	state.discard[0][0] = adventurer;

	result = fullDeckCount(0, adventurer, &state);

	assertTrue(result==1);
	
	return 0;
}

//Tests the fullDeckCount() function.
//Disc: 1
//Deck: 1
//Hand: 0 
int testFullDeckCount5() {
	
	struct gameState state;		//Create gameState object.
	int result;
	
	//Initialize beginning cards.
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	state.discardCount[0]++;
	state.discard[0][0] = adventurer;
	state.deck[0][0] = adventurer;

	result = fullDeckCount(0, adventurer, &state);

	assertTrue(result==2);
	
	return 0;
}

//Tests the fullDeckCount() function.
//Disc: 0
//Deck: 1
//Hand: 1 
int testFullDeckCount6() {
	
	struct gameState state;		//Create gameState object.
	int result;
	
	//Initialize beginning cards.
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	state.hand[0][0] = adventurer;
	state.deck[0][0] = adventurer;

	result = fullDeckCount(0, adventurer, &state);

	assertTrue(result==2);
	
	return 0;
}

//Tests the fullDeckCount() function.
//Disc: 1
//Deck: 0
//Hand: 1 
int testFullDeckCount7() {
	
	struct gameState state;		//Create gameState object.
	int result;
	
	//Initialize beginning cards.
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	state.discardCount[0]++;
	state.discard[0][0] = adventurer;
	state.hand[0][0] = adventurer;

	result = fullDeckCount(0, adventurer, &state);

	assertTrue(result==2);
	
	return 0;
}

//Tests the fullDeckCount() function.
//Disc: 1
//Deck: 1
//Hand: 1 
int testFullDeckCount8() {
	
	struct gameState state;		//Create gameState object.
	int result;
	
	//Initialize beginning cards.
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	state.discardCount[0]++;
	state.discard[0][0] = adventurer;
	state.hand[0][0] = adventurer;
	state.deck[0][0] = adventurer;

	result = fullDeckCount(0, adventurer, &state);

	assertTrue(result==3);
	
	return 0;
}




//Tests the fullDeckCount() function.
//Disc: 0
//Deck: 0
//Hand: 2 
int testFullDeckCount9() {
	
	struct gameState state;		//Create gameState object.
	int result;
	
	//Initialize beginning cards.
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	state.hand[0][0] = adventurer;
	state.hand[0][1] = adventurer;
	
	result = fullDeckCount(0, adventurer, &state);

	assertTrue(result==2);
	
	return 0;
}

//Tests the fullDeckCount() function.
//Disc: 0
//Deck: 2
//Hand: 0 
int testFullDeckCount10() {
	
	struct gameState state;		//Create gameState object.
	int result;
	
	//Initialize beginning cards.
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	state.deck[0][0] = adventurer;
	state.deck[0][1] = adventurer;
	
	result = fullDeckCount(0, adventurer, &state);

	assertTrue(result==2);
	
	return 0;
}

//Tests the fullDeckCount() function.
//Disc: 2
//Deck: 0
//Hand: 0 
int testFullDeckCount11() {
	
	struct gameState state;		//Create gameState object.
	int result;
	
	//Initialize beginning cards.
	int k[10] = {gold, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
		   
	//Call function to initialize the game with relevant parameters.
	initGame(2, k, 567, &state);
	
	state.discardCount[0]++;
	state.discard[0][0] = adventurer;
	state.discardCount[0]++;
	state.discard[0][1] = adventurer;

	result = fullDeckCount(0, adventurer, &state);

	assertTrue(result==2);
	
	return 0;
}




//This is the main function.
int main() {
	testFullDeckCount1();	
	testFullDeckCount2();
	testFullDeckCount3();
	testFullDeckCount4();
	testFullDeckCount5();	
	testFullDeckCount6();
	testFullDeckCount7();
	testFullDeckCount8();
	testFullDeckCount9();
	testFullDeckCount10();
	testFullDeckCount11();
	return 0;
}