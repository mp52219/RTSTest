//
// Created by Marin on 13.12.2020..
//

#include <iostream>
#include "Player.hpp"
#include "GlobalGameVariables.hpp"


void Player::update(float dt) {
    Player::setSrc(((int) this->getPosition().y / tileSize) * EFS + ((int) this->getPosition().x / tileSize));
    if(map[src] == '*'){
        if(map[src + 1]!= '*')
            src = src + 1;
        else if(map[src - 1]!= '*')
            src = src - 1;
        else if(map[src - (EFS+1)]!= '*')
            src = src - (EFS+1);
        else if(map[src - (EFS-1)]!= '*')
            src = src - (EFS-1);
        else if(map[src + (EFS+1)]!= '*')
            src = src + (EFS+1);
        else if(map[src + (EFS-1)]!= '*')
            src = src + (EFS-1);
        else if(map[src - EFS]!= '*')
            src = src - EFS;
        else if(map[src + EFS]!= '*')
            src = src + EFS;
    }
    if(!retList.empty()){
        float tempVelocity = velocity;
        if((((retList.front() % EFS) * tileSize) - ((src % EFS) * tileSize)) == (((retList.front() / EFS) * tileSize) - ((src / EFS) * tileSize)))
            tempVelocity = velocity/1.4f;
        if(map[retList.front()]== '+')
            tempVelocity = velocity/(slow/10.f);
        //when moving in a horizontal or vertical line
        this->move(dt*tempVelocity * (((retList.front() % EFS) * tileSize) - getPosition().x),
                   dt*tempVelocity * (((retList.front() / EFS) * tileSize) - getPosition().y));
        //tempVelocity = velocity;
        if(std::abs(getPosition().x - (retList.front() % EFS) * tileSize) < 10.f &&
                std::abs(getPosition().y - (retList.front() / EFS) * tileSize) < 10.f){
            retList.pop_front();
        }
    }
}

Player::Player(int srcO, int dstO, sf::Texture &texture) : FindPath(srcO, dstO), Sprite{texture}{
}

void Player::findPath() {
    FindPath::findPath();
}
