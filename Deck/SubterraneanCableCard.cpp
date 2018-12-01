#include "SubterraneanCableCard.h"

SubterraneanCableCard::SubterraneanCableCard() {
	setID(1);
	setName("Subterranean Cable");
	setCost(0);
	setHowTo(Discard);
	setEffect("+4 ENERGY_POINT and take 4 damage");
}

SubterraneanCableCard::~SubterraneanCableCard() {

}

void SubterraneanCableCard::Play(Player* playerData) {
	/*playerData->setEnergy(playerData->getEnergy() + 4);
	playerData->setHealth(playerData->getHealth() - 4);*/
	cout << "SUBTERRANEAN CABLE CARD USED" << endl;
	system("pause");
}