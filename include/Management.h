#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "IConstante.h"

#include <SFML/Graphics.hpp>
#include "BiomePlanet.h"
#include "Universe.h"
#include "Spacecraft.h"
#include "SpacecraftView.h"
#include "BarView.h"
#include "CharacterBoss.h"
#include "CharacterHero.h"
#include "CharacterView.h"
#include "Character.h"
#include "Planet.h"
#include "Player.h"
#include "Fight.h"
#include <vector>
#define MAX_NUMBER_OF_STUDENTS 4

using std::vector;

class Management : public sf::Event, public IConstante
{
    public:
        int choiceMenu = INITIALISED_VALUE;
        Management();
        virtual ~Management();

        void mainWindow(); //Window windowjeu
        void menu(sf::RenderWindow & windowJeu);
        void increaseStats(sf::RenderWindow & windowJeu);
        void pauseMenu(sf::RenderWindow & windowJeu);
        void playerAccount(sf::RenderWindow & windowJeu);
        void playerPseudo(sf::RenderWindow & windowJeu);
        void launch(sf::RenderWindow & windowJeu);
        void fightPlanet(sf::RenderWindow & windowJeu,Planet&);
        void screenResult(int result, sf::RenderWindow & windowJeu);
        void mapSpace(sf::RenderWindow & windowJeu);
        void creditGame(sf::RenderWindow &window);

        string eventFight(Character her, Character bos);



        sf::Sprite versus_sprite;
        sf::Texture versus_texture;


    protected:

    private:
        Universe universe;
        Spacecraft spacecraft;
        SpacecraftView spacecraftView;
        CharacterHero hero;
        CharacterView cView;
        BarView barHero;
        BarView barBoss;
        Player player;
        Fight fight;
        sf::Text credit[MAX_NUMBER_OF_STUDENTS];
        sf::Font font;
        sf::Font fontFight;
        sf::Text textLifeHero;
        sf::Text textLifeBoss;
//        vector <Planete*> planetes;
//        vector <Planete*> planetesInacc;

};

#endif // GESTION_H
