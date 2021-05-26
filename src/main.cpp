#include <iostream>
#include <unordered_set>
#include "FindPath.hpp"
#include "GlobalGameVariables.hpp"
#include "Unit.hpp"
#include "CMakeFiles/Menu.h"

int convertToEFS(const sf::Vector2f &position) { return ((int) position.y / tileSize) * EFS + ((int) position.x / tileSize); }

bool isInRect(Unit *unit, sf::Vector2f position, sf::Vector2f rectStart) {
    return
            unit->getPosition().x < position.x && unit->getPosition().x > rectStart.x &&
            unit->getPosition().y < position.y && unit->getPosition().y > rectStart.y ||
            unit->getPosition().x > position.x && unit->getPosition().x < rectStart.x &&
            unit->getPosition().y > position.y && unit->getPosition().y < rectStart.y ||
            unit->getPosition().x > position.x && unit->getPosition().x < rectStart.x &&
            unit->getPosition().y < position.y && unit->getPosition().y > rectStart.y ||
            unit->getPosition().x < position.x && unit->getPosition().x > rectStart.x &&
            unit->getPosition().y > position.y && unit->getPosition().y < rectStart.y;
}

void drawGrid(sf::RectangleShape rec, sf::Vector2f pos) {
    rec.setSize(sf::Vector2f(gameSize, 1.5f));
    rec.setFillColor(sf::Color(200, 250, 200, 150));
    pos.x = 0;
    for (int j = tileSize; j < gameSize; j += tileSize) {
        pos.y = j;
        rec.setPosition(pos);
        screen.draw(rec);
    }

    rec.setSize(sf::Vector2f(1.5f, gameSize));
    pos.y = 0;
    for (int k = tileSize; k < gameSize; k += tileSize) {
        pos.x = k;
        rec.setPosition(pos);
        screen.draw(rec);
    }
}

void makeWindowScrollable(const sf::Vector2i &mapPosition, float scrollSpeed, float dt) {
    if (mapPosition.x < 10 && view1.getCenter().x > view1.getSize().x / 2)
        view1.move(-1 * dt * scrollSpeed, 0);
    if (mapPosition.x > screenSize - 10 && view1.getCenter().x < (float)gameSize - view1.getSize().x / 2)
        view1.move(1 * dt * scrollSpeed, 0);
    if (mapPosition.y < 10 && view1.getCenter().y > view1.getSize().y / 2)
        view1.move(0, -1 * dt * scrollSpeed);
    if (mapPosition.y > screenSize - 10 && view1.getCenter().y < (float)gameSize - view1.getSize().y / 2)
        view1.move(0, 1 * dt * scrollSpeed);
}

void resetMap(FindPath *pPath) {
    for (int i = 0; i < EFS2; i++) {
        map[i] = '-';
        map2[i] = '-';
    }
    pPath->retList.clear();

}

sf::Vector2f drawTerrain(sf::RectangleShape &rec) {
    sf::Vector2f pos;
    sf::Vector2f size;
    size.x = tileSize;
    size.y = tileSize;
    rec.setSize(size);
    for (int i = 0; i < EFS2; i++) {
        if (isVisualization) {
            if (map2[i] == '/') {
                rec.setFillColor(sf::Color(0, 255, 190));
                pos.x = (i % EFS) * tileSize;
                pos.y = (i / EFS) * tileSize;
                rec.setPosition(pos);
                screen.draw(rec);
            }
        }
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
    return pos;
}

int main() {
    for (int i = 0; i < EFS2; i++) {
        map[i] = '-';
    }

    sf::RectangleShape rec;
    sf::RectangleShape selectionBox;
    selectionBox.setFillColor(sf::Color(144, 238, 144, 80));
    selectionBox.setOutlineColor(sf::Color(144, 238, 144, 180));
    selectionBox.setOutlineThickness(1);
    sf::Vector2i mapPosition;
    sf::Vector2f position;
    sf::Clock clock;
    sf::Texture texture;
    std::unordered_set<Unit *> units;
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        // error...
    }
    sf::Text tips[5];
    for (int i = 0; i < 5; i++) {
        tips[i].setFont(font);
        tips[i].setFillColor(sf::Color(255, 255, 255, 220));
        tips[i].setPosition(
                sf::Vector2f(screen.getSize().x * 0.7, screen.getSize().y / 5 + i * (screen.getSize().y / 5)));
        tips[i].setOutlineColor(sf::Color::Red);
        tips[i].setOutlineThickness(1.2f);
    }
    tips[0].setString("Drag a box around vehicles to select them\nright click to command movement");
    tips[1].setString("Press and hold A to draw\nimpassable terrain");
    tips[2].setString("Press and hold S to draw\nslowing terrain");
    tips[3].setString("Press and hold D \nto delete terrain");
    tips[4].setString("Press delete to delete\nall terrain");
    float scrollSpeed = 500.f;
    bool isPressed = false;
    bool inGame = false;
    screen.setVerticalSyncEnabled(true);
    screen.setFramerateLimit(60);
    Menu menu(screen.getSize().x / 4, screen.getSize().y);
    sf::Vector2f rectStart;
    texture.loadFromFile("ambulance.png");
    float dt;
    auto *path = new FindPath(0, 0);
    Unit unit1(80, 80, texture);//TODO MAKE A LOOP
    Unit unit2(112, 112, texture);
    Unit unit3(144, 80, texture);
    Unit unit4(176, 112, texture);
    Unit unit5(80, 112, texture);
    Unit unit6(112, 144, texture);
    Unit unit7(80, 176, texture);
    Unit unit8(144, 144, texture);
    units.insert(&unit1);
    units.insert(&unit2);
    units.insert(&unit3);
    units.insert(&unit4);
    units.insert(&unit5);
    units.insert(&unit6);
    units.insert(&unit7);
    units.insert(&unit8);
    while (screen.isOpen()) {
        mapPosition = sf::Mouse::getPosition(screen);
        position = screen.mapPixelToCoords(mapPosition);
        if (inGame)
            makeWindowScrollable(mapPosition, scrollSpeed, dt);
        dt = clock.restart().asSeconds();
        if (!inGame) {
            while (screen.pollEvent(event)) {
                if (event.type == sf::Event::EventType::Closed) {
                    screen.close();
                }
                if (event.type == sf::Event::KeyPressed) {
                    switch (event.key.code) {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;

                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;
                        case sf::Keyboard::Escape:
                            if (menu.GetSelectedMenu() == 1)
                                menu.changeToAlgorithmMenu();
                            break;
                        case sf::Keyboard::Return:
                            switch (menu.GetPressedItem()) {
                                case 0:
                                    if (menu.GetSelectedMenu() == 0) {
                                        isAStar = 0;
                                        menu.changeToScenarioMenu();
                                    } else {
                                        isVisualization = 0;
                                        tips[0].setString(
                                                "Drag a box around vehicles to select them\nright click to command movement");
                                        inGame = true;
                                    }
                                    break;
                                case 1:
                                    if (menu.GetSelectedMenu() == 0) {
                                        isAStar = 1;
                                        menu.changeToScenarioMenu();
                                    } else {
                                        isVisualization = 1;
                                        tips[0].setString(
                                                "Left click to select starting point\nright click to set destination");
                                        inGame = true;
                                    }
                                    break;
                                case 2:
                                    screen.close();
                                    break;
                            }

                            break;
                    }
                }
            }
        } else {
            while (screen.pollEvent(event)) {
                if (event.type == sf::Event::Resized) {
                    view1.setSize({
                                          static_cast<float>(event.size.width),
                                          static_cast<float>(event.size.height)
                                  });
                }
                if (event.type == sf::Event::EventType::Closed) {
                    screen.close();
                }
                if (event.type == sf::Event::KeyPressed) {
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            resetMap(path);
                            view1.setSize(30.f * (float)tileSize, 30.f * (float)tileSize);
                            view1.setCenter(view1.getSize().x / 2, view1.getSize().y / 2);
                            inGame = false;
                            break;
                        case sf::Keyboard::A:
                            map[convertToEFS(position)] = '*';
                            break;
                        case sf::Keyboard::S:
                            map[convertToEFS(position)] = '+';
                            break;
                        case sf::Keyboard::D:
                            map[convertToEFS(position)] = '-';
                            break;
                        case sf::Keyboard::Delete:
                            resetMap(path);
                            break;
                    }

                }
                if (event.type == sf::Event::MouseWheelMoved) {
                    switch (event.mouseWheel.delta) {
                        case 1:
                            view1.setSize(view1.getSize().x * 0.91f, view1.getSize().y * 0.91f);
                            break;
                        case -1:
                            view1.setSize(view1.getSize().x * 1.1f, view1.getSize().y * 1.1f);
                            break;
                    }
                }
                if (event.type == sf::Event::EventType::MouseButtonPressed) {

                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (isVisualization) {
                            if(map[convertToEFS(position)] != '*')
                                path->src = convertToEFS(position);

                        } else {
                            rectStart = position;
                            isPressed = true;
                        }
                    } else if (event.mouseButton.button == sf::Mouse::Right) {
                        if (isVisualization) {
                            path->dst = convertToEFS(position);
                            path->findPath();

                        } else {
                            for (Unit *unit : units) {
                                if (unit->isSelected) {
                                    unit->dst = convertToEFS(position);
                                    sf::Thread thread(&Unit::findPath, unit);
                                    thread.launch();

                                }
                            }
                        }
                    } else if (event.mouseButton.button == sf::Mouse::Middle) {
                        if (map[convertToEFS(position)] == '*')
                            map[convertToEFS(position)] = '-';
                        else
                            map[convertToEFS(position)] = '*';
                    } else if (event.mouseButton.button == sf::Mouse::XButton1) {
                        if (map[convertToEFS(position)] == '+')
                            map[convertToEFS(position)] = '-';
                        else
                            map[((int) position.y / tileSize) * EFS + ((int) position.x / tileSize)] = '+';
                    }
                }
                if (event.type == sf::Event::EventType::MouseButtonReleased) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        if (std::abs(position.x - rectStart.x) < 10 && std::abs(position.y - rectStart.y) < 10) {
                            bool isDone = false;
                            for (Unit *unit : units) {
                                if (unit->getGlobalBounds().contains(position.x, position.y) && !isDone) {
                                    unit->isSelected = true;
                                    isDone = true;
                                } else {
                                    unit->isSelected = false;
                                }
                            }
                        } else {
                            for (Unit *unit : units) {
                                if (isInRect(unit, position, rectStart)) {
                                    unit->isSelected = true;
                                } else {
                                    unit->isSelected = false;
                                }
                            }
                        }
                        isPressed = false;
                    }
                } else if (isPressed) {
                    selectionBox.setPosition(rectStart);
                    selectionBox.setSize(position - rectStart);
                } else {
                    selectionBox.setSize(sf::Vector2f(0.f, 0.f));
                }
            }
        }

        screen.setView(view1);
        screen.clear(color);
        sf::Vector2f pos = drawTerrain(rec);
        if (inGame) {
            drawGrid(rec, pos);
            if (!isVisualization) {
                for (Unit *unit: units) {
                    unit->update(dt);
                    screen.draw(*unit);
                }
                screen.draw(selectionBox);
            }
            if (isVisualization) {
                for (int p : path->retList) {
                    rec.setFillColor(sf::Color(255, 0, 0));
                    pos.x = (p % EFS) * tileSize;
                    pos.y = (p / EFS) * tileSize;
                    rec.setPosition(pos);
                    screen.draw(rec);
                }
            }
            for (const auto &tip : tips) {
                screen.draw(tip);
            }
        }
        if (!inGame) {
            menu.draw(screen);
        }
        screen.display();

    }
}


