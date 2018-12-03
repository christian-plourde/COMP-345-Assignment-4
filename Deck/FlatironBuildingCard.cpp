#include "FlatironBuildingCard.h"
#include "../MapLoader/MapLoader.h"

FlatIronBuildingCard::FlatIronBuildingCard() {
	setID(4);
	setName("Flatiron Building");
	setCost(3);
	setHowTo(Discard);
	setEffect("Buy this card for 1 ENERGY_POINT less if you are in MANHATTAN. +2 VICTORY_POINT");
}

FlatIronBuildingCard::~FlatIronBuildingCard() {

}

void FlatIronBuildingCard::Play(Player* playerData) {
	cout << "Playing your FlatIron Building Card..." << endl;
	playerData->setVictoryPoints(playerData->getVictoryPoints() + 2);

	system("pause");
}

void FlatIronBuildingCard::startBuy(Player* playerData)
{
	//at the beginning of the buy cards method, we should check the location of the player
	//if he is in MANHATTAN, then we should decrease the cost of the card by one.
	if(MapLoader::getMap()->getVertex(playerData->getZone())->getData() == "inner")
	{
		std::cout << "You are in Manhattan. ";
		//if the player's zone corresponds to one in manhattan, then we should lower the cost to 2
		this -> setCost(2);
		std::cout << "Therefore the FlatIron Building card is only " << getCost() << " energy!" << std::endl;
		system("pause");
	}
}

void FlatIronBuildingCard::endBuy(Player* playerData)
{
	//regardless of whether or not the player has chosen to buy this card, at the end of the buy cards
	//method we should set the cost of the card back to 1.
	//in this way, if the player has chosen to buy it, he no longer cares what it costs,
	//and if not, the next time someone tries to buy it, the process will start again
	this->setCost(3);
}