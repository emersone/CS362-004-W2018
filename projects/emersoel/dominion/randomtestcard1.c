//Elizabeth Emerson
//CS 362
//Feb 18 2018
//Assignment 4
//Smithy card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "rngs.h"
#include <time.h>

//Takes in a Boolean; if true, prints success message, else prints failure message.
int assertTrue(int x) {
	
	if (x == 1) {
		printf("Success! All works as expected.\n");
		return 1;
	}
	
	printf("Fail! There is a bug in your code.\n");
	return 0;
}

//This function tests smithy_card().
int check_smithy(int p, struct gameState *G, int handPos) {
	
	//Declaring variables to keep track of initial state of the game.
	int handCount = G->handCount[p];
	int deckSize = G->deckCount[p];
	int discardSize = G->discardCount[p];
	
	//Call Smithy card.
	smithy_card(G, p, handPos);
	
	if(assertTrue(handCount+2 == G->handCount[p]))
		printf("You have added 2 to handCount.\n");
	
	if(assertTrue(deckSize-3 == G->deckCount[p]))
		printf("You have subtracted 3 to discardCount.");
	
	if(assertTrue(discardSize+1 == G->discardCount[p]))
		printf("You have added 1 to discardCount.\n");
}


//This is the main function.
int main() {
	
	//Declare relevant variables.
	int j, i, n, r, p, deckCount, discardCount, handCount, handPos;

	//Choose which cards go in the deck.
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};

	struct gameState G;

	printf ("Testing smithy_card.\n");
	printf ("RANDOM TESTS.\n");	
	
   	//Declare time to use for generator.
    time_t t;
   
   //Intializes random number generator.
   srand((unsigned) time(&t));
	
	for (n = 0; n < 200; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = rand() % 256;
		}
    
		//Get random player.
		p = rand() % 2;
		
		//Get random deck count.
		G.deckCount[p] = (rand() % (MAX_DECK -10)) +10;	

		for (i = 0; i < G.deckCount[p]; i++) {
			
			//Choose a random card for k to put in the deck.
			G.deck[p][i] = k[rand() % 10];
		}
		
		//Get random hand count.
		G.handCount[p] = rand() % (MAX_HAND-(G.deckCount[p]-1))+1;
		
		for (i = 0; i < G.handCount[p]; i++) {
			
			//Choose a random card for k to put in the hand.
			G.hand[p][i] = k[rand() % 10];
		}
		
		G.discardCount[p] = MAX_DECK - G.deckCount[p] - G.handCount[p];
		
		for (i = 0; i < G.discardCount[p]; i++) {
			
			//Choose a random card for k to put in the discard pile.
			G.discard[p][i] = k[rand() % 10];
		}
		
		//Get random hand position.
		handPos = rand() % G.handCount[p];
		
		//Set additional gameState variable.
		G.playedCardCount = 0;
		
		//Call check_smithy to check Smithy card.
		check_smithy(p, &G, handPos);
	}
  
	return 0;
}