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
	//playerData->setHealth(playerData->getHealth() + 1);
	cout << "REGENERATION CARD USED" << endl;
	system("pause");
}