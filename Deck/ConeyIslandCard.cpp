#include "ConeyIslandCard.h"

ConeyIslandCard::ConeyIslandCard() {
	setID(5);
	setName("Coney Island");
	setCost(4);
	setHowTo(Discard);
	setEffect("Buy this card for 1 ENERGY_POINT less if you are in BROOKLYN. +3 VICTORY_POINT");
}

ConeyIslandCard::~ConeyIslandCard() {

}

void ConeyIslandCard::Play(Player* playerData) {
	cout << "Playing your Coney Island Card..." << endl;
	playerData->setVictoryPoints(playerData->getVictoryPoints() + 3);
	//because this card is a discard type, we need to remove it from the player's hand after
	//he has played it
	//we first need to find the card to remove in his hand
	system("pause");
}

void ConeyIslandCard::startBuy(Player* playerData)
{
	//at the beginning of the buy cards method, we should check where the player is
	//if he happens to be in brooklyn, then he can buy this card for 1 less energy cube than its cost
	if(MapLoader::getMap()->getVertex(playerData->getZone())->getName() == "Brooklyn")
	{
		std::cout << "You are in Brooklyn. ";
		this -> setCost(3);
		std::cout << "Therefore the Coney Island card is only " << getCost() << " energy!" << std::endl;
		system("pause");
	}

}

void ConeyIslandCard::endBuy(Player* playerData)
{
	//no matter if the player bought this card or not, we should set the cost back to what it was
	this -> setCost(4);
}