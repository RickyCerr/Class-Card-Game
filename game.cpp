#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "player.h"
#include "game.h"

using namespace std;



Game::Game() {
    cards = Deck();
    //cards.fill_cards();
    cards.shuffle_Deck();

    players[0] = Player(Hand(), "You");
    players[1] = Player(Hand(), "Computer");
    player_turn = 0;
}



Game::~Game() {
    cout << "Game over" << endl;
};


Deck& Game::get_cards() {
    return cards;
}



Player* Game::get_players() {
    return players;
}


Card& Game::get_faceup_card() {
    return faceup_card;
}


int Game::get_player_turn() {
    return player_turn;
}



void Game::set_cards(const Deck &new_cards) {
    cards = new_cards;
}



void Game::set_players(const Player (&new_players)[2]) {
    players[0] = new_players[0];
    players[1] = new_players[1];
}



void Game::set_faceup_card(Card &new_faceup_card) {
    faceup_card.assign_rank(new_faceup_card.get_rank());
    faceup_card.assign_suit(new_faceup_card.get_suit());
}






void Game::print_game_status() {
    cout << endl << "Cards left in deck: " << cards.get_numcards() << endl;
    string faceup_rank = "";
    /*if(faceup_card.get_rank() == -1)
    {
        faceup_rank = "any";
    }
    else
    {
        faceup_rank = faceup_card.get_string_rank();
    } */
    //************cout << "Card on top of stockpile: " << faceup_card.print_card() << endl;
    if(player_turn == 0)
    {
    // Assuming human player is players[0]
        Hand &player_hand = players[0].get_player_hand();
        player_hand.print_hand();
    }
    else if (player_turn == 1)
    {
        cout << endl <<"Computer has " << players[1].get_player_hand().get_num_cards() << " cards left" << endl;
    }
}





void Game::deal_cards() {

  for(int i = 0; i < 7; i++)
  {
    players[0].add_card(cards.return_one_card());
    players[1].add_card(cards.return_one_card());

  }
  players[0].print_player_hand() ;
  players[1].print_player_hand() ;

  faceup_card = cards.return_one_card();
  cout << "The top card (live card) is: " ;
  faceup_card.print_card();
  cout << endl << endl;
  cout << card_is_valid(0) << endl;
}


void Game::run_player_turn()
{
  int choice = -1;
  player_turn = 1;
  do {
    players[1].print_player_hand() ;
    cout << " Which card do you want to play (press 0 to draw new card)" << endl;
    cin >> choice;
  } while (card_is_valid(choice) && choice > 0 && choice < players[1].get_player_hand().get_num_cards());
  if(choice == 0){
      players[1].add_card(cards.return_one_card());
      cout << "Card added" << endl;
        players[1].print_player_hand();

  }
}











bool Game::card_is_valid(int card_num) {
  card_num++;
    if(card_num < 0 || card_num > (players[player_turn].get_player_hand().get_num_cards() - 1))
    {
        return false;
    }
    int rank = faceup_card.get_rank();
    int suit = faceup_card.get_suit();
    if(rank == players[player_turn].get_player_hand().get_rank(card_num) || suit == players[player_turn].get_player_hand().get_suit(card_num))
    {
        return true;
    }
    else
    {
        return false;
    }
}





/*
Game::Game(){

}



/*Game::Game(){
    //string player_name;
    //cin >> player_name;
    //players[0].assign_name(player_name);

}*/
