#pragma once
#include "Card.h"
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include <set>
#include <iostream>
#include <string>
enum Combination{highcard,pair,twopair,set,street,flash,fullhaus,kare,streetflash};
enum Playerstate{Dealer,smallbet,largebet,usual};
enum Action{Fold,Call,Raise,Check};



class Player
{
private:
	int* money;
	int* id;
	string name;
	Card* firstcard;
	Card* secondcard;
	int* combinationpower;
	enum Combination* combination;
	enum Playerstate* state;
	bool* live;
	void init_memory(string nam) //function for dynamic allocate memory
	{
		live = new bool;
		*this->live = true;
		combination = new enum Combination;
		state = new enum Playerstate;
		money = new int;
		id = new int;
		combinationpower = new int;
		name = nam;
	}
	
public:
	static int playerscount;
	Player()
	{
		init_memory("Bot player");
		Player::playerscount++;
		*id = getplayerscount();
		string nam = "Bot player ";
		cout << nam << endl;
		setname(nam);
	}

	Player(Card (*first), Card (*second),int money)
	{
		init_memory("Bot player");
		setcard(first,second);
		setmoney(money);
		Player::playerscount++;
		*id = getplayerscount();
		string nam = "Bot player " + *id;
		cout << nam << endl;
		setname(nam);
	}

	friend std::ostream& operator << (std::ostream& str, const Player& his)
	{
		str << "Your name:" << his.name << "\n";
		str << "Your cards:\n";
		str << *his.firstcard;
		str << *his.secondcard;
		str << "Your money:" << *his.money << "\n";
		if (*his.live)
		{
			str << "You turn\n";
		}
		else
		{
			str << "Your game is over! See you next time!\n";
		}
		return str;
	}
	void setname(string nam);
	void setcard(Card (*card_1),Card (*card_2));
	void setid(int id);
	void setmoney(int money);
	int  getmoney(void);
	void increasemoney(int money);
	void setlive(void);
	bool getlive(void);
	int getid(void);
	int getplayerscount(void);
	Action action(void);
};

