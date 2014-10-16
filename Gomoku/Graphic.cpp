
#include "Graphic.hpp"

Graphic::Graphic() {
    game = new Gomoku();
    _event = new SDL_Event();
}

Graphic::~Graphic() {
    delete game;
}

int Graphic::getKey() {
    while (SDL_PollEvent(_event)) {
        switch (_event->type) {
            case SDL_QUIT:
                return ESCAPE;
            case SDL_MOUSEBUTTONUP:
                clicX = _event->button.x;
                clicY = _event->button.y;
                return CLIC;
            case SDL_KEYDOWN:
                switch (_event->key.keysym.sym) {
                    case SDLK_UP:
                        return UP;
                    case SDLK_DOWN:
                        return DOWN;
                    case SDLK_ESCAPE:
                        return ESCAPE;
                    case SDLK_SPACE:
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

void Graphic::handleGame() {
    while (game->createPlayer(launchMenu()) != -1)
        launchGame();    
}

void Graphic::displayMenu(const int& active) {
    for (int i = 0; i != 3 ; i++) {
        SDL_Rect rect;
        rect.x = 125;
        rect.y = 250 + i * 150;
        rect.h = 100;
        rect.w = 500;
        if (active == i + 1)
            SDL_FillRect(_screen, &rect, SDL_MapRGB(_screen->format, 255, 255, 255));
        else
            SDL_FillRect(_screen, &rect, SDL_MapRGB(_screen->format, 0, 0, 255));
        SDL_Flip(_screen);
    }
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
        SDL_Delay(200);        
    }
}

void Graphic::drawLine() {
    SDL_Rect rect[19 + 19];
    
    for (int i = 0; i != 19 + 19; i++) {
        if (i < 19) {
            rect[i].x = 75 - 1;
            rect[i].y = 74 + (i * BLOCK_SIZE) - 1;
            rect[i].w = BLOCK_SIZE * 19;
            rect[i].h = 1;
            std::cout << i << std::endl;
        }
        else {
            rect[i].x = 75 + ((i - 19) * BLOCK_SIZE) - 1;
            rect[i].y = 75 - 1;
            rect[i].w = 1;
            rect[i].h = BLOCK_SIZE * 19;            
        }
        SDL_FillRect(_screen, &(rect[i]), SDL_MapRGB(_screen->format, 0, 0, 0));
    }
    SDL_Flip(_screen);
}

void Graphic::drawSquare() {
    std::vector<t_flag> map = game->getMap();
    int cpt = 0;
    SDL_Rect rect[19 * 19];
    
    for (std::vector<t_flag>::iterator it = map.begin(); it != map.end(); ++it) {
        rect[cpt].x = 75 + ((cpt % 19) * BLOCK_SIZE);
        rect[cpt].y = 75 + ((cpt / 19) * BLOCK_SIZE);
        rect[cpt].h = BLOCK_SIZE;
        rect[cpt].w = BLOCK_SIZE;
        SDL_FillRect(_screen, &(rect[cpt]), SDL_MapRGB(_screen->format, 255, 255, 255));
        cpt++;
    }
    drawLine();
    SDL_Flip(_screen);
}

void Graphic::launchGame() {
    int key;
    while (game->getWinner() == 0) {
        drawSquare();
        key = getKey();
        if (key == ESCAPE)
            return;
        
        SDL_Delay(200);
    }
}



