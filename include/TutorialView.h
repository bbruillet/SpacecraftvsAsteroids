#ifndef TUTORIALVIEW_H
#define TUTORIALVIEW_H

#include "Management.h"
#include "SFML/Graphics.hpp"


class TutorialView
{
    public:
        TutorialView();
        virtual ~TutorialView();
        void draw(Management& man,sf::RenderWindow &window);

    protected:

    private:
        sf::Sprite tuto_sprite;
        sf::Texture tuto_texture;
        sf::Font font;
        sf::Text tuto[2];
        sf::Text continueKey;
};

#endif // TUTORIALVIEW_H
