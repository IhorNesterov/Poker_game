#pragma once
#include "Card.h"
#include "Player.h"

class Table
{
private:
	Player* players;
	Card* cards;
	int* money;
	int* lowbet;
	int* highbet;
	void init_memory(void)
	{ 
		money = new int;
		lowbet = new int;
		highbet = new int;
		cards = new Card[5];
	}

public:
	Table()
	{
		init_memory();
	}

	Table(Player (*player), Card(*cards), int money, int lowbet)
	{
		init_memory();
		this->players = player;
		this->cards = cards;
		*this->money = money;
		*this->lowbet = lowbet;
		*this->highbet = lowbet * 2;
	}

	friend std::ostream& operator << (std::ostream& str, const Table& his)
	{
		str << "Cards on the table:\n";
		for (int i = 0; i < 5; i++)
		{
			str << his.cards[i];
		}
		str << "Money on the table:" << endl;
		str << *his.money << endl;
		return str;
	}

	void setcard(Card *card, int num);
	void setmoney(int money, int lowbet, int highbet);
	void setmoney(int money);
	void increasemoney(int moneyincrease);
    void setplayers(Player(*players));
    int getmoney();
	Card getcard(int pos);

};
