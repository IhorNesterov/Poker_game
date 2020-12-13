// Poker_game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Card.h"
#include "Player.h"
#include "Table.h"
#include <algorithm>
#include <iostream>
#include "Game.h"

int Player::playerscount = 0;
int Card::cardscount = 0;
int f;
int x;



int main()
{
    try
    {     
        Card* cards = new Card[52];
        Player* players = new Player[6];
        Table* table = new Table;
        Game* game = new Game;

        game->createstack(cards);

            std::cout << "Starting the game!\n";

            game->getcardsPlayers(cards, players);

            table->setplayers(players);
            table->setmoney(0, 200, 400);

            game->getcardsTable(cards, table);

            for (int i = 0; i < players[0].getplayerscount(); i++)
            {
                cout << players[i];
            }

            cout << table[0];
            game->freecards(cards);
            cout << "End game\n";
        }
    
    catch (const char* exnum)
    {
        cout << exnum;
    }
 } 
 

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
