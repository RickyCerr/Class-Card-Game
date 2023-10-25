#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "card.h"
#include <iostream>

using namespace std;

Card::Card()
{
   suit_max = generate_suitmax();
   rank_max = generate_rankmax();
   m_suit = generate_suit();
   m_rank = generate_rank();

}


Card::Card(const int &suit, const int &rank) : m_suit(suit), m_rank(rank)
{

}


int Card::generate_suitmax(){
    return 4;
}


int Card::generate_rankmax(){
    return 13;
}


int Card::generate_suit()
{
    return rand() % (suit_max-1) + 0;
}


int Card::generate_rank()
{
    return rand() % (rank_max-1) + 0;
}


void Card::assign_suit(int index)
{
    m_suit = index;
    // FOR LATER:return rand() % (SUIT_MAX-1) + 0;
}


void Card::assign_rank(int index)
{
    m_rank = index;
    // FOR LATER: return rand() % (RANK_MAX-1) + 0;
}
/*
std::string Card::Card2Str() const
{
    return SUIT[get_suit()] + RANK[get_rank()];
}
*/


int Card::get_suitmax() const
{
    return suit_max;
}


int Card::get_rankmax() const
{
    return rank_max;
}


int Card::get_suit() const
{
    return m_suit;
}


int Card::get_rank() const
{
    return m_rank;
}


void Card::reset_card() {
    m_rank = -1;
    m_suit = -1;
}


bool Card::is_valid_card() {
return !(m_rank == -1 || m_suit == -1);
}


void Card::print_card()
{
  string suit[]  = {"Spades", "Hearts", "Diamonds", "Cloves"};
  string rank[]  = {"Ace","2","3","4","5","6","7","8","9","10","J","Q","K"};

  cout << rank[m_rank] << " of ";
  cout << suit[m_suit] ;
}


Card::~Card()
{
    //cout << "Card class deleted" << endl;
}
