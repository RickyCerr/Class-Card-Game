#ifndef DECK_H
#define DECK_H

//#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "hand.h"

using namespace std;

class Deck
{
public:
      explicit Deck();
      ~Deck();
      void shuffle_Deck();
      void print_Deck() const;
      //int getOneSuit(int index);
      //int getOneSuit(int index);
      Card* get_cards();
      Card cards[52];
      int generate_numcards();
      int get_numcards();

      Card& return_one_card();
      int get_num_left();
private:

      int num_cards;
      int subtract;
};

#endif
