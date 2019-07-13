#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card
{
public:
	Card() {m_Value = 0;
			m_Name = "";
		   };
	Card(string name);
	int Value() const;
	Card& operator=(Card const& copy);
	string Name() const;
	int StringToValue(string card);
private:
	int m_Value;
	string m_Name;
};

#endif