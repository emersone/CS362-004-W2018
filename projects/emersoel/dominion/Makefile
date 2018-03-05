CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/


testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

initGame.o:
	gcc -c initGame.c -g  $(CFLAGS)

test1: cardtest1.c dominion.o rngs.o initGame.o
	gcc  -o test1 -g  cardtest1.c dominion.o rngs.o initGame.o $(CFLAGS)

test2: cardtest2.c dominion.o rngs.o initGame.o
	gcc -o test2 -g cardtest2.c dominion.o rngs.o initGame.o $(CFLAGS)

test3: cardtest3.c dominion.o rngs.o initGame.o
	gcc -o test3 -g cardtest3.c dominion.o rngs.o initGame.o $(CFLAGS)

test4: cardtest4.c dominion.o rngs.o initGame.o
	gcc -o test4 -g cardtest4.c dominion.o rngs.o initGame.o $(CFLAGS)

unit1: unittest1.c dominion.o rngs.o initGame.o
	gcc -o unit1 -g unittest1.c dominion.o rngs.o initGame.o $(CFLAGS)

unit2: unittest2.c dominion.o rngs.o initGame.o 
	gcc -o unit2 -g unittest2.c dominion.o rngs.o initGame.o $(CFLAGS)

unit3: unittest3.c dominion.o rngs.o
	gcc -o unit3 -g unittest3.c dominion.o rngs.o initGame.o $(CFLAGS)

unit4: unittest4.c dominion.o rngs.o initGame.o 
	gcc -o unit4 -g unittest4.c dominion.o rngs.o initGame.o $(CFLAGS)
	
tests: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o rngs.o initGame.o 
	rm -f *.gcda
	echo "unittest1.c:" > unittestresults.out
	gcc -o unit1 -g unittest1.c dominion.o rngs.o initGame.o $(CFLAGS)
	unit1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	rm -f *.gcda
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -o unit2 -g unittest2.c dominion.o rngs.o initGame.o $(CFLAGS)
	unit2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	rm -f *.gcda
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -o unit3 -g unittest3.c dominion.o rngs.o initGame.o $(CFLAGS)
	unit3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	rm -f *.gcda
	
	echo "unittest4.c:" >> unittestresults.out
	gcc -o unit4 -g unittest4.c dominion.o rngs.o initGame.o $(CFLAGS)
	unit4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	rm -f *.gcda
	
	echo "cardtest1.c:" >> unittestresults.out
	gcc  -o test1 -g  cardtest1.c dominion.o rngs.o initGame.o $(CFLAGS)
	test1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	rm -f *.gcda
	
	echo "cardtest2.c:" >> unittestresults.out
	gcc -o test2 -g cardtest2.c dominion.o rngs.o initGame.o $(CFLAGS)
	test2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	rm -f *.gcda
	
	echo "cardtest3.c:" >> unittestresults.out
	gcc -o test3 -g cardtest3.c dominion.o rngs.o initGame.o $(CFLAGS)
	test3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	rm -f *.gcda
	
	echo "cardtest4.c:" >> unittestresults.out
	gcc -o test4 -g cardtest4.c dominion.o rngs.o initGame.o $(CFLAGS)
	test4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	rm -f *.gcda
	
all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe test1 test2 test3 test4 unit1 unit2 unit3 unit4
