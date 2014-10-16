
#include "Graphic.hpp"

Graphic::Graphic() {
    game = new Gomoku();
    _event = new SDL_Event();
}

Graphic::~Graphic() {
    delete game;
}

int Graphic::getKey() const {
    while (SDL_PollEvent(_event)) {
        switch (_event->type) {
            case SDL_QUIT:
                return ESCAPE;
            case SDL_KEYDOWN:
                switch (_event->key.keysym.sym) {
                    case SDLK_UP:
                        return UP;
                    case SDLK_DOWN:
                        return DOWN;
                    case SDLK_ESCAPE:
                        return ESCAPE;
                    case SDLK_INSERT:
                        return ENTER;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    return (-1);
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

void Graphic::displayMenu(const int& active) {
    SDL_Rect rect;
    SDL_Rect rect2;
    SDL_Rect rect3;
    rect.x = 125;
    rect.y = 250;
    rect.h = 100;
    rect.w = 500;
    rect2.x = 125;
    rect2.y = 400;
    rect2.h = 100;
    rect2.w = 500;
    rect3.x = 125;
    rect3.y = 550;
    rect3.h = 100;
    rect3.w = 500;
    if (active == 1)
        SDL_FillRect(_screen, &rect, SDL_MapRGB(_screen->format, 255, 255, 255));
    else
        SDL_FillRect(_screen, &rect, SDL_MapRGB(_screen->format, 0, 0, 255));
    if (active == 2)
        SDL_FillRect(_screen, &rect2, SDL_MapRGB(_screen->format, 255, 255, 255));
    else
        SDL_FillRect(_screen, &rect2, SDL_MapRGB(_screen->format, 0, 0, 255));
    if (active == 3)
        SDL_FillRect(_screen, &rect3, SDL_MapRGB(_screen->format, 255, 255, 255));
    else
        SDL_FillRect(_screen, &rect3, SDL_MapRGB(_screen->format, 0, 0, 255));
        
}

void Graphic::activeUpdate(int *active) {
    if (*active > 3)
        *active = 1;
    if (*active < 1)
        *active = 3;
}


int Graphic::launchMenu() {
//    int i;
    int active = 1;
    int key;
    
    this->_height = 19 * BLOCK_SIZE + 150;
    this->_width = 19 * BLOCK_SIZE + 150;
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
        throw(MyException("launchMenu", "Can't init sdl"));
    this->_screen = SDL_SetVideoMode(_width, _height, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Gomoku Menu", NULL);
//    std::cout << "Bienvenue dans le menu, quel mode ?" << std::endl;
//    std::cin >> i;
//    if (i != 1)
//        return -1;
//    return i;
    while (1) {
        key = getKey();
        if (key == UP)
            active--;
        if (key == DOWN)
            active++;
        if (key == ENTER)
            return active;
        if (key == ESCAPE)
            return -1;
        activeUpdate(&active);
        displayMenu(active);
        SDL_Flip(_screen);
        SDL_Delay(200);
    }
}
