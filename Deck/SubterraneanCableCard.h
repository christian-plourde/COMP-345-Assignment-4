#ifndef SUBTERRANEANCABLECARD_H
#define SUBTERRANEANCABLECARD_H

#include "Card.h"
#include "../Player/Player.h"

class SubterraneanCableCard : public Card {
	public:
		SubterraneanCableCard();
		~SubterraneanCableCard();
		void Play(Player* playerData);
};

#endif
