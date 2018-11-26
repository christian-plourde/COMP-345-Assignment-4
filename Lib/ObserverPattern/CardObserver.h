#ifndef CARD_OBSERVER_H
#define CARD_OBSERVER_H

#include "Observer.h"
#include "Subject.h"

//this class will be responsible for observing the cards that a player has in his hand
class CardObserver : public Observer
{
  private:
    Subject* subject; //the subject that this is observing (it must be a card)

  public:
    CardObserver(Subject*); //a constructor that initializes the cardobserver with a particular subject
    void Update(); // the method called when the subject notify's it's observers
};

#endif