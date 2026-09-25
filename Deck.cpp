#include "Deck.h"
#include <algorithm>   // random_shuffle
#include <iostream>

Deck::Deck()
{
    cardVector.reserve(52);
    populate();
}

Deck::~Deck()
{
}

void Deck::populate()
{
    clearHand();

    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
        {
            add(new Card(static_cast<Card::RANK>(r),
                         static_cast<Card::SUIT>(s)));
        }
    }
}

void Deck::shuffle()
{
    std::random_shuffle(cardVector.begin(), cardVector.end());
}

void Deck::deal(Hand& aHand)
{
    if (!cardVector.empty())
    {
        aHand.add(cardVector.back());
        cardVector.pop_back();
    }
    else
    {
        std::cout << "Out of cards. Unable to deal.\n";
    }
}

void Deck::additionalCards(GenericPlayer& aGenericPlayer)
{
    while (!aGenericPlayer.isBusted() && aGenericPlayer.isHitting())
    {
        deal(aGenericPlayer);
        std::cout << aGenericPlayer << std::endl;

        if (aGenericPlayer.isBusted())
            aGenericPlayer.bust();
    }
}
