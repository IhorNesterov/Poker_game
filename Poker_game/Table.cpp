#include "Table.h"


void Table::setcard(Card(*card), int num)
{
	if (card != NULL)
	{
		switch (num)
		{
		case 0:
			this->firstcard = card;
			break;
		case 1:
			this->secondcard = card;
			break;
		case 2:
			this->thirdcard = card;
			break;
		case 3:
			this->fourcard = card;
			break;
		case 4:
			this->fivecard = card;
			break;
		}
		card->setbusy();
	}
}

void Table::setmoney(int money, int lowbet, int highbet)
{
	if (money >= 0 && lowbet > 0 && highbet > 0)
	{
		*this->money = money;
		*this->lowbet = lowbet;
		*this->highbet = highbet;
	}
	else
	{
		throw "Value for set table money is false\n";
	}
}

void Table::setmoney(int money)
{
	if (money >= 0)
	{
		*this->money = money;
	}
	else
	{
	throw "Value for set table money is false\n";
	}
}

void Table::increasemoney(int moneyincrease)
{
	if (moneyincrease > 0)
	{
		cout << this->getmoney() << endl;
		this->setmoney(this->getmoney() + moneyincrease);
		cout << this->getmoney() << endl;
	}
	else if (moneyincrease < 0)
	{
		if ((this->getmoney() + moneyincrease) > 0)
		{
			this->setmoney(this->getmoney() + moneyincrease);
		}
		else
		{
			throw "Table money is left\n";
		}
	}
}

void Table::setplayers(Player(*players))
{
	this->players = players;
}

int Table::getmoney()
{
	return *this->money;
}