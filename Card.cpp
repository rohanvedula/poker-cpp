#include <iostream>
#include "Card.h"
#include <string>
using namespace std;
//static variables used to dictate the string output
static string suits[] = {"Hearts", "Diamonds", "Spades", "Clubs"};
static string faces[] = {"Ace", "Duece", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

Card::Card(){
	suit = 0;
	face = 0;
}
Card::Card(int s, int f){
	suit = s;
	face = f;
}
//returns the card in a string form
string Card::toString(){
	return faces[face] +" of " +suits[suit];
}
//returns a boolean statement whether the faces of 2 cards are equal
bool Card::equalsFace(Card o){
	if(face==o.face)
		return true;
	return false;
}
//returns a boolean statement whether the suits of 2 cards are equal
bool Card::equalsSuit(Card o){
	if(suit==o.suit)
		return true;
	return false;
}
//returns a boolean statement whether the face of card equals a string
bool Card::faceEqualsString(string m){
	if(faces[face]==m)
		return true;
	return false;
}
