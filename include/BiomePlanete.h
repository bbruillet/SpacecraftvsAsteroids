#ifndef BIOMEPLANETE_H
#define BIOMEPLANETE_H


#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <cstdio>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;
//class Personnage;

class BiomePlanete
{


    private:
        string background;
        //Personnage* personnage;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(biome_sprite);
        }

    public:
        BiomePlanete(const string background="_Background");
        virtual ~BiomePlanete();
        BiomePlanete(const BiomePlanete&);
        BiomePlanete& operator=(const BiomePlanete&);

        void setBackground(const string &);

        sf::Sprite biome_sprite;
        sf::Texture biome_texture;

    protected:


};

#endif // BIOMEPLANETE_H
