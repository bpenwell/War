#ifndef DECK_H
#define DECK_H

#include <queue>
#include <string>
#include "Card.h"

using namespace std;

class Deck
{
public:
	Deck();
	Deck(bool randomize);
	bool isEmpty();
	Card GetTopCard();
private:
	queue<Card> m_Deck;
    int randomizeSeed;
};

#endif
