#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdio>

#include"CharacterHero.h"

#define MAX_NUMBER_OF_RACES 5
#define MAX_NUMBER_OF_NAMES 3
#define MAX_NUMBER_OF_STATS 7

using std::cout;
using std::endl;
using std::string;
using std::to_string;

class Player
{
    //Variables
    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Event event;
        sf::Text races[MAX_NUMBER_OF_RACES];
        sf::Text names[MAX_NUMBER_OF_NAMES];
        sf::Text stats[MAX_NUMBER_OF_STATS];
        sf::Sprite player_sprite;
        sf::Texture player_texture;
        sf::Sprite character_sprite;
        sf::Texture character_texture;

        sf::Text playerText;
        sf::String playerInput;

        string pseudo;
        CharacterHero her;


    public:
        //Constructeur
        Player();
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        //Getter et setter de pseudo
        string getPseudo() const;
        void setPseudo(const string &);
        int getSelectedItemIndex() const;

        //Méthode permettant de dessiner
        void draw(sf::RenderWindow &window);
        void pseudoPlayer(sf::RenderWindow &window);
        void moveUp();
        void moveDown();
        int getPressedElement();
        void getStats(CharacterHero her);
};

#endif // PLAYER_H
