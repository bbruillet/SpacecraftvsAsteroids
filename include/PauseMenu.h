#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_TEXTS 4

class PauseMenu
{
    public:
        PauseMenu();
        virtual ~PauseMenu();

        void draw(sf::RenderWindow &window);
        void moveUp();
        void moveDown();
        int getPressedItem();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
               target.draw(pause_menu_sprite);
        }

    protected:

    private:
        int selectedItemIndex;
        sf::Sprite pause_menu_sprite;
        sf::Texture pause_menu_texture;
        sf::Font font;
        sf::Text pauseMenu[MAX_NUMBER_OF_TEXTS];
};

#endif // PAUSEMENU_H
