//
// Created by Marin on 13.12.2020..
//

#include <iostream>
#include "Unit.hpp"
#include "GlobalGameVariables.hpp"


void Unit::update(float dt) {
    Unit::setSrc(((int) this->getPosition().y / tileSize) * EFS + ((int) this->getPosition().x / tileSize));
    if (map[src] == '*') {
        if (map[src + 1] != '*')
            src = src + 1;
        else if (map[src - 1] != '*')
            src = src - 1;
        else if (map[src - (EFS + 1)] != '*')
            src = src - (EFS + 1);
        else if (map[src - (EFS - 1)] != '*')
            src = src - (EFS - 1);
        else if (map[src + (EFS + 1)] != '*')
            src = src + (EFS + 1);
        else if (map[src + (EFS - 1)] != '*')
            src = src + (EFS - 1);
        else if (map[src - EFS] != '*')
            src = src - EFS;
        else if (map[src + EFS] != '*')
            src = src + EFS;
    }
    if (!retList.empty()) {
        float tempVelocity = velocity;
        if (retList.front() == src - (EFS - 1) || retList.front() == src + (EFS - 1) ||
            retList.front() == src - (EFS + 1) || retList.front() == src + (EFS + 1))
            tempVelocity = velocity / 1.4f;
        if (map[retList.front()] == '+')
            tempVelocity = velocity / (slow / 10.f);
        //when moving in a horizontal or vertical line
        this->move(dt * tempVelocity * (((retList.front() % EFS) * tileSize) - ((src % EFS) * tileSize)),
                   dt * tempVelocity * (((retList.front() / EFS) * tileSize) - ((src / EFS) * tileSize)));
        //tempVelocity = velocity;
        if (src == retList.front()) {
            retList.pop_front();
        }
    }
}

Unit::Unit(int srcO, int dstO, sf::Texture &texture) : FindPath(srcO, dstO), Sprite{texture} {
    this->setPosition(srcO, dstO);
    this->setOrigin(16,16);
}

void Unit::findPath() {
    FindPath::findPath();
}
