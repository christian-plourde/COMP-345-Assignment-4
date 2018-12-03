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
	cout << "Playing your Subterranean Cable Card..." << endl;
	playerData->setEnergy(playerData->getEnergy() + 4);
	playerData->setHealth(playerData->getHealth() - 4);
	//because the card is of discard type, it should be removed the list of cards that the player has
	//after it has been played

	system("pause");
}