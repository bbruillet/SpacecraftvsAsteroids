#ifndef COMPTE_H
#define COMPTE_H

#define MAX_NUMBER_OF_RACES 5
#include <iostream>
#include <ostream>
#include <string>

#include <cstdio>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;


class Compte
{
    private:
        int selectedItemIndex;
        sf::String playerInput;
        sf::Text playerText;
        sf::Font font;
        sf::Event event;
        sf::Text races[MAX_NUMBER_OF_RACES];
        sf::Sprite compte_sprite;
        sf::Texture compte_texture;

        string pseudo;



    public:
        Compte();
        virtual ~Compte();
        Compte(const Compte& other);
        Compte& operator=(const Compte& other);
        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem();


};

#endif // COMPTE_H
