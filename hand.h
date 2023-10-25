#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <fstream>
#include "deck.h"


using namespace std;
/*
class Hand
{
  private:
    Card* cards;
    int n_cards;  // Number of cards in the hand.
  public:
    explicit Hand();
  // must have constructors, destructor, accessor methods, and mutator methods
}; */



class Hand
{
  private:
      Card *cards;
      int num_cards;
  public:
      Hand();
      Hand(Card *&temp_cards, int temp_num_cards);
      //~Hand();

      int face_card_compare(int face_up_rank, int face_up_suit);
      Card*& get_cards();
      int get_num_cards();
      void print_hand();
      void set_cards(const Card *&new_cards);
      void set_num_cards(int new_n_cards);
      void add_card(Card &added_card);
      void remove_card(int m_rank, int m_suit);
      int get_suit(int index);
      int get_rank(int index);
      //void print_hand();
};


#endif
