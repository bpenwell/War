#include <iostream>
#include <fstream>
#include <algorithm>
#include "Deck.h"
#include "Player.h"
#include "Card.h"
using namespace std;

const int DECKSIZE = 52;
const int NUMPLAYERS = 2;

string SimulateGame(Player& p1, Player& p2, int& rounds);
int Begin();
vector<string> PlayRound(Player& p1, Player& p2);
int main()
{
	string input;
	do{
		cout << "+--------------------------------------+" << endl <<
		"| Select 1 to start a new game         |" << endl <<
		"| Select 2 to simulate 1,000 games     |" << endl <<
		"| Select 3 to simulate 100,000 games   |" << endl <<
		"| Select 4 to simulate 1,000,000 games |" << endl <<
		"| Select 5 to complete an ongoing game |" << endl <<
		"| Select -1 to quit                    |" << endl <<
		"+--------------------------------------+" << endl;

		cin >> input;

		if(input == "1")
		{
			Begin();
		}
		else if(input == "2")
		{
			int avgRoundsPerGame = 0, max = 0, min = 1000000, NumGamesToPlay = 1000;
			for (int i = 0; i < NumGamesToPlay; ++i)
			{
				cout << i << endl;
				int gameResult = Begin();
				if(max < gameResult)
				{
					max = gameResult;
				}

				if(min > gameResult)
				{
					min = gameResult;
				}

				avgRoundsPerGame += gameResult;
				cout << endl;
			}

			cout << "Average rounds to win a game (over " << NumGamesToPlay << "games) is " << (float)(avgRoundsPerGame/NumGamesToPlay) << endl;
			cout << "Min: " << min << endl;
			cout << "Max: " << max << endl;
		}
		else if(input == "3")
		{
			int avgRoundsPerGame = 0, max = 0, min = 1000000, NumGamesToPlay = 100000;
			for (int i = 0; i < NumGamesToPlay; ++i)
			{
				cout << i << endl;
				int gameResult = Begin();
				if(max < gameResult)
				{
					max = gameResult;
				}

				if(min > gameResult)
				{
					min = gameResult;
				}

				avgRoundsPerGame += gameResult;
				cout << endl;
			}

			cout << "Average rounds to win a game (over " << NumGamesToPlay << "games) is " << (float)(avgRoundsPerGame/NumGamesToPlay) << endl;
			cout << "Min: " << min << endl;
			cout << "Max: " << max << endl;
		}
		else if(input == "4")
		{
			long long int avgRoundsPerGame = 0;
			int max = 0, min = 1000000, NumGamesToPlay = 1000000;
			for (int i = 0; i < NumGamesToPlay; ++i)
			{
				cout << i << endl;
				int gameResult = Begin();
				if(max < gameResult)
				{
					max = gameResult;
				}

				if(min > gameResult)
				{
					min = gameResult;
				}

				avgRoundsPerGame += gameResult;
				cout << endl;
			}

			cout << "Average rounds to win a game (over " << NumGamesToPlay << "games) is " << (float)(avgRoundsPerGame/NumGamesToPlay) << endl;
			cout << "Min: " << min << endl;
			cout << "Max: " << max << endl;
		}
		else if(input == "5")
		{
			Player P1, P2;
			string inputString, name;

			cout << "--Enter P1's deck in order (i.e. A,2,3,4,5,6,7,8,9,10,J,Q,K) seperated by commas, with a period at the end. Enter when complete." << endl;

			cin >> inputString;

			for (int i = 0; i < inputString.size(); ++i)
			{
				if(inputString[i] == ',' || inputString[i] == '.')
				{
					cout << "card registered: " << name << endl;
					Card newCard(name);
					P1.TakeCards(newCard);

					name = "";
				}
				else
				{
					name += inputString[i];
				}
			}

			cout << "--Enter P2's deck in order (i.e. A,2,3,4,5,6,7,8,9,10,J,Q,K) seperated by commas. Enter when complete." << endl;
			
			cin >> inputString;

			for (int i = 0; i < inputString.size(); ++i)
			{
				if(inputString[i] == ',' || inputString[i] == '.')
				{
					cout << "card registered: " << name << endl;
					Card newCard(name);
					P2.TakeCards(newCard);
					
					name = "";
				}
				else
				{
					name += inputString[i];
				}
			}

			int rounds = 0;
			string Winner = SimulateGame(P1, P2, rounds);
			cout << Winner << " wins after " << rounds << " rounds!" << endl;
		}

	}while(input != "-1");
}

int EvaluateFlip(Card P1CardPulled, Card P2CardPulled)
{
	//cout << "P1CardPulled: " << P1CardPulled.Value() << endl;
	//cout << "P2CardPulled: " << P2CardPulled.Value() << endl;
	if(P1CardPulled.Value() > P2CardPulled.Value())
	{
		return 1;
	}
	else if(P1CardPulled.Value() < P2CardPulled.Value())
	{
		return 2;
	}
	else
	{
		return 0;
	}

}

int Begin()
{
	Deck Dealer(true);

	Player ben;
	Player jason;
	int counter=1, num = 0;
	
	//Reset file
	remove("GameReceipts.log");

	while(!Dealer.isEmpty())
	{
		//cout << counter << endl;
		if(counter == 1)
		{
			ben.TakeCards(Dealer.GetTopCard());
		}
		else if(counter == 2)
		{
			jason.TakeCards(Dealer.GetTopCard());
		}
		counter = counter % NUMPLAYERS + 1;
		num++;
	}
	//cout << "NUM=" << num << endl;
	//cout << "P1" << endl;
	ben.PrintCards();
	//cout << "P2" << endl;
	jason.PrintCards();

	int rounds = 0;
	string Winner = SimulateGame(ben, jason, rounds);
	cout << Winner << " wins after " << rounds << " rounds!" << endl;

	return rounds;
}

vector<Card> PlayRound(Player& p1, Player& p2, int round, int& winner)
{
	//ofstream fout;
	//fout.open("GameReceipts.log", std::ofstream::out | std::ofstream::app);
	vector<Card> Pool;
	int evaluation = -1, warRound = 1;
	Card P1CardPulled, P2CardPulled;
	do
	{
		if(p1.DeckSize() != 0)
		{
			P1CardPulled = p1.PlayCard();
			Pool.push_back(P1CardPulled);
		}

		if(p2.DeckSize() != 0)
		{
			P2CardPulled = p2.PlayCard();
			Pool.push_back(P2CardPulled);
		}

		//fout << "Round " << round << ": " << P1CardPulled.Name() << " | " << P2CardPulled.Name() << endl;

		evaluation = EvaluateFlip(P1CardPulled, P2CardPulled);

		if(evaluation == 1)
		{
			//fout << "P1 WIN" << endl;
			winner = 1;
			break;
		}
		else if(evaluation == 2)
		{
			//fout << "P2 WIN" << endl;
			winner = 2;
			break;
		}
		else
		{
			//fout << "Its time for WAR (round " << warRound << ")!" << endl;
			warRound++;
		}

	}while(evaluation == 0);
	//fout.close();

	random_shuffle(Pool.begin(), Pool.end());

	return Pool;
}

string SimulateGame(Player& p1, Player& p2, int& rounds)
{
	rounds++;

	string Winner = "";
	int winTracker = 0;
	//ofstream fout;

	while(p1.DeckSize() != 0 && p2.DeckSize() != 0)
	{
		vector<Card> awardedCards = PlayRound(p1, p2, rounds, winTracker);
		//fout.open("GameReceipts.log", std::ofstream::out | std::ofstream::app);
		if(winTracker == 1)
		{
			//fout << " -> Player 1 wins." << endl;
			p1.TakeCards(awardedCards);
		}
		else if(winTracker == 2)
		{
			//fout << " -> Player 2 wins." << endl;
			p2.TakeCards(awardedCards);
		}
		//fout << "p1.DeckSize(): " << p1.DeckSize() << endl;
		p1.PrintCards();
		//fout << "p2.DeckSize(): " << p2.DeckSize() << endl;
		p2.PrintCards();
		//fout << endl;
		rounds++;
		//fout.close();
	}

	if(p1.DeckSize() == 0)
	{
		Winner = "P2";
	}
	else
	{
		Winner = "P1";
	}

	return Winner;
}
