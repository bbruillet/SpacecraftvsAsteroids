#ifndef BIOMEPLANETE_H
#define BIOMEPLANETE_H


#include <iostream>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;
using std::string;



class BiomePlanete
{


    private:
        //variable
        string background;
        //sprite
        sf::Sprite biome_sprite;
        sf::Texture biome_texture;

    public:
        //constructeur
        BiomePlanete(const string background="_Background");
        virtual ~BiomePlanete();
        BiomePlanete(const BiomePlanete&);
        BiomePlanete& operator=(const BiomePlanete&);

        //Methode
        void setBackground(const string &);
        void draw(sf::RenderWindow& window);




};

#endif // BIOMEPLANETE_H
