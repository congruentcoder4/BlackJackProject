#include "Card.h"

Card::Card(RANK r, SUIT s, bool isUp)
    : rank(r), suit(s), isFaceUp(isUp)
{
    // body intentionally empty (per spec)
}

int Card::getValue() const
{
    if (!isFaceUp)
        return 0;

    int value = 0;
    if (rank > TEN)
        value = 10;          // J, Q, K
    else
        value = static_cast<int>(rank);  // ACE=1 ... TEN=10

    return value;
}

void Card::flip()
{
    isFaceUp = !isFaceUp;
}

std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
    static const char* RANKS[] = { "0", "A", "2", "3", "4", "5", "6",
                                   "7", "8", "9", "10", "J", "Q", "K" };
    static const char* SUITS[] = { "C", "D", "H", "S" };

    if (aCard.isFaceUp)
    {
        os << RANKS[aCard.rank] << SUITS[aCard.suit];
    }
    else
    {
        os << "XX";
    }
    return os;
}
