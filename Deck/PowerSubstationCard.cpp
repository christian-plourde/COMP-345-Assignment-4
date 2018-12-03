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
	cout << "Playing your Power Substation Card..." << endl;
	playerData->setVictoryPoints(playerData->getVictoryPoints() + 1);
	playerData->setEnergy(playerData->getEnergy() + 8);
	playerData->setHealth(playerData->getHealth() - 3);
	node<Card*>* toRemove = playerData -> getCards() -> find(this);
	playerData -> getCards() -> remove(toRemove);

	system("pause");
}