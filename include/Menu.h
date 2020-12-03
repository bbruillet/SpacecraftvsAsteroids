#pragma once
#include "SFML/Graphics.hpp"
#include "Management.h"

/*
    A static members data is defined here
*/
#define MAX_NUMBER_OF_ITEMS 3

/*
    This class is used to show the menu
*/
class Menu
{
    private:
        /*
            These members data are used as text, load font, knwowing a selected index, and as sprite and texture
        */
        int selectedItemIndex;
        sf::Sprite menu_sprite;
        sf::Texture menu_texture;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];


    public:
        /*
            The 2 next lines are :
                - constructor
                - destructor
        */
        Menu();
        ~Menu();

        /*
            This function is used to draw in the window
        */
        void draw(sf::RenderWindow &window);

        /*
            This function is used to draw in the window
        */
        void moveUp();
        void moveDown();

        /*This function is used to know the pressed item*/
        int getPressedItem();

        /*This function is used to show something according to Management.h*/
        void show(Management& man,sf::RenderWindow &window);
};
