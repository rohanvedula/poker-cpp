#include <iostream>
using namespace std;

#ifndef CARD_H
#define CARD_H

class Card{
private:
	int face,suit;

public:
	Card();
	Card(int, int);
	string toString();
	bool equalsFace(Card);
	bool equalsSuit(Card);
	bool faceEqualsString(string);
	
};

#endif