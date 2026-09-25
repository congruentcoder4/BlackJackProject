#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const std::string& name)
    : name(name)
{
}

GenericPlayer::~GenericPlayer()
{
}

bool GenericPlayer::isBusted() const
{
    return (getTotal() > 21);
}

void GenericPlayer::bust() const
{
    std::cout << name << " busts.\n";
}

std::string GenericPlayer::getName() const
{
    return name;
}

void GenericPlayer::setName(const std::string& newName)
{
    name = newName;
}

std::ostream& operator<<(std::ostream& os, const GenericPlayer& aPlayer)
{
    os << aPlayer.name << "\t";

    if (!aPlayer.cardVector.empty())
    {
        std::vector<Card*>::const_iterator iter;
        for (iter = aPlayer.cardVector.begin();
             iter != aPlayer.cardVector.end(); ++iter)
        {
            os << *(*iter) << "\t";   // uses Card << operator
        }

        int total = aPlayer.getTotal();
        if (total != 0)
            os << "(" << total << ")";
    }
    else
    {
        os << "<empty>";
    }

    return os;
}
