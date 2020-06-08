#pragma once
#include "Card.h"
#include "Player.h"

class Table
{
private:
	Player* players[6];
	Card* tablecards[5];
	int* money;
	int* lowbet;
	int* highbet;
	void init_memory(void);

public:
};
