#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include "card.h"
//#include "deck.h"
#include "player.h"

using namespace std;


class Game {
private:
    Deck cards;
    Card faceup_card;
    Player players[2];
    int player_turn;
public:
    Game();
    Game(const Deck &init_cards, const Player (&init_players)[2]);
    ~Game();
    Deck& get_cards();
    Player* get_players();
    Card& get_faceup_card();
    int get_player_turn();
    void set_cards(const Deck &new_cards);
    void set_players(const Player (&new_players)[2]);
    void set_faceup_card(Card &new_faceup_card);
  //  bool game_over();
    void print_game_status();
    void flip_top_card();



    bool card_is_valid(int card_num);
    void run_player_turn();
    void deal_cards();
};








/*
class Game
{
  private:
    Deck cards;
    Player players[2];
  public:
    explicit Game();
    //void start_game();
    //int end_game();

  // must have constructors, destructor, accessor methods, and mutator methods
};

*/


//have top card object


#endif
