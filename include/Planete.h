#ifndef PLANETE_H
#define PLANETE_H

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

class Planete : public sf::Drawable
{
    private:

        string nom;
        string image;
        int x, y;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(planete_sprite);
        }

    public:
        Planete(string nom, string image, int x, int y);
        virtual ~Planete();

        sf::Sprite planete_sprite;
        sf::Texture planete_texture;


//        string nom_fichier[2];
//
//        std::vector<sf::Sprite> sprites;
//        std::vector<sf::Texture> textures;

        Planete();
//        void load();

};

#endif // PLANETE_H
