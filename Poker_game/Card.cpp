#include "Card.h"

void Card::setsuit(enum suit suit)
{
	if (suit >= 0 && suit < 4)
	{
		*this->cardsuit = suit;
	}
	else
	{
		throw "suit is out of range\n";
	}
}

void Card::setvalue(enum cardvalue val)
{
	if (val >= 0 && val < 14)
	{
		*this->value = val;
	}
	else
	{
		throw "Cardvalue is out of range\n";
	}
}

void Card::setdecent(int dec)
{
	if (dec >= 0 && dec < 500)
	{
		*this->decent = dec;
	}
	else
	{
		throw "Decent is out of range\n";
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

void Card::setbusy(void)
{
	*this->busy = true;
}

bool Card::getbusy()
{
	return *this->busy;
}

void createstack(Card (*cards))
{
	int x = 0;
	enum cardvalue val;
	enum suit sui;
	for (int i = 0; i < 4; i++)
	{
		for (int u = 0; u < 13; u++)
		{
			sui = static_cast<suit>(i);
			val = static_cast<cardvalue>(u);
			cards[x] = { sui,val };
			x++;
		}
	}
}