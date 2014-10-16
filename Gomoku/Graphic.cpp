
#include "Graphic.hpp"

Graphic::Graphic() {
    game = new Gomoku();
}

Graphic::~Graphic() {
    delete game;
}

void Graphic::displayMap(std::vector<t_flag> map) {
    int i = 0;
    for (std::vector<t_flag>::iterator it = map.begin(); it != map.end(); ++it) {
        if (i % 19 == 0)
            std::cout << std::endl;
        if (*it == FREE)
            std::cout << "0";
        else if (*it == TEAM_1)
            std::cout << "1";
        else
            std::cout << "2";
        i++;
    }
}

void Graphic::launchGame() {
    if (game->createPlayer(launchMenu()) == -1)
        return ;
    
}

int Graphic::launchMenu() {
    int i;
    
    std::cout << "Bienvenue dans le menu, quel mode ?" << std::endl;
    std::cin >> i;
    if (i != 1)
        return -1;
    return i;
}
