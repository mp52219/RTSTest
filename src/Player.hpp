//
// Created by Marin on 13.12.2020..
//

#ifndef RTSTEST_PLAYER_HPP
#define RTSTEST_PLAYER_HPP


#include "FindPath.hpp"

class Player : public FindPath, public sf::Sprite {

public:
    Player(int srcO, int dstO, sf::Texture &texture);
    void findPath() override;
    void update(float dt);
    float velocity = 20.f;
};


#endif //RTSTEST_PLAYER_HPP
