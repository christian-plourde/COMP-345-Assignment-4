#ifndef CONEYISLANDCARD_H
#define CONEYISLANDCARD_H

#include "Card.h"
#include "../Player/Player.h"

class ConeyIslandCard : public Card {
	public:
		ConeyIslandCard();
		~ConeyIslandCard();
		void Play(Player* playerData);
};

#endif