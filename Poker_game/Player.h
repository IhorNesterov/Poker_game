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
	}

public:
	void setcard(Card* card_1,Card* card_2);
	void setid(int id);
	void setmoney(int money);
	void increasemoney(int money);


};

