//
// Created by Marin on 13.12.2020..
//

#ifndef RTSTEST_GLOBALGAMEVARIABLES_HPP
#define RTSTEST_GLOBALGAMEVARIABLES_HPP
#include <SFML/Graphics.hpp>
#include <list>

extern const int gameSize;
extern const int tileSize;
extern sf::RenderWindow screen;
extern const int screenSize;
extern sf::Event event;
extern sf::Color color;
extern sf::CircleShape circle;
extern sf::Clock clk;
extern sf::View view1;
extern const int MAX;
extern const int EFS;
extern const int EFS2;
extern char map[];
extern char map2[];
extern int slow;
extern int isAStar;
extern int isVisualization;
#endif //RTSTEST_GLOBALGAMEVARIABLES_HPP
