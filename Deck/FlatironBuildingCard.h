#ifndef FLATIRONBUILDING_H
#define FLATIRONBUILDING_H

#include "Card.h"
#include "../Player/Player.h"

class FlatIronBuildingCard : public Card {
	public:
		FlatIronBuildingCard();
		~FlatIronBuildingCard();
		void Play(Player* playerData);
		void startBuy(Player* playerData); //a method called at the beginning of the buy cards method
		void endBuy(Player* playerData); //a method called at the beginning of the buy cards method
};


#endif