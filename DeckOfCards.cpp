#include <iostream>
#include "DeckOfCards.h"
#include "Card.h"
#include <stdlib.h>
#include <ctime>
using namespace std;
//sizeofdeck is used to initialize the number of cards in the deck
static int sizeOfDeck = 0;
//counter keeps track of which card as been dealt
static int counter = 0;

//creates a full deck of cards, variable i represents the suit and k represents the face 
DeckOfCards::DeckOfCards(){
	for(int i = 0; i<4; i++){
		for(int k = 0; k<13; k++){
			Card temp(i,k);
			deck[sizeOfDeck] = temp;
			sizeOfDeck++;
		}
	}
	currentCard = counter;
}
//shuffle shuffles the deck, also it resets the counter to 0 effectively restarting the round of poker
void DeckOfCards::shuffle(){
	srand(time(NULL));
	for(int i = 0; i <3000; i++){
	  	int a = (rand()%51);
		int b = (rand()%51);
		Card temp = deck[a];
		deck[a] = deck[b];
		deck[b] = temp;
	}
	counter = 0;
}
//returns the next card in the deck
Card DeckOfCards::dealCard(){
	counter++;
	return deck[counter];
}
//determines if there are more cards to deal
bool DeckOfCards::moreCards(){
	if(counter<52)
		return true;

	return false;
}
//prints entire deck
string DeckOfCards::print(int m){
	return deck[m].toString();
}
//returns card at certain position in the deck (only used for testing)
Card DeckOfCards::cardAt(int m){
	return deck[m];
}
//prints which card the deck is on (only used for testing)
void DeckOfCards::printCounter(){
	cout<<counter<<endl;
}