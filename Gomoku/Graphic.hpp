/* 
 * File:   Graphic.hpp
 * Author: benjamin
 *
 * Created on October 16, 2014, 2:24 PM
 */

#ifndef GRAPHIC_HPP
#define	GRAPHIC_HPP

#include "Gomoku.hpp"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define BLOCK_SIZE 32

enum keyType {
    UP, DOWN, LEFT, RIGHT, ENTER, ESCAPE
};

class Graphic {
public:
    Graphic();
    ~Graphic();
    void displayMap(std::vector<t_flag> map);
    void launchGame();

private:
    int launchMenu();
    int getKey() const;
    void displayMenu(const int&);
    void activeUpdate(int*);
    Gomoku *game;
    SDL_Event *_event;
    int _height;
    int _width;
    SDL_Surface *_screen;
    
};

#endif	/* GRAPHIC_HPP */

