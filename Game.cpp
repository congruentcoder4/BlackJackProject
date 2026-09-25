#include "Game.h"
#include <iostream>

Game::Game(const std::string& name)
    : deck(), house("House"), player(name)
{
    // spec says: setName, then populate & shuffle
    player.setName(name);
    deck.populate();
    deck.shuffle();
}

Game::~Game()
{
}

void Game::play()
{
    // deal initial 2 cards each
    for (int i = 0; i < 2; ++i)
    {
        deck.deal(player);
        deck.deal(house);
    }

    house.flipFirstCard();  // hide first card

    std::cout << player << std::endl;
    std::cout << house << std::endl;

    // give player additional cards
    deck.additionalCards(player);

    // reveal dealer's first card
    house.flipFirstCard();
    std::cout << std::endl << house << std::endl;

    // give house additional cards
    deck.additionalCards(house);

    if (house.isBusted())
    {
        if (!player.isBusted())
            player.win();
    }
    else
    {
        if (!player.isBusted())
        {
            int playerTotal = player.getTotal();
            int houseTotal  = house.getTotal();

            if (playerTotal > houseTotal)
                player.win();
            else if (playerTotal < houseTotal)
                player.lose();
            else
                player.push();
        }
    }

    // clear hands
    player.clearHand();
    house.clearHand();
}
