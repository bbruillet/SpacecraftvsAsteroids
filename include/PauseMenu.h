#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include "SFML/Graphics.hpp"
#include "Management.h"

/*
    A static members data is defined here
*/
#define MAX_NUMBER_OF_TEXTS 4

/*
    This class is used to show the pause menu (by pressing escape in the universe)
*/

class PauseMenu
{
    private:
        /*
            These members data are used as text, load font, knwowing a selected index, and as sprite and texture
        */
        int selectedItemIndex;
        sf::Sprite pause_menu_sprite;
        sf::Texture pause_menu_texture;
        sf::Font font;
        sf::Text pauseMenu[MAX_NUMBER_OF_TEXTS];

    public:
        /*
            The 2 next lines are :
                - constructor
                - destructor
        */
        PauseMenu();
        virtual ~PauseMenu();

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

#endif // PAUSEMENU_H
