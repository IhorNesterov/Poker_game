#pragma once
#include <iostream>

enum suit{pika,chirva,kresta,buba};
enum cardvalue{two,three,four,five,six,seven,eight,nine,ten,J,Q,K,A};
using namespace std;

class Card
{
private:

	enum suit* cardsuit;
	enum cardvalue* value;
	int* decent;
	bool* busy;
	void init_memory(void) //function for dynamic allocate memory
	{
		busy = new bool;
		*this->busy = false;
		cardsuit = new enum suit;
		value = new enum cardvalue;
		decent = new int;
	}

public:

	static int cardscount;
	void setsuit(enum suit suit);
	void setvalue(enum cardvalue val);
	void setdecent(int dec);
	void setbusy(void);
	bool getbusy(void);
	enum suit getsuit();
	enum cardvalue getvalue();
	int getdecent();

	Card()
	{
		init_memory();
		setsuit(pika);
		setvalue(two);
		setdecent(0);
	}

	Card(enum suit suit, enum cardvalue val)
	{
		init_memory();
		setsuit(suit);
		setvalue(val);
		Card::cardscount++;
		setdecent(cardscount);
	}


	friend std::ostream& operator << (std::ostream& str, const Card& his)
	{
		switch (*his.value)
		{
		case(two):
			str << "2 ";
			break;
		case(three):
			str << "3 ";
			break;
		case(four):
			str << "4 ";
			break;
		case(five):
			str << "5 ";
			break;
		case(six):
			str << "6 ";
			break;
		case(seven):
			str << "7 ";
			break;
		case(eight):
			str << "8 ";
			break;
		case(nine):
			str << "9 ";
			break;
		case(ten):
			str << "10 ";
			break;
		case(J):
			str << "J ";
			break;
		case(Q):
			str << "Q ";
			break;
		case(K):
			str << "K ";
			break;
		case(A):
			str << "A ";
			break;
		}

		switch (*his.cardsuit)
		{
		case(pika):
			str << "Pika";
			break;
		case(kresta):
			str << "Kresta";
			break;
		case(chirva):
			str << "Chirva";
			break;
		case(buba):
			str << "Buba";
			break;
		}

		str << " Id " << *his.decent << endl;
		return str;
	}
};

void createstack(Card(*cards));
