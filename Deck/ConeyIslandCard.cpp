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
	// NEEDS COST CHANGES
	//playerData->setVictoryPoints(playerData->getVictoryPoints() + 3);
	cout << "CONY ISLAND CARD USED" << endl;
	system("pause");
}