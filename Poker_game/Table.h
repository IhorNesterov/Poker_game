#pragma once
#include "Card.h"
#include "Player.h"

class Table
{
private:
	Player* players;
	Card* firstcard;
	Card* secondcard;
	Card* thirdcard;
	Card* fourcard;
	Card* fivecard;
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
	Table()
	{
		init_memory();
	}

	Table(Player (*player), Card(*firstcard), Card(*secondcard), Card(*thirdcard), Card(*fourcard), Card(*fivecard), int money, int lowbet)
	{
		init_memory();
		this->players = player;
		this->firstcard = firstcard;
		this->secondcard = secondcard;
		this->thirdcard = thirdcard;
		this->fourcard = fourcard;
		this->fivecard = fivecard;
		*this->money = money;
		*this->lowbet = lowbet;
		*this->highbet = lowbet * 2;
	}

	friend std::ostream& operator << (std::ostream& str, const Table& his)
	{
		str << "Cards on the table:\n";
		str << *his.firstcard << *his.secondcard << *his.thirdcard << *his.fourcard << *his.fivecard;
		str << "Money on the table:" << endl;
		str << *his.money << endl;
		return str;
	}

	void setcard(Card(*card), int num);
	void setmoney(int money, int lowbet, int highbet);
	void setmoney(int money);
	void increasemoney(int moneyincrease);
    void setplayers(Player(*players));

	int getmoney();


};
