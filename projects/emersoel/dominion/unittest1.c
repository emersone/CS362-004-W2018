/* -----------------------------------------------------------------------
 * Name: Elizabeth Emerson
 * Filename: unittest1.c
 * Class: CS 362
 * Assignment: Assignment 3
 * Date: 4 Feb 2018
 * Notes: This is for the kingdomCards() function.
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
		printf("Success! All works as expected.\n");
		return 1;
	}
	
	printf("Fail! There is a bug in your code.\n");
	return 0;
}

//Tests the kingdomCards() function.
int testKingdomCards() {
	
	//Expected array
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int *arr;
	int i;
	
	//Initialize beginning cards.
	arr = kingdomCards(adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy);
	
	for(i=0; i < 10; i++) {
		assertTrue(arr[i] == k[i]);
	}
	return 0;
}


//This is the main function.
int main() {
	testKingdomCards();	
	return 0;
}