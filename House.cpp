#include "House.h"
#include <iostream>

House::House(const std::string& name)
    : GenericPlayer(name)
{
}

House::~House()
{
}

bool House::isHitting() const
{
    // House hits on 16 or less
    return (getTotal() <= 16);
}

void House::flipFirstCard() const
{
    if (!cardVector.empty())
    {
        cardVector[0]->flip();
    }
    else
    {
        std::cout << "No cards to flip.\n";
    }
}
