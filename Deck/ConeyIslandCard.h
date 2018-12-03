#ifndef CONEYISLANDCARD_H
#define CONEYISLANDCARD_H

#include "Card.h"
#include "../Player/Player.h"

class ConeyIslandCard : public Card {
	public:
		ConeyIslandCard();
		~ConeyIslandCard();
		void Play(Player* playerData);
		void startBuy(Player* playerData); //a method called at the beginning of the buy cards method
		void endBuy(Player* playerData); //a method called at the beginning of the buy cards method
};

#endif