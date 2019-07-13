#include <iostream>

using namespace std;

#include "Card.h"

Card::Card(string name)
{
	m_Name = name;
	m_Value = StringToValue(name);
}
int Card::Value() const
{
	return m_Value;
}
string Card::Name() const
{
	return m_Name;
}
Card& Card::operator=(Card const& copy)
{
	if(this != &copy)
	{
		m_Name = copy.Name();
		m_Value = copy.Value();
	}
	return *this;	
}
int Card::StringToValue(string card)
{
	if(card == "A")
	{
		return 14;
	}
	else if(card == "2")
	{
		return 2;
	}
	else if(card == "3")
	{
		return 3;
	}
	else if(card == "4")
	{
		return 4;
	}
	else if(card == "5")
	{
		return 5;
	}
	else if(card == "6")
	{
		return 6;
	}
	else if(card == "7")
	{
		return 7;
	}
	else if(card == "8")
	{
		return 8;
	}
	else if(card == "9")
	{
		return 9;
	}
	else if(card == "10")
	{
		return 10;
	}
	else if(card == "J")
	{
		return 11;
	}
	else if(card == "Q")
	{
		return 12;
	}
	else if(card == "K")
	{
		return 13;
	}

	return -1;
}