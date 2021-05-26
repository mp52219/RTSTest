//
// Created by Marin on 13.12.2020..
//

#ifndef RTSTEST_UNIT_HPP
#define RTSTEST_UNIT_HPP


#include "FindPath.hpp"

class Unit : public FindPath, public sf::Sprite {

public:
    Unit(int srcO, int dstO, sf::Texture &texture);
    void findPath() override;
    void update(float dt);
    float velocity = 30.f;
    bool isSelected = false;

    sf::Vector2f trueDest;
};


#endif //RTSTEST_UNIT_HPP
