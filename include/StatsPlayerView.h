#ifndef STATSPLAYERVIEW_H
#define STATSPLAYERVIEW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdio>

#include"CharacterHero.h"
#define MAX_NUMBER_OF_STATS 7

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class StatsPlayerView
{
    public:
        StatsPlayerView();
        virtual ~StatsPlayerView();
        StatsPlayerView(const StatsPlayerView& other);
        StatsPlayerView& operator=(const StatsPlayerView& other);

        void draw(sf::RenderWindow &window);
        void showStats(CharacterHero her);

    protected:

    private:
        CharacterHero her;
        sf::Font font;
        sf::Text stats[MAX_NUMBER_OF_STATS];
};

#endif // STATSPLAYERVIEW_H
