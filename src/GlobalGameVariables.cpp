//
// Created by Marin on 13.12.2020..
//
#include "GlobalGameVariables.hpp"
const int gameSize = 1020;
const int tileSize = 10;
sf::RenderWindow screen(sf::VideoMode(800, 800), "Hello SFML");
sf::Event event;
sf::Color color(sf::Color::Black);
sf::CircleShape circle(200);
sf::Clock clk;
sf::View view1(sf::FloatRect(0.f, gameSize - 10.f * tileSize, 10.f * tileSize, 10.f * tileSize));
const int MAX = gameSize;
const int EFS = gameSize / tileSize;
const int EFS2 = EFS * EFS;
char map[EFS2];
char map2[EFS2];
