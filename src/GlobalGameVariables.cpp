//
// Created by Marin on 13.12.2020..
//
#include "GlobalGameVariables.hpp"
const int tileSize = 32;
const int gameSize = tileSize*80;
const int screenSize = 800;
sf::RenderWindow screen(sf::VideoMode(screenSize, screenSize), "Hello SFML");
sf::Event event;
sf::Color color(sf::Color::Black);
sf::CircleShape circle(200);
sf::Clock clk;
sf::View view1(sf::FloatRect(0.f, 0/*gameSize - 10.f * tileSize*/, 30.f * tileSize, 30.f * tileSize));
const int MAX = gameSize;
const int EFS = gameSize / tileSize;
const int EFS2 = EFS * EFS;
char map[EFS2];
char map2[EFS2];
int slow = 20;
int isAStar = 0;
int isVisualization = 0;
//TODO REMOVE EXCESS