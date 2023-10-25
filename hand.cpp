#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "hand.h"

using namespace std;

Hand::Hand()
{
    num_cards = 0;
    cards = NULL;
}


Hand::Hand(Card *&temp_cards, int temp_num_cards)
{
    cards = new Card[temp_num_cards];
    for(int i = 0; i < temp_num_cards; i++) {
        cards[i].assign_rank(temp_cards[i].get_rank());
        cards[i].assign_suit(temp_cards[i].get_suit());
    }
    num_cards = temp_num_cards;
}


int Hand::face_card_compare(int face_up_rank, int face_up_suit)
{
    int count = 0;
    cout << "Live card (face up): " << face_up_rank << " " << face_up_suit << endl;
    cout << endl << endl << num_cards;
    for (int i = 0; i < num_cards; i++)
    {
        if (cards[i].get_rank() == face_up_rank || cards[i].get_suit() == face_up_suit)
        {
            cout << cards[i].get_rank() << " " << cards[i].get_suit() << endl;
            count ++;
        }
    }
    if (count > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void Hand::print_hand()
{
    for (int i = 0; i < num_cards; i++)
    {
        cout << "Card " << i + 1 << ":    ";
        cards[i].print_card();
        cout << endl;
    }
}


void Hand::add_card(Card &added_card)
{
    Card **cards_point = &cards;
    Card *updated_cards = new Card[num_cards + 1];

    for(int i = 0; i < num_cards; i++) {
        updated_cards[i].assign_suit((*cards_point)[i].get_suit());
        updated_cards[i].assign_rank((*cards_point)[i].get_rank());
    }
    updated_cards[num_cards].assign_suit(added_card.get_suit());
    updated_cards[num_cards].assign_rank(added_card.get_rank());


    delete [] *cards_point;
    *cards_point = NULL;
    *cards_point = updated_cards;
    num_cards++;
    //cout << num_cards;
/*
    cout << "Card: " ;
    updated_cards[num_cards-1].print_card(updated_cards[num_cards-1].get_rank(), updated_cards[num_cards-1].get_suit()) ;
    cout << " added to the hand." << endl */
    //cout << updated_cards[num_cards-1].get_suit() << endl;
    //cout << updated_cards[num_cards-1].get_rank() << endl;
}



void Hand::remove_card(int m_rank, int m_suit)
{
    Card **cards_point = &cards;
    Card *updated_cards = new Card[num_cards - 1];

    bool card_error = 0;
    for(int i = 0; i < num_cards; i++) {
        if(cards[i].get_rank() == m_rank && cards[i].get_suit() == m_suit) {
            cards[i].reset_card();
            card_error = 1;
            break;
        }
    }
    if(card_error = 0) {
        cout << "Invalid input, card does not exist" << endl;
        return;
    }


    int copy_index = 0;
    int index = 0;
    while(index < num_cards) {
        if(cards[index].is_valid_card()) {
            updated_cards[copy_index].assign_rank((*cards_point)[index].get_rank());
            updated_cards[copy_index].assign_suit((*cards_point)[index].get_suit());
            copy_index++;
        }
        index++;
    }


    delete [] *cards_point;
    *cards_point = NULL;
    *cards_point = updated_cards;
    num_cards--;
}



Card*& Hand::get_cards()
{
    return cards;
}



int Hand::get_num_cards()
{
    return num_cards;
}



void Hand::set_num_cards(int updated_num_cards)
{
    num_cards = updated_num_cards;
}



void Hand::set_cards(const Card *&updated_cards)
{
    for(int i = 0; i < num_cards; i++){
        cards[i] = updated_cards[i];
      }
}



int Hand::get_suit(int index)
{
    return cards[index].get_suit();
}



int Hand::get_rank(int index)
{
    return cards[index].get_rank();
}

/*

Hand::~Hand()
{
    Card **cards_point = &cards;
    delete [] *cards_point;
    *cards_point = NULL;
}
*/
