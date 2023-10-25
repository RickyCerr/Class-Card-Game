#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "hand.h"

using namespace std;

class Player
{
  private:
    Hand hand;
    string name;
  public:
    explicit Player();
    Player(const Hand& player_hand, string player_name);

    int eight_card_prompt();
    int face_card_compareh(int face_up_rank, int face_up_suit);
    void print_player_hand();
    void add_card(Card &added_card);
    void delete_card(int m_rank, int m_suit);
    void set_player_name(string changed_name);
    void set_hand(const Hand& changed_hand);
    string get_player_name();
    Hand& get_player_hand();
  // must have constructors, destructor, accessor methods, and mutator methods

};



#endif
