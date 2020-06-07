#pragma once

enum suit{pika,chirva,kresta,buba};
enum cardvalue{two,three,four,five,six,seven,eight,nine,ten,J,Q,K,A};

class Card
{
private:
	enum suit* cardsuit;
	enum cardvalue* value;
	int* decent;
	void init_memory(void) //function for dynamic allocate memory
	{
		cardsuit = new enum suit;
		value = new enum cardvalue;
		decent = new int;
	}
public:
	void setsuit(enum suit suit);
	void setvalue(enum cardvalue val);
	void setdecent(int dec);
	enum suit getsuit();
	enum cardvalue getvalue();
	int getdecent();
};

