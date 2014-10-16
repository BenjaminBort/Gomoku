
#include "Gomoku.hpp"
#include "Graphic.hpp"

Gomoku::Gomoku() {
    for (int row = 0; row != 361 ; ++row) {
        _map.push_back(FREE);
    }
}

Gomoku::~Gomoku() {

}

int Gomoku::createPlayer(const int& choice)
{
    if (choice == -1)
        return choice;
    if (choice == 1) {
        playerOne = new Player(HUMAN);
        playerTwo = new Player(HUMAN);
    }
    else {
        playerOne = new Player(HUMAN);
        playerTwo = new Player(IA);        
    }
    return choice;
}