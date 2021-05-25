//
// Created by Marin on 25.5.2021..
//

#include "Menu.h"

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        // handle error
    }

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Dijkstra");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1.8));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("A*");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2.6));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Choose a pathfinding algorithm(arrow up and arrow down)");
    menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 0.5));

    selectedItemIndex = 0;
}

void Menu::draw(sf::RenderWindow &window)
{
    for (const auto & i : menu)
    {
        window.draw(i);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
void Menu::changeToScenarioMenu() {
    menu[3].setString("Choose a scenario (arrow up and arrow down)\nEscape to go back");
    menu[0].setString("Shortest path for ambulance vehicles");
    menu[1].setString("Algorithm visualization");
    selectedMenu = 1;
}
void Menu::changeToAlgorithmMenu() {
    menu[3].setString("Choose a pathfinding algorithm(arrow up and arrow down)");
    menu[0].setString("Dijkstra");
    menu[1].setString("A*");
    selectedMenu = 0;
}