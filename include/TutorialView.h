#ifndef TUTORIALVIEW_H
#define TUTORIALVIEW_H

#include "Management.h"
#include "SFML/Graphics.hpp"

/*
    This is the tutorial --> How to play ?
*/
class TutorialView
{
    public:
        /*
            The 2 next lines are :
                - construcor
                - copy contructor
            The constructor is defined by default.
        */
        TutorialView();
        virtual ~TutorialView();
        /*
            This is a function that draw the window
        */
        void draw(Management& man,sf::RenderWindow &window);

    private:
        /*
            It’s the texture and the font of the tutorial
        */
        sf::Sprite tuto_sprite;
        sf::Texture tuto_texture;
        sf::Font font;
        sf::Text tuto[2];
        sf::Text continueKey;
};

#endif // TUTORIALVIEW_H
