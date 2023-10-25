#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "player.h"


Player::Player()
{
    name = "Default name";
    hand = Hand();
}


Player::Player(const Hand &player_hand, string player_name)
{
    name = player_name;
    hand = player_hand;
    //hand();
    //hand = ;
}


int Player::eight_card_prompt()
{
    srand(time(NULL));
    int computer_decision = (rand() % 4);
    int player_decision;
    if (name == "Computer")
    {
        cout <<  "Computer has played an eight, now it must choose a suit: " << endl;
        if (computer_decision == 0)
        {
            cout << "Computer has changed the suit to Spades" << endl;
            return computer_decision;
        }
        else if (computer_decision == 1)
        {
            cout << "Computer has changed the suit to Hearts" << endl;
            return computer_decision;
        }
        else if (computer_decision == 2)
        {
            cout << "Computer has changed the suit to Diamonds" << endl;
            return computer_decision;
        }
        else if (computer_decision == 3)
        {
            cout << "Computer has changed the suit to Cloves" << endl;
            return computer_decision;
        }
    }
    else
    {
        cout << name << " has played an eight, now you must choose a suit: " << endl << "Enter --> 1 <-- for Spades"  << endl << "Enter --> 2 <-- for Hearts"  << endl << "Enter --> 3 <-- for Diamonds"  << endl << "Enter --> 4 <-- for Cloves" << endl;
        cin >> player_decision;
        if (player_decision == 1)
        {
            cout << name << "  has changed the suit to Spades" << endl;
            return (player_decision - 1);
        }
        else if (player_decision == 2)
        {
            cout << name << " has changed the suit to Hearts" << endl;
            return (player_decision - 1);
        }
        else if (player_decision == 3)
        {
            cout << name << " has changed the suit to Diamonds" << endl;
            return (player_decision - 1);
        }
        else if (player_decision == 4)
        {
            cout << name << " has changed the suit to Cloves" << endl;
            return (player_decision - 1);
        }
    }
}


int Player::face_card_compareh(int face_up_rank, int face_up_suit)
{
    if ( hand.face_card_compare(face_up_rank, face_up_suit) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void Player::print_player_hand()
{
    cout << endl << endl << name << "'s hand:" << endl;
    hand.print_hand();
}


void Player::add_card(Card &added_card)
{
    hand.add_card(added_card);
}


void Player::delete_card(int m_rank, int m_suit)
{
    hand.remove_card(m_rank, m_suit);
}


void Player::set_player_name(string changed_name)
{
    name = changed_name;
}


void Player::set_hand(const Hand & changed_hand)
{
    hand = changed_hand;
}


string Player::get_player_name()
{
    return name;
}


Hand& Player::get_player_hand()
{
    return hand;
}
