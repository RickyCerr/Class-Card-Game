#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>

#include "game.h"
//#include "player.h"
//#include "hand.h"
//#include "card.h"
//#include "deck.h"

int main()
{
Game Game;
Game.deal_cards();
Game.run_player_turn();


    //Game Game;
    /*Game.start_game();
    while( (Game.end_game()) == 0 ){
        if ( (Game.end_game()) == 1){
            cout << "Player has won";
        }
        else if( (Game.end_game()) == 2){
            cout << "Computer has won";
        }
    }*/

/*int end_game = 0;

    while( end_game == 0 ){
        cin >> end_game;
        if ( end_game == 1){
            cout << "Player has won";
        }
        else if( end_game == 2){
            cout << "Computer has won";
        }
    }*/

/*

    Deck Deck;
    Card c;
    Card b;
    Card d;
    Card a;


    Deck.generate_numcards();
    Hand Hand;

    Hand.add_card(c);
    Hand.add_card(b);
    Hand.add_card(d);
    Hand.add_card(a);    //Deck.print_Deck();


    Hand.print_hand();




    Player player(Hand, "Player");
    player.eight_card_prompt();

    Player clayer(Hand, "Computer");
    clayer.eight_card_prompt();


    player.set_hand(Hand);
    if (player.face_card_compareh(0,0) == 1)
    {
        cout << "card matches" << endl;
    }
    else
    {
        cout << "card DOES NOT match" << endl;

    }

    //Player player[2];
    //player[0].

    //Deck.getOneCard();
    int input;
    //std::cout<< "Press 1 followed by pressing enter to shuffle the deck" << std::endl;
    std::cin >> input;

    if(input == 1)
    {
      //Deck.shuffle_Deck();

      std::cout << std::endl;
      //Deck.print_Deck();
    }



    std::cout << std::endl;

    return 0;
 */

}
