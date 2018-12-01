#include "FlatironBuildingCard.h"

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
	// NEEDS COST CHANGES
	//playerData->setVictoryPoints(playerData->getVictoryPoints() + 2);
	cout << "FLATIRON BUILDING CARD USED" << endl;
	system("pause");
}