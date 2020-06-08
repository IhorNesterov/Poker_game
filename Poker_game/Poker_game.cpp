// Poker_game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Card.h"
#include "Player.h"
#include <iostream>

int Player::playerscount = 0;
int Card::cardscount = 0;

int main()
{
    Card cards[52];
    Player players[6];
    std::cout << "Hello World!\n";
    cards[0] = {pika,J};
    cards[1] = {chirva,K};
    cards[2] = {kresta,Q};
    cards[3] = {buba,A};
    cards[4] = { pika,K };
    cards[5] = { chirva,ten };
    cards[6] = { kresta,eight };
    cards[7] = { buba,J };
    players[0] = { &cards[0],&cards[1],5000};
    players[1] = { &cards[2],&cards[3],10000};
    players[2] = { &cards[4],&cards[5],8000 };
    players[3] = { &cards[6],&cards[7],6000 };
    for (int i = 0; i < players[0].getplayerscount(); i++)
    {
        cout << players[i];
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
