/* 
 * File:   Graphic.hpp
 * Author: benjamin
 *
 * Created on October 16, 2014, 2:24 PM
 */

#ifndef GRAPHIC_HPP
#define	GRAPHIC_HPP

#include "Gomoku.hpp"

class Graphic {
public:
    Graphic();
    ~Graphic();
    void displayMap(std::vector<t_flag> map);
    void launchGame();

private:
    int launchMenu();
    Gomoku *game;
};

#endif	/* GRAPHIC_HPP */

