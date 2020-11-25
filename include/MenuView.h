#ifndef MENUVIEW_H
#define MENUVIEW_H
#include "SFML/Graphics.hpp"

class MenuView : public sf::Drawable
{
    public:
        MenuView();
        virtual ~MenuView();
        void draw(sf::RenderWindow &window);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
           target.draw(menu_sprite);
        }

    protected:

    private:
        sf::Sprite menu_sprite;
        sf::Texture menu_texture;
};

#endif // MENUVIEW_H
