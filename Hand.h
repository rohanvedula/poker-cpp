#include <iostream>
#include "Card.h"
#include "DeckOfCards.h"
using namespace std;

#ifndef HAND_H
#define HAND_H

class Hand{
private:
	Card *hand = new Card[5];

public:
	Hand(DeckOfCards &);
	Hand();
	void reinitialize(DeckOfCards &);
	~Hand(){
		delete[] hand;
	};
	void equals(Hand);
	bool threeOfAKind();
	bool fourOfAKind();
	bool twoSame();
	bool doubleTwoSame();
	bool flush();
	bool straight();
	bool royalFlush();
	bool fullHouse();
	bool straightFlush();
	int highestCard();
	int highestPair();
	void printHand();
	Card cardAt(int i);
	int type();
	void change(int, DeckOfCards &);
	void bestHandCPU(DeckOfCards &);
	int indexOfLowestCard();
	void changeAllBut(int, DeckOfCards &);
};

#endif