#ifndef POWERSUBSTATIONCARD_H
#define POWERSUBSTATIONCARD_H

#include "Card.h"
#include "../Player/Player.h"

class PowerSubstationCard : public Card {
	public:
		PowerSubstationCard();
		~PowerSubstationCard();
		void Play(Player* playerData);
};

#endif