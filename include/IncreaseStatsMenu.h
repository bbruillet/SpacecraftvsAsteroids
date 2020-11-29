#ifndef INCREASESTATSMENU_H
#define INCREASESTATSMENU_H
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_INCREASED_STATS 7

class IncreaseStatsMenu
{
    public:
        IncreaseStatsMenu();
        virtual ~IncreaseStatsMenu();
        void draw(sf::RenderWindow &window);
        void moveUp();
        void moveDown();
        int getPressedItem();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
               target.draw(stats_menu_sprite);
        }

    protected:

    private:
        int selectedItemIndex;
        sf::Sprite stats_menu_sprite;
        sf::Texture stats_menu_texture;
        sf::Font font;
        sf::Text statsMenu[MAX_NUMBER_OF_INCREASED_STATS];
};

#endif // INCREASESTATSMENU_H
