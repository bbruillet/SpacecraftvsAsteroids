#ifndef BIOMEPLANET_H
#define BIOMEPLANET_H


#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;
using std::string;



class BiomePlanet
{


    private:
        //variable
        string background;
        //sprite
        sf::Sprite biome_sprite;
        sf::Texture biome_texture;

    public:
        //constructeur
        BiomePlanet(const string background="_Background");
        virtual ~BiomePlanet();
        BiomePlanet(const BiomePlanet&);
        BiomePlanet& operator=(const BiomePlanet&);

        //Methode
        void setBackground(const string &);
        void drawBiome(sf::RenderWindow& window);




};

#endif // BIOMEPLANETE_H
