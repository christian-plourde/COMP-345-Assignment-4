#include "RegenerationCard.h"

RegenerationCard::RegenerationCard() {
	setID(3);
	setName("Regeneration");
	setCost(5);
	setHowTo(Keep);
	setEffect("Heal 1 damage at the start of your turn");
}

RegenerationCard::~RegenerationCard() {

}

void RegenerationCard::Play(Player* playerData) {
	cout << "Playing your Regeneration Card..." << endl;
	playerData->setHealth(playerData->getHealth() + 1);
	
	system("pause");
}