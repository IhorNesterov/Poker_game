#include "Player.h"

void Player::setmoney(int money)
{
	if (money > 0)
	{
		*this->money = money;
	}
	else
	{
		throw "Money is out of range\n";
	}
}

void Player::setcard(Card (*card_1), Card (*card_2))
{
	if (card_1 != nullptr && !card_1->getbusy() && !card_2->getbusy())
	{
		this->firstcard = card_1;
		card_1->setbusy();
		if (card_2 != nullptr && !card_2->getbusy())
		{
			this->secondcard = card_2;
			card_2->setbusy();
		}
	}
	else 
	{
		throw "Card for player is busy\n";
	}
}

void Player::setid(int id)
{
	if (id > 0)
	{
		*this->id = id;
	}
	else
	{
		throw "id is not in range\n";
	}
}

void Player::increasemoney(int money)
{
	if (money > 0)
	{
		*this->money += money;
	}
	if (money < 0)
	{
		if (*this->money > money)
		{
			*this->money += money;
		}
		else
		{
			throw "You game is over\n";
		}
	}
}

int Player::getplayerscount(void)
{
	return Player::playerscount;
}

void Player::setlive(void)
{
	*this->live = false;
}

bool Player::getlive(void)
{
	return *this->live;
}