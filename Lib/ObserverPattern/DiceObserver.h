#ifndef DICE_OBSERVER_H
#define DICE_OBSERVER_H

#include "Observer.h"
#include "Subject.h"

//this class will be responsible for observing a dice object
class DiceObserver : public Observer
{
  private:
    Subject* subject; //the subject that this is observing (it must be a dice object)

  public:
    DiceObserver(Subject*); //a constructor that initializes the diceobserver with a particular subject
    void Update(); // the method called when the subject notify's it's observers
};

#endif