#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cmath>
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
#include "Fight.h"
#include "StatsPlayerView.h"

using std::vector;
/*
    This is the most important class !
    It's our "main" class.
*/
class Management : public sf::Event
{
    private:
        sf::RenderWindow* windowGame;
        /*
            These are pointers from our classes
            AIP -- > Agrégation interne par pointeur
        */
        Universe* universe;
        Spacecraft* spacecraft;
        SpacecraftView* spacecraftView;
        BiomePlanet* biome;
        CharacterHero* hero;
        CharacterView* cView;
        BarView* barHero;
        BarView* barBoss;
        Fight* fight;
        StatsPlayerView* spv;

        /*
            These are fonts, texts, sprites and textures
        */
        sf::Text tutorial;
        sf::Font font;
        sf::Font fontFight;
        sf::Text textLifeHero;
        sf::Text textLifeBoss;
        sf::Text textShieldHero;
        sf::Text textShieldBoss;
        sf::Sprite versus_sprite;
        sf::Texture versus_texture;
        sf::Text textHero;
        sf::Text textBoss;
        sf::Text textAttackEvent;
        sf::Sprite victory_sprite;
        sf::Texture victory_texture;

        /*
            These are members data
        */
        /*This memebr data is used to know if there is a victory or a loss*/
        int nbStory;
        int lifeHero;
        int shieldHero;
        int lifeBoss;
        int shieldBoss;


    public:
        /*
            These 2 lines are de constructor and the destructor
        */
        Management();
        virtual ~Management();

        /*
            These functions are used to display every windows from classes (or gameplay)
        */
        void mainWindow();
        void startScreen();
        void menu();
        void increaseStats();
        void pauseMenu();
        void playerAccount();
        void playerPseudo(int select);
        void launch();
        void fightPlanet(Planet&);
        void screenResult(int result);
        void mapSpace();
        void creditGame();
        void initCombat(Planet& pla);
        void showStats();
        void story();
        void tuto();
        void drawBattle();

        /*
            Getters and setters
        */
        CharacterHero& getCharHero();
        Universe& getUniverse();
        Spacecraft& getSpaceCraft();
        BiomePlanet& getBiome();
        SpacecraftView& getSpaceCraftView();
        CharacterView& getCharacterView();
        int getNbStory()const;
        void setNbStory(const int nbStory);
        sf::Texture getVictory_texture() const;
        sf::Sprite getVictory_sprite() const;
        void setSpriteVictory();
        void setVictoryTexture();
        void setLoseTexture();
};

#endif // GESTION_H
