#include "Game.h"

int Game::getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
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
        string s;
        s += to_string(players[i].getid());
        players[i].setname("Bot player " + s);
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

void Game::getmoneyfromplayer(Player(*player), Table(*table), int money)
{
    if (player->getmoney() >= money)
    {
        table->increasemoney(money);
        player->increasemoney(-money);
    }
    else
    {
        throw "Player dont have money\n";
    }
}

void Game::getmoneytoplayer(Player(*player), Table(*table), int money)
{
    if (table->getmoney() >= money)
    {
        table->increasemoney(-money);
        player->increasemoney(money);
    }
    else
    {
        throw "Table dont have money\n";
    }
}

void Game::setstage(GameStage st)
{
    this->stage = st;
}


GameStage Game::getstage(void)
{
    return this->stage;
}

void Game::getcombinationpower(Player(*player), Table(*table))
{
    switch (this->stage)
    {
    case Preflop:
        if (player->getcard(1)->getdecent() == player->getcard(2)->getdecent())
        {
            player->setcombinationpower(100 + player->getcard(1)->getdecent());
        }
        else
        {
            player->setcombinationpower(player->getcard(1)->getdecent());
        }
        break;

    case Flop:
        Card* cards = new Card[5];
        Card* card = new Card;
        cards[0] = player->getcard(1);
        cards[1] = player->getcard(2);
        cards[2] = table->getcard(1);
        cards[3] = table->getcard(2);
        cards[4] = table->getcard(3);

        for (int i = 0; i < 5; i++) 
        {
            for (int j = 0; j < 4; j++) 
            {
                if (cards[j].getvalue() > cards[j + 1].getvalue()) 
                {
                    *card = cards[j]; // создали дополнительную переменную
                    cout << *card;
                    cards[j] = cards[j + 1]; // меняем местами
                    cards[j + 1] = *card; // значения элементов
                }
            }
        }

        delete card;

        //streetflash check
        if (cards[0].getsuit() == cards[1].getsuit() == cards[2].getsuit() == cards[3].getsuit() == cards[4].getsuit())
        {
            bool streetcheck = false;
            for (int i = 0; i < 4; i++)
            {
                if (cards[i + 1].getvalue() - cards[i].getvalue() == 1)
                {
                    streetcheck = true;
                }
                else
                {
                    streetcheck = false;
                }
            }
            if (streetcheck)
            {
                player->setcombinationpower(900 + cards[4].getvalue()); //street flash
            }
            else
            {
                player->setcombinationpower(600 + cards[4].getvalue()); //flash
            }
        }

        //kare check
        for (int i = 0; i < 2; i++)
        {
            if (cards[i].getvalue() == cards[i + 1].getvalue() == cards[i + 2].getvalue() == cards[i + 3].getvalue())
            {
                player->setcombinationpower(800 + cards[i + 3].getvalue());
                return;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            if (cards[i].getvalue() == cards[i + 1].getvalue() == cards[i + 2].getvalue())
            {
                if (cards[i + 3].getvalue() == cards[i + 4].getvalue())
                {
                    player->setcombinationpower(800 + cards[3].getvalue());
                        return;
                }
                return;
            }
            return;
        }
            

            
        
    }
}