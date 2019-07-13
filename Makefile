all: main

main: clean Deck.o Card.o Player.o
	g++ main.cpp Deck.cpp Card.cpp Player.cpp -o War

Deck.o:
	g++ -c Deck.cpp

Card.o:
	g++ -c Card.cpp

Player.o:
	g++ -c Player.cpp

clean:
	rm -rf *o main