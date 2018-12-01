#ifndef FLATIRONBUILDING_H
#define FLATIRONBUILDING_H

#include "Card.h"
#include "../Player/Player.h"

class FlatIronBuildingCard : public Card {
	public:
		FlatIronBuildingCard();
		~FlatIronBuildingCard();
		void Play(Player* playerData);
};


#endif