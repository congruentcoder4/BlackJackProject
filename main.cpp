#include <iostream>
#include <string>
#include "Game.h"

int main()
{
    std::cout << "Welcome to Blackjack!\n\n";

    std::string name;
    std::cout << "Enter player name: ";
    std::getline(std::cin, name);

    char again = 'y';
    Game game(name);

    while (again == 'y' || again == 'Y')
    {
        game.play();

        std::cout << "\nDo you want to play again? (Y/N): ";
        std::cin >> again;
        std::cin.ignore(1000, '\n');
        std::cout << std::endl;
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}
