# Blackjack Project

A command-line Blackjack game written in C++.

## Features

- Standard card ranks and suits
- Deck creation and shuffling
- Player and dealer hands
- Hit and stand gameplay
- Hand value calculation
- Blackjack and bust detection

## Project Structure

- `main.cpp` — starts the game
- `Card.cpp / Card.h` — represents individual cards
- `Deck.cpp / Deck.h` — creates and manages the deck
- `Hand.cpp / Hand.h` — manages cards in a hand
- `Player.cpp / Player.h` — player logic
- `House.cpp / House.h` — dealer logic
- `Game.cpp / Game.h` — controls the game
- `GenericPlayer.cpp / GenericPlayer.h` — shared player behavior

## How to Run

From the project directory, compile the program:

```bash
g++ -std=c++17 -Wall -Wextra -o blackjack \
main.cpp Card.cpp Deck.cpp Game.cpp \
GenericPlayer.cpp Hand.cpp House.cpp Player.cpp
