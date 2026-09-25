#include "Hand.h"

Hand::Hand()
{
    cardVector.reserve(7);
}

Hand::~Hand()
{
    clearHand();
}

void Hand::add(Card* pCard)
{
    cardVector.push_back(pCard);
}

void Hand::clearHand()
{
    std::vector<Card*>::iterator iter;
    for (iter = cardVector.begin(); iter != cardVector.end(); ++iter)
    {
        delete *iter;
        *iter = nullptr;  // good practice
    }
    cardVector.clear();
}

int Hand::getTotal() const
{
    if (cardVector.empty())
        return 0;

    // if first card is face down, total is 0
    if (cardVector[0]->getValue() == 0)
        return 0;

    int total = 0;
    bool containsAce = false;

    std::vector<Card*>::const_iterator iter;
    for (iter = cardVector.begin(); iter != cardVector.end(); ++iter)
    {
        int cardVal = (*iter)->getValue();
        if (cardVal == 1)   // Ace
            containsAce = true;
        total += cardVal;
    }

    // if we have an Ace and counting it as 11 doesn't bust
    if (containsAce && total <= 11)
        total += 10;    // Ace goes from 1 to 11

    return total;
}
