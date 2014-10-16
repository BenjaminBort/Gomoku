/* 
 * File:   Gomoku.hpp
 * Author: benjamin
 *
 * Created on October 16, 2014, 1:56 PM
 */

#ifndef GOMOKU_HPP
#define	GOMOKU_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Exception.hpp"
#include "Player.hpp"

enum t_flag {
    FREE, TEAM_1, TEAM_2
};

class Gomoku
{
public:
    Gomoku();
    ~Gomoku();
    const std::vector<t_flag>& getMap() const {return _map;}
    int getWinner() const {return _winner;}
    int createPlayer(const int &);
    
    void setWinner(const int& t) {_winner = t;}
       
protected:
    std::vector<t_flag> _map;
    Player *playerOne;
    Player *playerTwo;
    int _winner;
};

#endif	/* GOMOKU_HPP */

