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

int Player::getmoney(void)
{
	return *this->money;
}

int Player::getid(void)
{
	return *this->id;
}

void Player::setname(string nam)
{
	if (&nam != NULL)
	{
		cout << "Set name for " << *id << endl;
		this->name = nam;
	}
	else
	{
		cout << "name is false or NULL pointer\n";
	}
}

void Player::setcard(Card (*card_1), Card (*card_2))
{
	if (card_1 != nullptr && !card_1->getbusy())
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

Card* Player::getcard(int pos)
{
	switch (pos)
	{
	case 1:
		return this->firstcard;
		break;
	case 2:
		return this->secondcard;
		break;
	}
}

void Player::setcombinationpower(int power)
{
	if (power > 0)
	{
		*this->combinationpower = power;
	}
	else
	{
		throw "Combination power out of range!\n";
	}
}

int Player::getcombinationpower(void)
{
	return *this->combinationpower;
}

Action Player::action(void)
{
	uint8_t key;
	Action action;
	cout << "Choose your action" << endl;
	cout << "Q - Call" << endl;
	cout << "W - Check" << endl;
	cout << "E - Fold" << endl;
	cout << "R - Raise" << endl;
	cin >> key;
	switch (key)
	{
	case 'Q':
		action = Call;
		break;
	case 'W':
		action = Check;
		break;
	case 'E':
		action = Fold;
		break;
	case 'R':
		action = Raise;
		break;
	}
	return action;
}