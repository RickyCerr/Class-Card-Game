#include <iostream>
#include <ctime>
#include <string>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "deck.h"

using namespace std;

Deck::Deck()
{
    subtract = 0;


    int count = 0;
    for (unsigned int i(0); i < cards[0].get_suitmax(); ++i)
    {
        for (unsigned int j(0); j < cards[0].get_rankmax(); ++j)
        {
            cards[count].assign_suit(i);
            cards[count].assign_rank(j);
            //cout << card[count].get_rank() + 1 << " ";
            //cout << card[count].get_suit()  + 1<< ". " << endl;
            count ++;
            //Card card(i, j);
            //Deck.push_back(card);
        }
    }
}

int Deck::get_num_left()
{
    return (52 - subtract);
}


void Deck::shuffle_Deck()
{
  int n = 52;
  srand(time(0));

  for (int i=0; i<n ;i++)
  {
      // Random for remaining positions.
      int r = i + (rand() % (52 -i));
      swap(cards[i], cards[r]);
      //swap(card[i], card[r]);
  }

  /*
  srand(time(0));
  int count = 0;
    for (unsigned int i(0); i < SUIT_MAX; ++i)
    {
        for (unsigned int j(0); j < RANK_MAX; ++j)
        {
            count =  (rand() % (51));
            Card temp;
            card[]
            //cout << r << endl;
            //swap(card[count].assign_suit(i), card[count].assign_suit(r));
            //swap(card[count].assign_rank(i), card[count].assign_rank(r));
            //count ++;
          //Card card(i, j);
          //Deck.push_back(card);
        }
        cout << endl;
    } */
}


void Deck::print_Deck() const
{
    string suit[]  = {"Spades", "Hearts", "Diamonds", "Cloves"};
    string rank[]  = {"Ace","2","3","4","5","6","7","8","9","10","J","Q","K"};

    unsigned int count(1);

    for (unsigned int i(0); i < num_cards; ++i)
    {
        //cout << i << endl << endl;
        cout << "Card " << (i + 1) << ": " << rank[cards[i].get_rank()] << " ";
        cout << suit[cards[i].get_suit()] << ". " << endl << endl;
        //cout << card[i].get_rank() + 1 << " " << endl;
        //cout << card[i].get_suit() + 1 << ". " << endl;
    }
}


int Deck::generate_numcards()
{
num_cards = 52;
}


int Deck::get_numcards()
{
return num_cards;
}

/*
int Deck::getOneCard(int index)
{
    card[index].
}


int Deck::getOneSuit(int index)
{

    //Card cd(Deck.back().get_suit(), Deck.back().get_rank());
    //Deck.pop_back();
    //std::cout << cd.Card2Str() << std::endl;
} */

Card* Deck::get_cards(){
    return cards;
}



Card& Deck::return_one_card()
{
    subtract++;
    return cards[52 - subtract];
}


Deck::~Deck()
{
    //cout << "Deck class removed" << endl;
}
