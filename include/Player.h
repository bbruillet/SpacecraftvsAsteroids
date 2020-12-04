#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdio>
#include "CharacterHero.h"
#include "Management.h"

/*
    3 static members data is defined here
*/
#define MAX_NUMBER_OF_RACES 5
#define MAX_NUMBER_OF_NAMES 3
#define MAX_NUMBER_OF_STATS 7

using std::cout;
using std::endl;
using std::string;
using std::to_string;

/*
    It is where a user will choose his hero and his pseudo
*/
class Player
{
    private:
        /*
            These members data are used as text, load font, knwowing a selected index, as event, and as sprite and texture
        */
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

        /*
            These 2 members data are used to know the pseudo of the user
            (It allows the user to enter his own pseudo !)
        */
        sf::Text playerText;
        sf::String playerInput;

        /*
            The pseudo will be stocked !
            There is a hero too (to be choosed by the user)
        */
        string pseudo;
        CharacterHero her;


    public:
        /*
            The 4 next lines are :
                - constructor
                - destructor
                - copy constructor
                - operator=
        */
        Player();
        virtual ~Player();
        Player(const Player& other);
        Player& operator=(const Player& other);

        /*
            These are the getter and setter of the pseudo
        */
        string getPseudo() const;
        void setPseudo(const string &);

        /*
            It is used to know which element is selected (not pressed !!!)
        */
        int getSelectedItemIndex() const;

        /*
            This function is used to draw in the window
        */
        void draw(sf::RenderWindow &window);

        /*
            This is the function used to enter the pseudo of a user
        */
        void pseudoPlayer(Management& man ,sf::RenderWindow &window);

        /*
            These functions are used to move up and down between choices
        */
        void moveUp();
        void moveDown();

        /*This function is used to know the pressed item*/
        int getPressedElement();
        void setPressedElement(int selectedItemIndex);

        /*This function is used to know the stats of a hero*/
        void getStats(CharacterHero& her);

        /*This function is used to show something according to Management.h*/
        void show(Management& man,sf::RenderWindow& window);
};

#endif // PLAYER_H
