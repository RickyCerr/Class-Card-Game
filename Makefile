output: drive.o drive.o game.o player.o hand.o cards.o deck.o
		g++ drive.o game.o player.o hand.o deck.o cards.o -o output

drive.o: drive.cpp
		g++ -c drive.cpp

game.o: game.cpp game.h
		g++ -c game.cpp

player.o: player.cpp player.h
		g++ -c player.cpp

hand.o: hand.cpp hand.h
		g++ -c hand.cpp

deck.o: deck.cpp deck.h
		g++ -c deck.cpp

cards.o: cards.cpp card.h
		g++ -c cards.cpp

clean:
	rm -f *.o $(EXE_FILE)