#ifndef STATSPLAYERVIEW_H
#define STATSPLAYERVIEW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdio>
#include"CharacterHero.h"

/*
    1 static member data is defined here
*/
#define MAX_NUMBER_OF_SHOW_STATS 8

using std::cout;
using std::endl;
using std::string;
using std::to_string;

/*
    It is where you can see your own stats during game
*/
class StatsPlayerView
{
    private:
        /*
            These are members data used to writes some stuff
        */
        sf::Font font;
        sf::Text stats[MAX_NUMBER_OF_SHOW_STATS];
        sf::Text title;
        sf::Text backKey;

        /*These are sprites and textures used to draw our character's informations and backgrounds*/
        sf::Sprite player_sprite;
        sf::Texture player_texture;
        sf::Sprite character_sprite;
        sf::Texture character_texture;

        /*This member data is the hero*/
        CharacterHero her;

    public:
        /*
            The 4 next lines are :
                - constructor
                - destructor
                - copy constructor
                - operator=
        */
        StatsPlayerView();
        virtual ~StatsPlayerView();
        StatsPlayerView(const StatsPlayerView& other);
        StatsPlayerView& operator=(const StatsPlayerView& other);

        /*
            This function is used to draw in the window
        */
        void draw(sf::RenderWindow &window);

        /*
            This function is used to show statistics
        */
        void showStats(CharacterHero& her);
};

#endif // STATSPLAYERVIEW_H
