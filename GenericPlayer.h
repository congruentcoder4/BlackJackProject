#pragma once
#include <string>
#include <iostream>
#include "Hand.h"

class GenericPlayer : public Hand
{
public:
    GenericPlayer(const std::string& name = "");
    virtual ~GenericPlayer();

    virtual bool isHitting() const = 0;  // pure virtual

    bool isBusted() const;
    void bust() const;

    std::string getName() const;
    void setName(const std::string& newName);

    friend std::ostream& operator<<(std::ostream& os,
                                    const GenericPlayer& aPlayer);

protected:
    std::string name;
};
