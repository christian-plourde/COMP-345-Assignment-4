#include "CardObserver.h"
#include <iostream>
#include "../../Player/Player.h"
#include "../../Deck/Card.h"

CardObserver::CardObserver(Subject* s)
{
  subject = s; //this sets the subject that the observer is looking at
}

void CardObserver::Update()
{
  //this method will be called when the subject notifies its observers and will print a summary of the cards
  //that the player has in his hand at that moment
  //if the player has no cards in his hands, we should simply say that he doesn't have any cards

  if(dynamic_cast<Player*>(subject) -> getCards() -> getCount() < 1)
    std::cout << dynamic_cast<Player*>(subject) -> getName() << ", you have no cards!" << std::endl;

  //if he does have cards in his hand, we should print out information about each card that he does have
  else
  {
    int i = 1;
    node<Card*>* curr = dynamic_cast<Player*>(subject) -> getCards() -> getHead();
    std::cout << dynamic_cast<Player*>(subject) -> getName() << ", these are the cards in your hand:" << std::endl;
    while(curr != NULL)
    {

      std::cout << i << ". ";
      std::cout << curr -> getData() -> getName() << "\t" << curr -> getData() -> getEffect();
      std::cout << std::endl;
      std::cout << std::endl;
      curr = curr -> getNext();
      i++;
    }
  }

}


