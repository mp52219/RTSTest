//
// Created by Marin on 25.5.2021..
//

#ifndef RTSTEST_MENU_H
#define RTSTEST_MENU_H

#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
    Menu(float width, float height);

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    void changeToScenarioMenu();
    void changeToAlgorithmMenu();
    int GetPressedItem() const { return selectedItemIndex; }
    int GetSelectedMenu() const { return selectedMenu; }

private:
    int selectedMenu = 0;
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS+1];

};
#endif //RTSTEST_MENU_H
