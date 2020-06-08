#pragma once
#include "Card.h"
#include "Player.h"

class Table
{
private:
	Player* players;
	Card* tablecards;
	int* money;
	int* lowbet;
	int* highbet;
	void init_memory(void)
	{ 
		money = new int;
		lowbet = new int;
		highbet = new int;
	}

public:

	Table(Player (*player), Card(*card), int money, int lowbet)
	{
		init_memory();
		this->players = player;
		this->tablecards = card;
		*this->money = money;
		*this->lowbet = lowbet;
		*this->highbet = lowbet * 2;
	}
	friend std::ostream& operator << (std::ostream& str, const Table& his)
	{
		str << "Cards on the table:\n";
		str << his.tablecards[8] << his.tablecards[9] << his.tablecards[10] << his.tablecards[11] << his.tablecards[12];
		return str;
	}
};
