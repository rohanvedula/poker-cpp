#include <iostream>
#include "Card.h"
#include "DeckOfCards.h"
#include "Hand.h"
using namespace std;
static string suits[] = {"Hearts", "Diamonds", "Spades", "Clubs"};
static string faces[] = {"Ace", "Duece", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

//intializes a deck of cards with the given deck
Hand::Hand(DeckOfCards &d){
	for(int i = 0; i<5; i++){
		hand[i] = d.dealCard();
	}
}
//returns blank hand
Hand::Hand(){
	Card k;
	for(int i = 0; i<5; i++){
		hand[i] = k;
	}
}
//reinitializes cards in hand with cards in the deck
void Hand::reinitialize(DeckOfCards &d){
	for(int i = 0; i<5; i++){
		hand[i] = d.dealCard();
	}
}
//makes two hand equal to each other (only used for testing)
void Hand::equals(Hand temp){
	for(int i = 0; i<5; i++){
		hand[i] = temp.cardAt(i);
	}
}

//The following methods were taken from assignment 1 card game in C++ they (should) all work since they worked in the previous assignment
bool Hand::threeOfAKind(){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
		 	for(int l=0; l<5; l++){
		 		if((hand[i].equalsFace(hand[j])&&hand[i].equalsFace(hand[l]))&& (i!=j&&i!=l&&j!=l))
		 		return true; 
			}
		}
	}
	return false;
}
bool Hand::fourOfAKind(){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
		 	for(int l=0; l<5; l++){
				for(int k=0; k<5;k++){
		 			if((hand[i].equalsFace(hand[j])&&hand[i].equalsFace(hand[l])&&hand[i].equalsFace(hand[k]))&& (i!=j&&i!=l&&j!=l&&i!=k&&l!=k&&j!=k))
		 			return true;
				} 
			}
		}
	}
	return false;
}
bool Hand::twoSame (){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++)
		 	if(hand[i].equalsFace(hand[j])&& i!=j)
		 		return true; 
	}
	return false;
}
bool Hand::doubleTwoSame(){
	int counter1 = 0;
	for(int i=0; i<5; i++){
	 	for(int j=0; j<5; j++){
	 		if(hand[i].equalsFace(hand[j])&& i!=j){
	 			counter1++;
	 		}
	 	}
 	}
	if(counter1==4||counter1==8)
		return true;

	return false;
}
bool Hand::flush(){
	if(hand[0].equalsSuit(hand[1])&&hand[0].equalsSuit(hand[2])&&hand[0].equalsSuit(hand[3])&&hand[0].equalsSuit(hand[4]))
	 	return true;
	 
	else
		return false;
}
bool Hand::straight(){
	if(twoSame()==true)
		return false;

	int temp = 13;
	int temp2 = 13;
	int l = 0;

	int counter1=0;

	 for(int i = 0; i<5; i++){
		 for(int j = 0; j<13; j++){
			 if(hand[i].faceEqualsString(faces[j])&&j<temp)
			  temp = j;	
			if(hand[i].faceEqualsString(faces[j])&&j<temp2&&j>temp)
			  temp2 = j;	
	 	}
	 }
	
	if(temp==0&&temp2==9)
	 temp=temp2;

	for(int i = 0; i<5; i++){
		for(int k = 0; k <5; k++){
			l= temp+k;
			if(l>12)
				l= l-13;
			if(hand[i].faceEqualsString(faces[l]))
				counter1++;
		}
	 }
	if(counter1==5)
		return true;
	return false;
}
bool Hand::royalFlush(){
	if(flush()==false||twoSame()==true)
		return false;

	int counter1 = 0;
	string faces[] ={"Ace","King","Queen","Jack","Ten"};

	for(int i = 0; i<5; i++){
			for(int k = 0; k<5; k++){
				if(hand[k].faceEqualsString(faces[i])){
				counter1++;
			} 	
	 	}
	}
	if(counter1==5)
		return true;
	 
	else	
		return false;
 }
bool Hand::straightFlush(){
	if(straight()==true && flush()==true)
	return true;
	
	else 
	return false;
}
bool Hand::fullHouse(){
	if(threeOfAKind()==true && doubleTwoSame()==true)
		return true;
	
	else
		return false;
}
int Hand::highestCard(){
	int temp = 0;
	for(int i = 0; i<5; i++){
		 for(int j = 0; j<(13); j++){
			 if(hand[i].faceEqualsString(faces[j])&&j>temp)
			  temp = j;	
	 	}
	 }
	return temp;
}
int Hand::highestPair(){
	int temp;
	bool fin = true;
	for(int i=0; i<5 && fin == true; i++){
		 for(int j=0; j<5 && fin == true; j++){
		 	if(hand[i].equalsFace(hand[j])&& i!=j){
		 		temp = j;
				fin = false;
			}
		 }
	}
	for(int l = 0; l<13; l++){
		if(hand[temp].faceEqualsString(faces[l])){
			temp = l;
			return l;
		}
	}
	return temp;
}
//assigns a number value to the hand
int Hand::type(){
	if (royalFlush()==true)
	return 10;
	if (straightFlush()==true)
	return 9;
	if(fourOfAKind()==true)
	return 8;
	if(fullHouse()==true)
	return 7;
	if(flush()==true)
	return 6;
	if(straight()==true)
	return 5;
	if(threeOfAKind()==true)
	return 4;
	if(doubleTwoSame()==true)
	return 3;
	if(twoSame()==true)
	return 2;

	return 1;
}

//The folowing are new methods

//returns carAt a certain integer
Card Hand::cardAt(int i){
	return hand[i];
}
//prints hand
void Hand::printHand(){
	for(int i = 0; i <5; i++){
		cout<<"\t"<<i+1<<". "<<hand[i].toString()<<endl;
	}
}
//finds the index of the lowest value card in the deck
int Hand::indexOfLowestCard(){
	for(int j = 0; j<13; j++){
		for(int i = 0; i<5; i++){
			if(hand[i].faceEqualsString(faces[j]))
				return j;
	 	}
	}
	return 0;
}
//exchanges a card with a new one
void Hand::change(int k, DeckOfCards &d){
	hand[k] = d.dealCard();
}
//changes a card in the hand except for the card at a specified index
void Hand::changeAllBut(int k, DeckOfCards &d){
	bool fin = true;
	for(int i = 0; i<5&& fin==true; i++){
		if(hand[i].faceEqualsString(faces[k])==false){
			change(i,d);
			fin = false;
		}	
	}
}
//determines the best hand possible for a cpu in 3 exchanges
void Hand::bestHandCPU(DeckOfCards &d){
	if(type()<5){
		for(int i = 0; i < 3 && type()<5; i++){
			if(type() == 1)
				changeAllBut(indexOfLowestCard(),d);
			else
				changeAllBut(highestPair(),d);
			
			//printHand();
		}
	}
}
