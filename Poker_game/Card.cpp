#include "Card.h"

void Card::setsuit(enum suit suit)
{
	if (suit >= 0 && suit < 4)
	{
		*this->cardsuit = suit;
	}
}

void Card::setvalue(enum cardvalue val)
{
	if (val >= 0 && val < 14)
	{
		*this->value = val;
	}
}

void Card::setdecent(int dec)
{
	if (dec >= 0 && dec < 55)
	{
		*this->decent = dec;
	}
}

enum suit Card::getsuit()
{
	return *this->cardsuit;
}

enum cardvalue Card::getvalue()
{
	return *this->value;
}

int Card::getdecent()
{
	return *this->decent;
}