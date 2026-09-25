#pragma once
#include "Deck.h"
#include "House.h"
#include "Player.h"
#include <string>

class Game
{
public:
    Game(const std::string& name);
    ~Game();

    void play();

private:
    Deck deck;
    House house;
    Player player;
};
