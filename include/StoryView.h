#ifndef STORYVIEW_H
#define STORYVIEW_H
#include "Management.h"
#include "SFML/Graphics.hpp"

#include <iostream>

using std::cout;
using std::endl;


class StoryView
{
    private:
        /*
            Allows to give a texture and position
        */
        sf::Sprite story_sprite;
        sf::Texture story_texture;
        sf::Font font;
        sf::Text intro;
        sf::Text conclu;
        sf::Text continueKey;


    public:
         /*
            The 4 next lines are :
                - construcor
                - destructor
                - copy contructor
                - operator=

            The constructor is defined by default.
        */
        StoryView();
        virtual ~StoryView();
        StoryView(const StoryView& other);
        StoryView& operator=(const StoryView& other);
/*
    This is a function that write the introduction
*/
        void introduction(Management& man,sf::RenderWindow &window);
/*
    This is a function that write the conclusion
*/
        void conclusion(Management& man,sf::RenderWindow &window);
};

#endif // STORYVIEW_H
