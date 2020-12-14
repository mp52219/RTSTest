#include <iostream>
#include <list>
#include "FindPath.hpp"
#include "GlobalGameVariables.hpp"
#include "Player.hpp"

int main() {
    for (int i = 0; i < EFS2; i++) {
        map[i] = '-';
    }
    int src = 0;
    int dst = 0;

    sf::RectangleShape rec;
    sf::Vector2i mapPosition;
    sf::Vector2f position;
    sf::Clock clock;
    sf::Texture texture;
    std::list<int> path;
    int scrollSpeed = 300;
    texture.loadFromFile(R"(C:\Users\Marin\CLionProjects\RTSTest\src\assets\redCircle.png)");
    float dt;
    Player player(0, 0, texture);
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
        path = player.retList;
        while (screen.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed) {
                screen.close();
            }
            //std::cout << dt << std::endl;

            if (event.type == sf::Event::EventType::MouseButtonPressed) {

                if (event.mouseButton.button == sf::Mouse::Left) {
                    for(int p : path){
                        std::cout<<p<<  " ";
                    }
                    //player.src = ((int) position.y / tileSize) * EFS + ((int) position.x / tileSize);
                } else if (event.mouseButton.button == sf::Mouse::Right) {
                    player.dst = ((int) position.y / tileSize) * EFS + ((int) position.x / tileSize);
                    sf::Thread thread(&Player::findPath, &player);
                    thread.launch();
                    path = player.retList;
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
        }
        screen.setView(view1);
        screen.clear(color);
        sf::Vector2f size;
        sf::Vector2f pos;
        size.x = tileSize;
        size.y = tileSize;
        rec.setSize(size);
        /*rec.setFillColor(sf::Color(150, 150, 150));
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
        }*/
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
        player.update(dt);
        screen.draw(player);
        screen.display();

    }
}
