#include "Player.h"
#include <iostream>

Player::Player(const std::string& name)
    : GenericPlayer(name)
{
}

Player::~Player()
{
}

bool Player::isHitting() const
{
    char response;
    std::cout << name << ", do you want a hit? (Y/N): ";
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    std::cout << name << " wins.\n";
}

void Player::lose() const
{
    std::cout << name << " loses.\n";
}

void Player::push() const
{
    std::cout << name << " pushes.\n";
}
