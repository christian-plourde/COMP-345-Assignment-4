#ifndef REGENERATIONCARD_H
#define REGENERATIONCARD_H

#include "Card.h"
#include "../Player/Player.h"

class RegenerationCard : public Card {
	public:
		RegenerationCard();
		~RegenerationCard();
		void Play(Player* playerData);
};

#endif