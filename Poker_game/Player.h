#pragma once
#include "Card.h"

enum Combination{highcard,pair,twopair,set,street,flash,fullhaus,kare,streetflash};
enum Playerstate{Dealer,smallbet,largebet,usual};

class Player
{
private:
	int* money;
	int* id;
	Card* firstcard;
	Card* secondcard;
	int* combinationpower;
	enum Combination* combination;
	enum Playerstate* state;
	void init_memory(void) //function for dynamic allocate memory
	{
		combination = new enum Combination;
		state = new enum Playerstate;
		money = new int;
		id = new int;
		combinationpower = new int;
		firstcard = new Card;
		secondcard = new Card;
		
	}

public:
	static int playerscount;
	Player()
	{
		init_memory();
		cout << "constructor" << endl;
	}
	Player(Card* first, Card* second,int money)
	{
		init_memory();
		setcard(first,second);
		setmoney(money);
		Player::playerscount++;
		*id = getplayerscount();
		cout << "constructor2" << endl;
	}
	friend std::ostream& operator << (std::ostream& str, const Player& his)
	{
		str << "Your player id:" << *his.id << "\n";
		str << "Your cards:\n";
		str << *his.firstcard;
		str << *his.secondcard;
		str << "Your money:" << *his.money << "\n";
		return str;
	}
	void setcard(Card* card_1,Card* card_2);
	void setid(int id);
	void setmoney(int money);
	void increasemoney(int money);
	int getplayerscount(void);

};

