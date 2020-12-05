#ifndef BIOMEPLANET_H
#define BIOMEPLANET_H

#include <iostream>
#include <SFML/Graphics.hpp>

using std::string;


/*
    This class is used to cream a biome that'll be associated later with a planet
*/
class BiomePlanet
{
    private:
        /*
            This member data is used to store the directory of biome's picture
        */
        string background;

        /*
            The thow members data are :
                - biome's sprite
                - biome's texture (used by the sprite)
        */
        sf::Sprite biome_sprite;
        sf::Texture biome_texture;

    public:
        /*
            The 4 next lines are :
                - construcor
                - destructor
                - copy contructor
                - operator=

            The constructor is defined by default.
        */
        BiomePlanet(const string background="_Background");
        virtual ~BiomePlanet();
        BiomePlanet(const BiomePlanet&);
        BiomePlanet& operator=(const BiomePlanet&);

        /*
            This function is used to set a background
        */
        void setBackground(const string &);

        /*
            This function is used to draw a biome;
        */
        void drawBiome(sf::RenderWindow& window);




};

#endif // BIOMEPLANET_H
