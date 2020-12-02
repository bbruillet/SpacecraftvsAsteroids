#ifndef STORYVIEW_H
#define STORYVIEW_H
#include "Management.h"
#include "SFML/Graphics.hpp"

class StoryView
{
    private:
        sf::Sprite story_sprite;
        sf::Texture story_texture;
        sf::Font font;
        sf::Text intro;
        sf::Text conclu;
        sf::Text continueKey;


    public:
        StoryView();
        virtual ~StoryView();
        StoryView(const StoryView& other);
        StoryView& operator=(const StoryView& other);
        void introduction(Management& man,sf::RenderWindow &window);
        void conclusion(Management& man,sf::RenderWindow &window);
};

#endif // STORYVIEW_H
