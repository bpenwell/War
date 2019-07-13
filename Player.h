#ifndef PLAYER_H
#define PLAYER_H

#include <queue>
#include <string>
#include "Card.h"

using namespace std;

class Player
{
public:
	void TakeCards(vector<Card> cards);
	void TakeCards(Card card);
	void PrintCards();
	int DeckSize();
	Card PlayCard();
private:
	queue<Card> m_Deck;
};

#endif