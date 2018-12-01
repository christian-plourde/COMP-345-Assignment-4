#include "PowerSubstationCard.h"

PowerSubstationCard::PowerSubstationCard() {
	setID(2);
	setName("Power Substation");
	setCost(5);
	setHowTo(Discard);
	setEffect("+1 VICTORY_POINT, +8 ENERGY_POINT and take 3 damage");
}

PowerSubstationCard::~PowerSubstationCard() {

}

void PowerSubstationCard::Play(Player* playerData) {
	/*playerData->setVictoryPoints(playerData->getVictoryPoints() + 1);
	playerData->setEnergy(playerData->getEnergy() + 8);
	playerData->setHealth(playerData->getHealth() - 3);*/
	cout << "POWER SUBSTATION CARD USED" << endl;
	system("pause");
}