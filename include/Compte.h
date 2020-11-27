#ifndef COMPTE_H
#define COMPTE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdio>

#define MAX_NUMBER_OF_RACES 5
#define MAX_NUMBER_OF_NAMES 3

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class Compte
{
    //Variables
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

        sf::Text playerText;
        sf::String playerInput;

        string pseudo;


    public:
        //Constructeur
        Compte();
        virtual ~Compte();
        Compte(const Compte& other);
        Compte& operator=(const Compte& other);

        //Getter et setter de pseudo
        string getPseudo() const;
        void setPseudo(const string &);

        //Méthode permettant de dessiner
        void dessiner(sf::RenderWindow &window);
        void PseudoUtilisateur(sf::RenderWindow &window);
        void haut();
        void bas();
        int getElementPresse();
};

#endif // COMPTE_H
