#ifndef STARTSCREENVIEW_H
#define STARTSCREENVIEW_H
#include "SFML/Graphics.hpp"
#include "Management.h"

#include <iostream>

using std::cout;
using std::endl;

/*
    This class is used to show the first view of the game !!
*/
class StartScreenView
{
    private:
        /*
            This is the sprite & the texture of the background of this menu.
            The text and the font are members data writed on the screen
        */
        sf::Sprite start_sprite;
        sf::Texture start_texture;
        sf::Text continueKey;
        sf::Font font;

    public:
        /*
            The 4 next lines are :
                - constructor
                - destructor
                - copy contructor
                - operator=
        */
        StartScreenView();
        virtual ~StartScreenView();
        StartScreenView(const StartScreenView& other);
        StartScreenView& operator=(const StartScreenView& other);

        /*This function is used to show something according to Management.h*/
        void show(Management& man,sf::RenderWindow &window);
};

#endif // STARTSCREENVIEW_H
