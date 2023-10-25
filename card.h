#ifndef CARD_H
#define CARD_H

#include <string>

//const int SUIT_MAX(4);
//const int RANK_MAX(13);

class Card
{
    //friend class Deck; // Deck Class needs to access to Card Class but not vice versa
public:
    explicit Card();
    explicit Card(const int &suit, const int &rank);
    ~Card();

    std::string Card2Str() const;
    int generate_suitmax();
    int generate_rankmax();
    int generate_suit();
    int generate_rank();
    void assign_suit(int index);
    void assign_rank(int index);
    int get_suitmax() const;
    int get_rankmax() const;
    int get_suit() const;
    int get_rank() const;
    void reset_card();
    bool is_valid_card();
    void print_card();

  

private:

    int suit_max;
    int rank_max;
    int m_suit;
    int m_rank;
};

#endif
