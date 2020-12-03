#ifndef STARTSCREENVIEW_H
#define STARTSCREENVIEW_H
#include "SFML/Graphics.hpp"
#include "Management.h"

#include <iostream>

using std::cout;
using std::endl;


class StartScreenView
{
    public:
        StartScreenView();
        virtual ~StartScreenView();
        StartScreenView(const StartScreenView& other);
        StartScreenView& operator=(const StartScreenView& other);

        void show(Management& man,sf::RenderWindow &window);

    protected:

    private:
        sf::Sprite start_sprite;
        sf::Texture start_texture;
        sf::Text continueKey;
        sf::Font font;
};

#endif // STARTSCREENVIEW_H
