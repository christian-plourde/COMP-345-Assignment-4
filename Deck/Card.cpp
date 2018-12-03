// implementation file for Card.h


#include <iostream>
#include "Card.h"

string how_To[4] = { "Empty", "Goal", "Keep", "Discard" };		// string representations of how to

// card default constructor
Card::Card() {
	name = "";
	cost = -1;
	howTo = Empty;
	effect = "";
}

// set constructor
Card::Card(int iD, string nam, int cos, HowTo how, string eff) {
	id = iD;
	name = nam;
	cost = cos;
	howTo = how;
	effect = eff;
}

Card::~Card() {
	// destructor
}

/*** SETTERS ***/
void Card::setID(int i) {
	id = i;
}

void Card::setName(string nam) {
	name = nam;
}

void Card::setCost(int cos) {
	cost = cos;
}

void Card::setHowTo(HowTo how) {
	howTo = how;
}

void Card::setEffect(string eff) {
	effect = eff;
}


/** GETTERS ***/
int Card::getID() const {
	return id;
}

string Card::getName() const {
	return name;
}

int Card::getCost() const {
	return cost;
}

HowTo Card::getHowTo() const {
	return howTo;
}

string Card::getEffect() const {
	return effect;
}

void Card::Print() {
	cout << "{ ID: " << id << endl;
	cout << "  Name: " << name << endl;
	cout << "  Cost: " << cost << endl;
	cout << "  How To Play: " << how_To[howTo] << endl;		// print string representation of how to
	cout << "  Effect: " << effect << " }" << endl;
}


void Card::Play(Player* playerData)
{
	//the play method does absolutely nothing for the base class
	std::cout << "Playing a base class card" << std::endl;
	system("pause");
}

void Card::startBuy(Player* playerData)
{
	//this method is called at the beggining of the buy cards method
	//for a card of the base class type, it doesn't need to do anything
}

void Card::endBuy(Player* playerData)
{
	//this method is called at the end of the buy cards method
	//for a card of the base class type, it doesnt need to do anything
}
