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

tests: 
	gcc -o test1 -g randomtestcard1.c dominion.c rngs.c $(CFLAGS)
	echo "randomtestcard1.c:" > randomtestcard1.out
	./test1 >> randomtestcard1.out
	gcov -b -f dominion.c >> randomtestcard1.out
	
	rm -f  *.gcov *.gcda *.gcno test1
	
	echo "randomtestcard2.c:" > randomtestcard2.out
	gcc -o test2 -g randomtestcard2.c dominion.c rngs.c $(CFLAGS)
	./test2 >> randomtestcard2.out
	gcov -b -f dominion.c >> randomtestcard2.out
	
	rm -f  .gcov *.gcda *.gcno test2
	
	echo "randomtestadventurer.c:" > randomtestadventurer.out
	gcc -o test3 -g randomtestadventurer.c dominion.c rngs.c $(CFLAGS)
	./test3 >> randomtestadventurer.out
	gcov -b -f dominion.c >> randomtestadventurer.out
	
	rm -f  *.gcov *.gcda *.gcno test3
	
	
all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe