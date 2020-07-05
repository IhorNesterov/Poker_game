#pragma once

#include "Card.h"
#include "Player.h"
#include "Table.h"
#include <algorithm>
#include <iostream>
class Game
{

public:
	int getRandomNumber(int min, int max);
	void getcardsPlayers(Card(*cards), Player(*players));
	void getcardsTable(Card(*cards), Table(*table));
	void freecards(Card(*cards));
	void createstack(Card(*cards));
	void getmoneyfromplayer(Player(*player), Table(*table),int money);
	void getmoneytoplayer(Player(*player), Table(*table), int money);
};