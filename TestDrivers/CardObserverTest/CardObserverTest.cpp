#include "../../Player/Player.h"
#include <iostream>
int main()
{
  Player* p1 = new Player();

  Card c1;
  c1.setName("Card 1");
  node<Card> n1;
  n1.setData(c1);
  p1 -> getCards() -> add(&n1);
  node<Card>* curr = p1 -> getCards() -> getHead();

  while(curr != NULL)
  {
    std::cout << curr -> getData().getName();

    curr = curr -> getNext();
  }
  delete p1;
  return 0;
}