#ifndef INCREASESTATSMENU_H
#define INCREASESTATSMENU_H
#include "SFML/Graphics.hpp"

/*
    A static members data is defined here
*/
#define MAX_NUMBER_OF_INCREASED_STATS 5


/*
    This class is used to show stats menu incrementation
*/
class IncreaseStatsMenu
{
    private:
        /*
            These members data are used as text, load font, knwowing a selected index, and as sprite and texture
        */
        int selectedItemIndex;
        sf::Sprite stats_menu_sprite;
        sf::Texture stats_menu_texture;
        sf::Font font;
        sf::Text statsMenu[MAX_NUMBER_OF_INCREASED_STATS];

    public:
        /*
            The 2 next lines are :
                - constructor
                - destructor
        */
        IncreaseStatsMenu();
        virtual ~IncreaseStatsMenu();

        /*
            This function is used to draw in the window
        */
        void draw(sf::RenderWindow &window);

        /*
            The 2 functions are use to movin up and down in the menu (between word)
        */
        void moveUp();
        void moveDown();

        /*This function is used to know the pressed item*/
        int getPressedItem();
};

#endif // INCREASESTATSMENU_H
