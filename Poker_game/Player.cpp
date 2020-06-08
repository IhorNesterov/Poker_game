#include "Player.h"

void Player::setmoney(int money)
{
	if (money > 0)
	{
		*this->money = money;
	}
}

void Player::setcard(Card* card_1, Card* card_2)
{
	if (card_1 != nullptr && card_2 != nullptr)
	{
		this->firstcard = card_1;
		this->secondcard = card_2;
	}
}

void Player::setid(int id)
{
	if (id > 0)
	{
		*this->id = id;
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
			
		}
	}
}

int Player::getplayerscount(void)
{
	return Player::playerscount;
}