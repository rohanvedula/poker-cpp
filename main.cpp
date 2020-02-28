#include "Card.h"
#include "DeckOfCards.h"
#include "Hand.h"
#include <iostream>
#include <string>
using namespace std; 
//Cantrell draw poker

//converts what a player has to a string
string convertToString(int i){
	if (i==10)
		return "royal flush";
	else if (i==9)
		return "straight flush";
	else if(i==8)
		return "four of a kind";
	else if(i==7)
		return "full house";
	else if(i==6)
		return "flush";
	else if(i==5)
		return "straight";
	else if(i==4)
		return "three of a kind";
	else if(i==3)
		return "double pair";
	else if(i==2)
		return "pair";

	else
		return "high card";
}
//determines whether the player wins
string outcome(int *count, int length, Hand *players){
	for(int i = 1; i<length;i++){
		if(count[i]>count[0])
			return "lose";
		else if(count[i]==count[0]){
			if(count[i]==2||count[i]==3||count[i]==4||count[i]==8){
				if(players[i].highestPair()>players[0].highestPair())
					return "lose";
			}
			else if(count[i]==1||count[i]==5||count[i]==6||count[i]==9){
				if(players[i].highestCard()>players[0].highestCard())
					return "lose";
				
			}
			else 
				return "tie";
		}
		else
			return "win";
	}
	return "win";
}
int moneyOutcome(string out, int money, int bid){
		if(out=="win")
			money = money + bid;
		
		else if(out=="tie")
			money = money + bid/2;
		
		else
			money = money - bid;

	return money;
}


int main() {
	int money;
	int ppl = 0;
	cout<<"How much money do you have?"<<endl;
	cin>>money;

	while(ppl<2||ppl>4){
		cout<<"Enter players: (2-4)"<<endl;
		cin>>ppl;
	}
	
	DeckOfCards game;
	char cont = 'Y';
	int counter = 0;
	int bid = 0;
	int bet = 0;
	int replace;

	while(money>0 && cont == 'Y'){
		game.shuffle();
		Hand *players = new Hand[ppl];
		int *count = new int[ppl];
		
		for(int i = 0; i<ppl;i++){
			players[i].reinitialize(game);
		}
		for(int i =0; i<ppl;i++){
			count[i] = players[i].type();
		}

		cout<<endl<<"Your Hand:"<<endl;
		players[0].printHand();

		cout<<"You have a "<<convertToString(count[0])<<endl;

		if(counter%ppl==0){
			cout<<"You're big blind"<<endl;
			bid = bid+10;
		}

		while(bet<11||(bet+bid)>money){
			cout<<"How much do you want to bid"<<endl;
			cin>>bet;
		}

		bid = bid + bet;
		bet = 0;

		for(int i =0; i<3; i++){
			cout<<"Select card to replace (0 to keep all)"<<endl;
			cin>>replace;
			if(replace>0)
				players[0].change(replace-1, game);
			else 
				break;
			
			cout<<"Your Hand:"<<endl;
			players[0].printHand();
			count[0] = players[0].type();
			cout<<"You have a "<<convertToString(count[0])<<endl;
		}

		while((bet+bid)>money){
			cout<<"How much do you want to bid"<<endl;
			cin>>bet;
		}

		bid = bid + bet;

		cout<<endl<<"Your opponents have:"<<endl;
		for(int i = 1; i<ppl;i++){
			//players[i].printHand();
			players[i].bestHandCPU(game);
			count[i] = players[i].type();
			cout<<"\t"<<convertToString(count[i])<<endl;
		}

		cout<<"You "<<outcome(count,ppl, players)<<endl<<endl;

		money = moneyOutcome(outcome(count, ppl, players), money, bid);
		bid = 0;
		bet = 0;

		cout<<"You have $"<<money<<endl;
		cout<<"Continue? (Y or N)"<<endl;
		cin>>cont;

		counter++;

		delete[] count;
		delete[] players;
	}
}