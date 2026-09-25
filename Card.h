#pragma once
#include <iostream>

class Card
{
public:
    enum RANK { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
                EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum SUIT { CLUBS, DIAMONDS, HEARTS, SPADES };

    Card(RANK r = ACE, SUIT s = SPADES, bool isUp = true);

    int getValue() const;
    void flip();

    // for output
    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);

private:
    RANK rank;
    SUIT suit;
    bool isFaceUp;
};
