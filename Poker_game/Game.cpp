#include "Game.h"

int Game::getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Game::getcardsPlayers(Card(*cards), Player(*players))
{
    int tab[5];
    for (int i = 0; i < players[0].getplayerscount(); i++)
    {
        do
        {
            tab[0] = getRandomNumber(0, 51);
        } while (cards[tab[0]].getbusy());
        do
        {
            tab[1] = getRandomNumber(0, 51);
        } while (cards[tab[1]].getbusy());
        players[i].setcard(&cards[tab[0]], &cards[tab[1]]);
        players[i].setmoney(1000 * i + 1);
    }
}

void Game::getcardsTable(Card(*cards), Table(*table))
{
    int tab[5];
    for (int i = 0; i < 5; i++)
    {
        do
        {
            tab[i] = getRandomNumber(0, 51);
        } while (cards[tab[i]].getbusy());
        table->setcard(&cards[tab[i]], i);
    }
}

void Game::freecards(Card(*cards))
{
    for (int i = 0; i < 52; i++)
    {
        cards[i].setfree();
    }
}

void Game::createstack(Card(*cards))
{
    int x = 0;
    enum cardvalue val;
    enum suit sui;
    for (int i = 0; i < 4; i++)
    {
        for (int u = 0; u < 13; u++)
        {
            sui = static_cast<suit>(i);
            val = static_cast<cardvalue>(u);
            cards[x] = { sui,val };
            x++;
        }
    }
}

