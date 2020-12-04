#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cmath>

#include "IConstante.h"
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

class Management : public sf::Event, public IConstante
{
    public:
        int choiceMenu = INITIALISED_VALUE;
        Management();
        virtual ~Management();

        void mainWindow();
        void startScreen(sf::RenderWindow& windowJeu);
        void menu(sf::RenderWindow & windowJeu);
        void increaseStats(sf::RenderWindow & windowJeu);
        void pauseMenu(sf::RenderWindow & windowJeu);
        void playerAccount(sf::RenderWindow & windowJeu);
        void playerPseudo(sf::RenderWindow & windowJeu,int select);
        void launch(sf::RenderWindow & windowJeu);
        void fightPlanet(sf::RenderWindow & windowJeu,Planet&);
        void screenResult(int result, sf::RenderWindow & windowJeu);
        void mapSpace(sf::RenderWindow & windowJeu);
        void creditGame(sf::RenderWindow &window);
        void initCombat(Planet& pla);

        void showStats(sf::RenderWindow &window);

        void story(sf::RenderWindow & windowJeu);
        void tuto(sf::RenderWindow & windowJeu);
        void drawBattle(sf::RenderWindow& windowJeu);
        string eventFight(Character her, Character bos);
        CharacterHero& getCharHero();
        Universe& getUniverse();
        Spacecraft& getSpaceCraft();
        BiomePlanet& getBiome();
        SpacecraftView& getSpaceCraftView();
        CharacterView& getCharacterView();
        int getNbStory()const;
        void setNbStory(const int nbStory);

        sf::Sprite victory_sprite;
        sf::Texture victory_texture;

    protected:

    private:
        Universe universe;
        Spacecraft spacecraft;
        SpacecraftView spacecraftView;
        BiomePlanet biome;
        CharacterHero hero;
        CharacterView cView;
        BarView barHero;
        BarView barBoss;
        Fight fight;
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

        StatsPlayerView spv;
        int nbStory;
        int lifeHero;
        int shieldHero;
        int lifeBoss;
        int shieldBoss;

};

#endif // GESTION_H
