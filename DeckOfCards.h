#include <iostream>
#include "Card.h"
using namespace std;

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

class DeckOfCards{
private:
	Card *deck = new Card[52];
	int currentCard;

public:
	DeckOfCards();
	~DeckOfCards(){
		delete[] deck;
	};
	void shuffle();
	Card dealCard();
	bool moreCards();
	string print(int);
	Card cardAt(int);
	void printCounter();
};

#endif