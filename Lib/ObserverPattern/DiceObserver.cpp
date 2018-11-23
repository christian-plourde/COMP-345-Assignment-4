#include "DiceObserver.h"
#include <iostream>
#include "../../Dice/Dice.h"

//this file contains the implementation for the class defined in DiceObserver.h

DiceObserver::DiceObserver(Subject* s)
{
  subject = s; //assign whatever subject is passed as a parameter to the private sibject field of the class
}

void DiceObserver::Update()
{
  //the update method that will be called when whichever subject it is observing
  std::cout << "The result of your roll was: " << dynamic_cast<Dice*>(subject) -> toString() << std::endl;
}