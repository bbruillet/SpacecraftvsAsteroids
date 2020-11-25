#ifndef COMPTE_H
#define COMPTE_H

#define MAX_NUMBER_OF_RACES 5
#define MAX_NUMBER_OF_NAMES 2
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

        sf::Font font;
        sf::Event event;
        sf::Text races[MAX_NUMBER_OF_RACES];
        sf::Text noms[MAX_NUMBER_OF_NAMES];
        sf::Sprite compte_sprite;
        sf::Texture compte_texture;

        sf::Sprite personnage_sprite;
        sf::Texture personnage_texture;


        string pseudo;



    public:
        Compte();
        virtual ~Compte();
        Compte(const Compte& other);
        Compte& operator=(const Compte& other);
        string getPseudo() const;
        void setPseudo(const string &);
        void draw(sf::RenderWindow &window);
        void PseudoUtilisateur(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem();
        sf::Text playerText;
        sf::String playerInput;



};

#endif // COMPTE_H
