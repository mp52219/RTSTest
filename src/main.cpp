#include <iostream>
#include <list>
#include <unordered_set>
#include "FindPath.hpp"
#include "GlobalGameVariables.hpp"
#include "Unit.hpp"

int main() {
    for (int i = 0; i < EFS2; i++) {
        map[i] = '-';
    }
    sf::RectangleShape rec;
    sf::RectangleShape selectionBox;
    selectionBox.setFillColor(sf::Color(144,238,144,80));
    selectionBox.setOutlineColor(sf::Color(144,238,144,180));
    selectionBox.setOutlineThickness(1);
    sf::Vector2i mapPosition;
    sf::Vector2f position;
    sf::Clock clock;
    sf::Texture texture;
    std::unordered_set<Unit *> units;
    int scrollSpeed = 300;
    bool isPressed = false;
    sf::Vector2f rectStart;
    texture.loadFromFile(R"(C:\Users\Marin\CLionProjects\RTSTest\src\assets\ambulance.png)");
    float dt;
    Unit player(80, 80, texture);
    Unit player2(112, 112, texture);
    units.insert(&player);
    units.insert(&player2);
    for(Unit* unit : units){
        unit->setOrigin(16, 16);
    }
    while (screen.isOpen()) {
        mapPosition = sf::Mouse::getPosition(screen);
        position = screen.mapPixelToCoords(mapPosition);
        if (mapPosition.x < 10)
            view1.move(-1 * dt * scrollSpeed, 0);
        if (mapPosition.x > 790)
            view1.move(1 * dt * scrollSpeed, 0);
        if (mapPosition.y < 10)
            view1.move(0, -1 * dt * scrollSpeed);
        if (mapPosition.y > 790)
            view1.move(0, 1 * dt * scrollSpeed);
        dt = clock.restart().asSeconds();
        while (screen.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed) {
                screen.close();
            }
            if (event.type == sf::Event::EventType::MouseButtonPressed) {

                if (event.mouseButton.button == sf::Mouse::Left) {
                    rectStart = position;
                    isPressed = true;
                } else if (event.mouseButton.button == sf::Mouse::Right) {
                    for (Unit *unit : units) {
                        if (unit->isSelected) {
                            unit->dst = ((int) position.y / tileSize) * EFS + ((int) position.x / tileSize);
                            sf::Thread thread(&Unit::findPath, unit);
                            thread.launch();
                        }
                    }
                } else if (event.mouseButton.button == sf::Mouse::Middle) {
                    if (map[((int) position.y / tileSize) * EFS + ((int) position.x / tileSize)] == '*')
                        map[((int) position.y / tileSize) * EFS + ((int) position.x / tileSize)] = '-';
                    else
                        map[((int) position.y / tileSize) * EFS + ((int) position.x / tileSize)] = '*';
                } else if (event.mouseButton.button == sf::Mouse::XButton1) {
                    if (map[((int) position.y / tileSize) * EFS + ((int) position.x / tileSize)] == '+')
                        map[((int) position.y / tileSize) * EFS + ((int) position.x / tileSize)] = '-';
                    else
                        map[((int) position.y / tileSize) * EFS + ((int) position.x / tileSize)] = '+';
                }
            }
            if (event.type == sf::Event::EventType::MouseButtonReleased) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if(abs(position.x - rectStart.x) < 10 && abs(position.y - rectStart.y) < 10){
                        bool isDone = false;
                        for (Unit *unit : units) {
                            if (unit->getGlobalBounds().contains(position.x, position.y) && !isDone) {
                                unit->isSelected = true;
                                isDone = true;
                            } else {
                                unit->isSelected = false;
                            }
                        }
                    }
                    else {
                        for (Unit *unit : units) {
                            if (unit->getPosition().x < position.x && unit->getPosition().x > rectStart.x &&
                                unit->getPosition().y < position.y && unit->getPosition().y > rectStart.y ||
                                unit->getPosition().x > position.x && unit->getPosition().x < rectStart.x &&
                                unit->getPosition().y > position.y && unit->getPosition().y < rectStart.y ||
                                unit->getPosition().x > position.x && unit->getPosition().x < rectStart.x &&
                                unit->getPosition().y < position.y && unit->getPosition().y > rectStart.y ||
                                unit->getPosition().x < position.x && unit->getPosition().x > rectStart.x &&
                                unit->getPosition().y > position.y && unit->getPosition().y < rectStart.y) {

                                unit->isSelected = true;
                            } else {
                                unit->isSelected = false;
                            }
                        }
                    }
                    isPressed = false;
                }
            }
            else if(isPressed){
                selectionBox.setPosition(rectStart);
                selectionBox.setSize(position - rectStart);
            } else{
                selectionBox.setSize(sf::Vector2f(0.f,0.f));
            }
        }
        screen.setView(view1);
        screen.clear(color);
        sf::Vector2f size;
        sf::Vector2f pos;
        size.x = tileSize;
        size.y = tileSize;
        rec.setSize(size);
        rec.setFillColor(sf::Color(150, 150, 150));
        for (int i = 0; i < gameSize; i += 2 * tileSize) {
            for (int j = 0; j < gameSize; j += 2 * tileSize) {
                pos.x = i;
                pos.y = j;
                rec.setPosition(pos);
                screen.draw(rec);
            }
            for (int k = tileSize; k < gameSize; k += 2 * tileSize) {
                pos.x = i + tileSize;
                pos.y = k;
                rec.setPosition(pos);
                screen.draw(rec);
            }
        }
        for (int i = 0; i < EFS2; i++) {
            /*if (map2[i] == '/') {
                rec.setFillColor(sf::Color(0, 255, 150));
                pos.x = (i % EFS) * tileSize;
                pos.y = (i / EFS) * tileSize;
                rec.setPosition(pos);
                screen.draw(rec);
            }*/
            if (map[i] == '*') {
                rec.setFillColor(sf::Color(0, 255, 0));
                pos.x = (i % EFS) * tileSize;
                pos.y = (i / EFS) * tileSize;
                rec.setPosition(pos);
                screen.draw(rec);
            }
            if (map[i] == '+') {
                rec.setFillColor(sf::Color(0, 0, 255));
                pos.x = (i % EFS) * tileSize;
                pos.y = (i / EFS) * tileSize;
                rec.setPosition(pos);
                screen.draw(rec);
            }

        }

        /*for (int p : path) {
            rec.setFillColor(sf::Color(255, 0, 0));
            pos.x = (p % EFS) * tileSize;
            pos.y = (p / EFS) * tileSize;
            rec.setPosition(pos);
            screen.draw(rec);
        }*/
        for(Unit* unit: units) {
            unit->update(dt);
            screen.draw(*unit);
        }
        screen.draw(selectionBox);
        screen.display();

    }
}
