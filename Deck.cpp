#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <chrono>

using namespace std;

#include "Deck.h"
#include "Card.h"

Deck::Deck()
{
}

Deck::Deck(bool randomize)
{
	//put all cards in bet
	if(randomize)
	{
		vector<Card> cards;
		cards.push_back(Card("A"));
		cards.push_back(Card("2"));
		cards.push_back(Card("3"));
		cards.push_back(Card("4"));
		cards.push_back(Card("5"));
		cards.push_back(Card("6"));
		cards.push_back(Card("7"));
		cards.push_back(Card("8"));
		cards.push_back(Card("9"));
		cards.push_back(Card("10"));
		cards.push_back(Card("J"));
		cards.push_back(Card("Q"));
		cards.push_back(Card("K"));

		vector<int> cardsGiven;
		cardsGiven.push_back(4);
		cardsGiven.push_back(4);
		cardsGiven.push_back(4);
		cardsGiven.push_back(4);
		cardsGiven.push_back(4);
		cardsGiven.push_back(4);
		cardsGiven.push_back(4);
		cardsGiven.push_back(4);
		cardsGiven.push_back(4);
		cardsGiven.push_back(4);
		cardsGiven.push_back(4);
		cardsGiven.push_back(4);
		cardsGiven.push_back(4);
		
		int randomNumIndex = 0;
		srand(chrono::high_resolution_clock::now().time_since_epoch().count());
		for (int i = 0; i < cards.size()*4; ++i)
		{
			randomNumIndex = (rand() % cards.size()-1) + 1;
			//cout << "randomNumIndex: " << randomNumIndex << endl;
			if(cardsGiven[randomNumIndex] != 0)
			{
				//cout << cards[randomNumIndex].Name() << " ";
				m_Deck.push(cards[randomNumIndex]);
				cardsGiven[randomNumIndex]--;
			}
			else
			{
				//cout << "Out" << endl;
				i--;
			}
		}

		//cout << m_Deck.size() << endl;
	}
	else
	{
		//read in from a file
	}
}

bool Deck::isEmpty()
{
	return m_Deck.empty();
}

Card Deck::GetTopCard()
{
	Card ret = m_Deck.front();
	m_Deck.pop();
	return ret; 
}
