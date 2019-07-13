#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

#include "Player.h"
#include "Card.h"

void Player::TakeCards(vector<Card> cards)
{
	for (int i = 0; i < cards.size(); ++i)
	{
		m_Deck.push(cards[i]);
	}
}

void Player::TakeCards(Card card)
{
	m_Deck.push(card);
}

int Player::DeckSize()
{
	return m_Deck.size();
}

Card Player::PlayCard()
{
	Card card = m_Deck.front();
	m_Deck.pop();
	return card;
}

void Player::PrintCards()
{
	ofstream fout;
	//fout.open("GameReceipts.log", std::ofstream::out | std::ofstream::app);

	queue<Card> copy = m_Deck;
	//fout << "PRINTING: ";
	while(!copy.empty())
	{
		//fout << copy.front().Name() << " ";
		copy.pop();
	}
	fout << endl;

	fout.close();
}