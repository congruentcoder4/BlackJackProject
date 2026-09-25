#pragma once
#include <vector>
#include "Card.h"

class Hand
{
public:
    Hand();
    virtual ~Hand();

    void add(Card* pCard);
    void clearHand();
    int getTotal() const;

protected:
    std::vector<Card*> cardVector;
};
