#include "Management.h"

#include <SFML/Graphics.hpp>

#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>
#include <cmath>


#include "Character.h"
#include "Universe.h"
#include "Planet.h"
#include "Spacecraft.h"
#include "BiomePlanet.h"
#include "CharacterHero.h"
#include "CharacterBoss.h"
#include "Menu.h"
#include "PauseMenu.h"
#include "Player.h"
#include "IncreaseStatsMenu.h"

using namespace std;

Management::Management()
{


    this->universe = universe;
    this->spacecraft = spacecraft;
    vector <Planet*> planets(6);
    vector <Planet*> unreachPlanets(3);
    vector <CharacterBoss*> boss(6);
    planets[0] = new Planet("Bleue", "Images/Planetes/Bleu.png", 2000, 750, -30, 625); //319
    planets[1] = new Planet("Orange", "Images/Planetes/Orange.png", 9000, 1250, 120, 685); //291
    planets[2] = new Planet("Mauve_Detruite", "Images/Planetes/Mauve_Detruite.png", 7000, 5500, 30, 700); //417
    planets[3] = new Planet("Anneau_Rouge", "Images/Planetes/Anneau_Rouge.png", 11000, 3000, 310, 725); //1083
    planets[4] = new Planet("Verte", "Images/Planetes/Verte.png", 5000, 3200, 390, 700); //703
    planets[5] = new Planet("Anneau_Bleu", "Images/Planetes/Anneau_Bleu.png", 1500, 5100, 180, 715); //318

    unreachPlanets[0] = new Planet("Mort", "Images/Planetes/Etoile_De_La_Mort.png", 8000, 6120, 0, 0);
    unreachPlanets[1] = new Planet("Plateforme", "Images/Planetes/Plateforme.png", 6900, 3300, 0, 0);
    unreachPlanets[2] = new Planet("Soleil", "Images/Planetes/Soleil.png", 12000, 0, 0, 0);

    boss[0] = new CharacterBoss("Oblumandias",BLUE);
    boss[1] = new CharacterBoss("Mof Tarkin the great",ORANGE);
    boss[2] = new CharacterBoss("BossMauve",PURPLE_DESTROYED);
    boss[3] = new CharacterBoss("BossRouge",RING_RED);
    boss[4] = new CharacterBoss("BossVert",GREEN);
    boss[5] = new CharacterBoss("Zanentia",RING_BLUE);


    for ( size_t i = 0; i < planets.size(); i++ )
    {
        for ( size_t j = 0; j < boss.size(); j++ )
        {
            if(boss[j]->getOrigin() == i){
                planets[i]->giveBoss(*boss[j]);
            }
        }
        universe.add(planets[i]);
    }

    for ( size_t i = 0; i < unreachPlanets.size(); i++ )
    {
        universe.addUnreachable(unreachPlanets[i]);
    }



}

void Management::mainWindow()
{
    /*MUSIQUE*/
    sf::SoundBuffer Buffer;
    if (!Buffer.loadFromFile("Musiques/Musique_Menu.wav"))
    {
        cout << "Problem while loading the sound" <<endl;
    }
    sf::Sound sound;
    sound.setBuffer(Buffer);

    sound.setLoop(true);
    sound.play();

    sf::RenderWindow windowJeu(sf::VideoMode(1600, 900), "Spacecraft vs Asteroids"/*, sf::Style::Fullscreen*/);

    sf::Image icon;

    if(!icon.loadFromFile("Images/Backgrounds/Icon.png"))
    {

    }

    windowJeu.setIcon(250,250,icon.getPixelsPtr());
    //menu(windowJeu);
    menu(windowJeu);
}


void Management::menu(sf::RenderWindow & windowJeu)
{
	Menu menu;
	//menu.show()


	while (windowJeu.isOpen())
	{
		sf::Event event;
		while (windowJeu.pollEvent(event))
		{
			switch (event.type)
			{
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.moveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.moveDown();
                    break;

                case sf::Keyboard::Return:
                    switch(menu.getPressedItem())
                    {
                    case 0:
                        playerAccount(windowJeu);
                        windowJeu.close();

                        break;

                    case 1:
                        creditGame(windowJeu);

                        break;

                    case 2:
                        windowJeu.close();
;
                        default:
                        break;
                    }
                    windowJeu.clear();
                    default:
                    break;
                }
                break;
                case sf::Event::Closed:
                    windowJeu.close();

                default:
                break;

			}

		}

		windowJeu.clear();

		menu.draw(windowJeu);
		windowJeu.display();
	}
}

void Management::pauseMenu(sf::RenderWindow & windowJeu)
{
	PauseMenu menu;

	while (windowJeu.isOpen())
	{
		sf::Event event;
		while (windowJeu.pollEvent(event))
		{
			switch (event.type)
			{
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.moveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.moveDown();
                    break;

                case sf::Keyboard::Return:
                    switch(menu.getPressedItem())
                    {
                    case 0:
                        launch(windowJeu);

                        break;

                    case 1:
                        mapSpace(windowJeu);
                        break;

                    case 2:

                        showStats(windowJeu);
                       break;
                    case 3:

                        windowJeu.close();
                        break;
                        default:
                        break;
                    }
                    windowJeu.clear();
                    default:
                    break;
                }
                break;
                case sf::Event::Closed:
                    windowJeu.close();

                default:
                break;

			}

		}

		windowJeu.clear();

		menu.draw(windowJeu);

		windowJeu.display();
	}
}

void Management::playerAccount(sf::RenderWindow & windowJeu)
{
	//PersonnageHeros p1("Joueur1", HUMAIN);
    player.getStats(hero);
	while (windowJeu.isOpen())
	{
		sf::Event event;
		while (windowJeu.pollEvent(event))
		{
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                windowJeu.clear();
                menu(windowJeu);

            }
			switch (event.type)
			{
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    player.moveUp();
                    player.getStats(hero);
                    break;

                case sf::Keyboard::Down:
                    player.moveDown();
                    player.getStats(hero);
                    break;

                case sf::Keyboard::Return:
                    switch(player.getPressedElement())
                    {
                    case 0:
                        hero.setRace(HUMAN);


                        break;

                    case 1:
                        hero.setRace(VALDERA);

//

                        break;

                    case 2:
                        hero.setRace(VANDUUL);

//

                       break;

                    case 3:
                        hero.setRace(COVENANTE);

//

                       break;

                    case 4:
                        hero.setRace(AETWI);

                        break;
                        default:
                        break;


                    }


                    playerPseudo(windowJeu);

                    break;

                    windowJeu.clear();
                    default:
                    break;
                }
                break;
                case sf::Event::Closed:

                    windowJeu.close();


                default:
                break;

			}

		}

		windowJeu.clear();

		player.draw(windowJeu);

		windowJeu.display();
	}
}

void Management::playerPseudo(sf::RenderWindow & windowJeu)
{
    player.pseudoPlayer(windowJeu);
    hero.setName(player.getPseudo());

    spv.showStats(hero);
    launch(windowJeu);
}

Management::~Management()
{
    //dtor
}

void Management::launch(sf::RenderWindow & windowJeu)
{
    sf::View view(sf::FloatRect(2000, 2000, 3450, 1800));
    view.setCenter(spacecraft.getX(), spacecraft.getY());
    BiomePlanet biome;


    Planet planetInProgress;



    int display = 0;


    int x = spacecraft.getX();
    int y = spacecraft.getY();


    int a,b;

    while (windowJeu.isOpen())
        {
            sf::Event event;
            while (windowJeu.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                   // pause(windowJeu);
                    windowJeu.close();
                }

                //Faire pause dans le jeu
                switch (event.type)
                {
                    case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                    case sf::Keyboard::Escape:
                        windowJeu.clear();
                        view.reset(sf::FloatRect(2048, 1024, 1500, 900));
                        view.setCenter(750, 450);
                        windowJeu.setView(view);
                        pauseMenu(windowJeu);
                        break;
                        default:
                        break;
                    }
                    default:
                        break;
                }
                for (size_t i (0); i< universe.planets.size();i++){
                    if((spacecraft.getX() >= universe.planets[i]->getX()+200 && spacecraft.getX() <= universe.planets[i]->getX()+800)
                       && (spacecraft.getY() >= universe.planets[i]->getY()+200 && spacecraft.getY() <= universe.planets[i]->getY() + 800))
                    {
                        display = 1;
                        planetInProgress = *universe.planets[i];

                            switch (event.type)
                            {
                                case sf::Event::KeyReleased:
                                switch(event.key.code)
                                {
                                    case sf::Keyboard::Return:

                                        biome.setBackground("Images/Backgrounds/"+planetInProgress.getName()+"_Background.png");

                                        planetInProgress.giveBiome(biome);
                                        fightPlanet(windowJeu,planetInProgress);


                                    break;
                                    default:
                                        break;
                                }
                                default:
                                    break;
                            }


                    }
                    else
                    {
                        if(*universe.planets[i] == planetInProgress){
                            display = 0;
                        }
                    }

            }

                if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::M)
                {
                    windowJeu.clear();
                    mapSpace(windowJeu);
                }
            }


                if(event.type == sf::Event::EventType::KeyPressed)
                {
                    a = x;
                    b = y;


                    x = spacecraftView.moveOnX(event, x);
                    y = spacecraftView.moveOnY(event, y);

                    a = x-a;
                    b = y-b;
                    view.move(a,b);

                    spacecraft.setX(x);
                    spacecraft.setY(y);
                    spacecraftView.spacecraft_sprite.setPosition(x,y);
                }
            }


            sf::Font font;

            if (!font.loadFromFile("Polices/SpaceFont.ttf"))
            {
                cout << "Internal error" <<endl;
            }

            sf::Text text;
            text.setFont(font);
            text.setString("> Appuyez sur la touche enter pour atterir <");
            text.setCharacterSize(100);
            text.setPosition(sf::Vector2f(planetInProgress.getX()-600, planetInProgress.getY()-100));


            windowJeu.clear();
            windowJeu.setView(view);
            windowJeu.draw(universe.universe_sprite);

            for(size_t i(0);i<universe.planets.size();i++)
            {
                windowJeu.draw(*universe.planets[i]);
            }

            for(size_t i(0); i < universe.unreachablePlanets.size(); i++)
            {
                windowJeu.draw(*universe.unreachablePlanets[i]);
            }

            if(display == 1)
            {
                windowJeu.draw(text);
            }

            spacecraftView.setSpacecraft(spacecraft);
            spacecraftView.drawSpacecraft(windowJeu);
            windowJeu.display();

        }
}

void Management::mapSpace(sf::RenderWindow & windowJeu)
{
    sf::View view(sf::FloatRect(0, 0, 16000, 8642));
    //4000 2160.5
    view.setCenter(7130, 3150);



    windowJeu.setView(view);

    while (windowJeu.isOpen())
    {

        sf::Event event;

        while (windowJeu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                view.reset(sf::FloatRect(2048, 1024, 1500, 900));
                view.setCenter(750, 450);
                windowJeu.setView(view);
                menu(windowJeu);
            }

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::M)
                {
                    windowJeu.clear();

                    launch(windowJeu);
                }
            }
        }

        sf::Font font;

        if (!font.loadFromFile("Polices/SpaceFont.ttf"))
        {
            cout << "Internal error" <<endl;
        }

        sf::Text text;
        text.setFont(font);
        text.setString("> Appuyez sur la touche 'm' pour revenir sur le jeu <");
        text.setCharacterSize(500);
        text.setPosition(200, -600);

        windowJeu.clear();

        windowJeu.setView(view);
        windowJeu.draw(universe.universe_sprite);

        for(size_t i(0);i<universe.planets.size();i++)
        {
            windowJeu.draw(*universe.planets[i]);
        }

        for(size_t i(0); i < universe.unreachablePlanets.size(); i++)
        {
            windowJeu.draw(*universe.unreachablePlanets[i]);
        }

        windowJeu.draw(text);
        windowJeu.display();

    }
}

void Management::fightPlanet(sf::RenderWindow & windowJeu,Planet& pla)
{
    sf::View view(sf::FloatRect(2048, 1024, 2048, 1024));
    view.setCenter(1024, 512);
    int nb = 0;
    int step;
    cout << hero.str() << endl;

    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    //sf::Font font;

    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
    {
        cout << "Internal error" <<endl;
    }

    if (!fontFight.loadFromFile("Polices/SpaceCapitain.otf"))
    {
        cout << "Internal error" <<endl;
    }

    if (!versus_texture.loadFromFile("Images/Backgrounds/versus.png"))
    {
        std::cout << "Problème d'image du 'versus'" << std::endl;
    }

    sf::Vector2f dimension(pla.getXChar(),pla.getYChar());
    sf::Vector2f dimensionBoss(pla.getBoss()->getX()-250,pla.getBoss()->getY());
    cView.character_hero_sprite.setPosition(dimension.x, dimension.y);
    cView.attack_boss_sprite.setPosition(dimensionBoss.x,dimensionBoss.y);


    versus_sprite.setTexture(versus_texture);
    versus_sprite.setPosition(775, -25);

    sf::Text textHero;
    sf::Text textBoss;

    textHero.setFont(fontFight);
    textBoss.setFont(fontFight);

    textHero.setFillColor(sf::Color::Green);
    textBoss.setFillColor(sf::Color::Green);

    textHero.setCharacterSize(30);
    textBoss.setCharacterSize(30);

    cView.setCharacterBoss(*pla.getBoss());
    cView.setCharacterHero(hero);


    barHero.setMaxLife(hero.getPtsLife());
    barHero.setBarLifePosition(650,75);
    barHero.setBarShieldPosition(800,100);
    barHero.setMaxShield(hero.getShield());

    barBoss.setBarLifePosition(1400,75);
    barBoss.setMaxLife(pla.getBoss()->getPtsLife());
    barBoss.setBarShieldPosition(1250,100);
    barBoss.setMaxShield(pla.getBoss()->getShield());

    barHero.setRotation();

    barHero.updateLife(hero.getPtsLife());
    barHero.updateShield(hero.getShield());

    barBoss.updateLife(pla.getBoss()->getPtsLife());
    barBoss.updateShield(pla.getBoss()->getShield());

    int statut = 0;
    int nbRegen = 2;
    int result = 0;
    int attackEvent = 0;


    sf::Text textAttackEvent;

    textAttackEvent.setFont(font);
    //
    textAttackEvent.setFillColor(sf::Color::Black);
    textAttackEvent.setCharacterSize(45);

    textAttackEvent.setPosition(750,550);

    textLifeHero.setFont(font);
    textLifeBoss.setFont(font);
    textShieldHero.setFont(font);
    textShieldBoss.setFont(font);

    textLifeHero.setFillColor(sf::Color(105, 0, 0));
    textLifeBoss.setFillColor(sf::Color(105, 0, 0));
    textShieldHero.setFillColor(sf::Color(0, 51, 102));
    textShieldBoss.setFillColor(sf::Color(0, 51, 102));

    textLifeHero.setCharacterSize(30);
    textLifeBoss.setCharacterSize(30);
    textShieldHero.setCharacterSize(17);
    textShieldBoss.setCharacterSize(17);


    textLifeHero.setPosition(837, 55);
    textLifeBoss.setPosition(1153, 55);
    textShieldHero.setPosition(870, 88);
    textShieldBoss.setPosition(1153, 88);

    textLifeHero.setStyle(sf::Text::Bold);
    textLifeBoss.setStyle(sf::Text::Bold);
    textShieldHero.setStyle(sf::Text::Bold);
    textShieldBoss.setStyle(sf::Text::Bold);

    textLifeHero.setString(to_string(hero.getPtsLife()));
    textLifeBoss.setString(to_string(pla.getBoss()->getPtsLife()));
    textShieldHero.setString(to_string(hero.getShield()));
    textShieldBoss.setString(to_string(pla.getBoss()->getShield()));

    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

    windowJeu.setView(view);

    int lifeHero = hero.getPtsLife();
    int shieldHero = hero.getShield();

    int lifeBoss = pla.getBoss()->getPtsLife();
    int shieldBoss = pla.getBoss()->getShield();

    while (windowJeu.isOpen())
    {


        sf::Event event;
        while (windowJeu.pollEvent(event))
        {
            if(statut == 0)
            {
                statut = 1;

            if(hero.getPtsLife() > 0 && pla.getBoss()->getPtsLife() > 0){

                switch (event.type){
                case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::A:
                attackEvent = fight.attack(hero,*pla.getBoss());

                textAttackEvent.setString("Attaque de " + hero.getName());


                while(dimension.x < pla.getBoss()->getX() -300)
                {
                    nb++;
                    windowJeu.clear();
                    cView.forwardHero();
                    dimension.x += 22;
                    cView.character_hero_sprite.setPosition(dimension.x, dimension.y);
                    pla.getBiome()->drawBiome(windowJeu);
                    barHero.drawLife(windowJeu);
                    barHero.drawShield(windowJeu);
                    barBoss.drawLife(windowJeu);
                    barBoss.drawShield(windowJeu);
                    cView.drawHero(windowJeu);
                    cView.drawBoss(windowJeu);
                    windowJeu.draw(versus_sprite);
                    windowJeu.draw(textHero);
                    windowJeu.draw(textBoss);
                    windowJeu.draw(textAttackEvent);


                    windowJeu.draw(textLifeHero);
                    windowJeu.draw(textLifeBoss);
                    windowJeu.draw(textShieldHero);
                    windowJeu.draw(textShieldBoss);
                    windowJeu.display();
                    sf::sleep(sf::milliseconds(5));
                }

                if(attackEvent == 2)
                {
                    textAttackEvent.setString(pla.getBoss()->getName()+fight.eventAttack(attackEvent));
                }
                else
                {
                    textAttackEvent.setString(fight.eventAttack(attackEvent)+hero.getName());
                }

                for(size_t i(0);i<5;i++)
                {
                    windowJeu.clear();
                    cView.fightHero();
                    pla.getBiome()->drawBiome(windowJeu);
                    barHero.drawLife(windowJeu);
                    barHero.drawShield(windowJeu);
                    barBoss.drawLife(windowJeu);
                    barBoss.drawShield(windowJeu);
                    cView.drawHero(windowJeu);
                    cView.drawBoss(windowJeu);
                    windowJeu.draw(versus_sprite);
                    windowJeu.draw(textHero);
                    windowJeu.draw(textBoss);
                    windowJeu.draw(textAttackEvent);


                    windowJeu.draw(textLifeHero);
                    windowJeu.draw(textLifeBoss);
                    windowJeu.draw(textShieldHero);
                    windowJeu.draw(textShieldBoss);
                    windowJeu.display();
                    sf::sleep(sf::milliseconds(600));
                }

                barBoss.updateLife(pla.getBoss()->getPtsLife());
                barBoss.updateShield(pla.getBoss()->getShield());

                textLifeHero.setString(to_string(hero.getPtsLife()));
                textLifeBoss.setString(to_string(pla.getBoss()->getPtsLife()));

                textShieldHero.setString(to_string(hero.getShield()));
                textShieldBoss.setString(to_string(pla.getBoss()->getShield()));


                for(int i(0);i<nb;i++)
                {
                    windowJeu.clear();
                    cView.backwardHero();
                    dimension.x -= 22;
                    cView.character_hero_sprite.setPosition(dimension.x, dimension.y);
                    pla.getBiome()->drawBiome(windowJeu);
                    barHero.drawLife(windowJeu);
                    barHero.drawShield(windowJeu);
                    barBoss.drawLife(windowJeu);
                    barBoss.drawShield(windowJeu);
                    cView.drawHero(windowJeu);
                    cView.drawBoss(windowJeu);
                    windowJeu.draw(versus_sprite);
                    windowJeu.draw(textHero);
                    windowJeu.draw(textBoss);


                    windowJeu.draw(textLifeHero);
                    windowJeu.draw(textLifeBoss);
                        windowJeu.draw(textShieldHero);
                        windowJeu.draw(textShieldBoss);
                    windowJeu.display();
                    sf::sleep(sf::milliseconds(5));
                }





                cView.rectHero.left = 0;



                /*-------------BOSSSSSS------------*/

                if(pla.getBoss()->getPtsLife() != 0){


                attackEvent = fight.attack(*pla.getBoss(), hero);


                textAttackEvent.setString("Attaque de " + pla.getBoss()->getName());

                if(pla.getBoss()->getPtsLife() > 0){
                    for(size_t i(0);i<5;i++)
                    {
                        windowJeu.clear();
                        cView.fightBoss();
                        pla.getBiome()->drawBiome(windowJeu);
                        barHero.drawLife(windowJeu);
                        barHero.drawShield(windowJeu);
                        barBoss.drawLife(windowJeu);
                        barBoss.drawShield(windowJeu);
                        cView.drawHero(windowJeu);
                        cView.drawBoss(windowJeu);
                        windowJeu.draw(versus_sprite);
                        windowJeu.draw(textHero);
                        windowJeu.draw(textBoss);
                        windowJeu.draw(textAttackEvent);


                        windowJeu.draw(textLifeHero);
                        windowJeu.draw(textLifeBoss);
                        windowJeu.draw(textShieldHero);
                        windowJeu.draw(textShieldBoss);
                        windowJeu.display();
                        sf::sleep(sf::milliseconds(200));
                    }

                    if(attackEvent == 2)
                    {
                        textAttackEvent.setString(hero.getName()+fight.eventAttack(attackEvent));
                    }
                    else
                    {
                        textAttackEvent.setString(fight.eventAttack(attackEvent)+pla.getBoss()->getName());
                    }

                    cView.rectBoss.left = 0;

                    for(int i(0);i<nb;i++)
                    {
                        sf::sleep(sf::milliseconds(5));
                        windowJeu.clear();
                        cView.throwingBoss();
                        dimensionBoss.x -= 22;
                        cView.attack_boss_sprite.setPosition(dimensionBoss.x, dimensionBoss.y);
                        pla.getBiome()->drawBiome(windowJeu);
                        barHero.drawLife(windowJeu);
                        barHero.drawShield(windowJeu);
                        barBoss.drawLife(windowJeu);
                        barBoss.drawShield(windowJeu);
                        cView.drawHero(windowJeu);
                        cView.drawBoss(windowJeu);
                        cView.drawBoss2(windowJeu);
                        windowJeu.draw(versus_sprite);
                        windowJeu.draw(textHero);
                        windowJeu.draw(textBoss);
                        windowJeu.draw(textAttackEvent);


                        windowJeu.draw(textLifeHero);
                        windowJeu.draw(textLifeBoss);
                        windowJeu.draw(textShieldHero);
                        windowJeu.draw(textShieldBoss);
                        windowJeu.display();
                    }
                }

                textLifeHero.setString(to_string(hero.getPtsLife()));
                textLifeBoss.setString(to_string(pla.getBoss()->getPtsLife()));

                textShieldHero.setString(to_string(hero.getShield()));
                textShieldBoss.setString(to_string(pla.getBoss()->getShield()));

                dimensionBoss.x = pla.getBoss()->getX()-250;

                /*-----------------------------------*/


                    barHero.updateLife(hero.getPtsLife());
                    barHero.updateShield(hero.getShield());

                    step = nb;
                    nb = 0;
                }

                break;

                case sf::Keyboard::R:

                    textAttackEvent.setString(hero.getName() + " regagne sa vie de "+ to_string(hero.getRegeneration()) + " points");
                    if(hero.getPtsLife()+hero.getRegeneration() <= lifeHero && nbRegen>0)
                    {

                        nbRegen--;
                        fight.regenHero(hero, *pla.getBoss());

                        barHero.updateLife(hero.getPtsLife());
                        barHero.updateShield(hero.getShield());
                        textLifeHero.setString(to_string(hero.getPtsLife()));


                    /*---
                    Animation REGEN
                    */
                    for(size_t i(0);i<5;i++)
                    {
                        cView.regen_sprite.setPosition(pla.getXChar()-20, pla.getYChar()-30);
                        windowJeu.clear();
                        cView.regenCircles();
                        pla.getBiome()->drawBiome(windowJeu);
                        barHero.drawLife(windowJeu);
                        barHero.drawShield(windowJeu);
                        barBoss.drawLife(windowJeu);
                        barBoss.drawShield(windowJeu);
                        cView.drawHero(windowJeu);
                        cView.drawBoss(windowJeu);
                        cView.drawRegenCircles(windowJeu);
                        windowJeu.draw(versus_sprite);
                        windowJeu.draw(textHero);
                        windowJeu.draw(textBoss);
                        windowJeu.draw(textAttackEvent);

                        windowJeu.draw(textLifeHero);
                        windowJeu.draw(textShieldHero);
                        windowJeu.draw(textShieldBoss);
                        windowJeu.draw(textLifeBoss);
                        windowJeu.display();
                        sf::sleep(sf::milliseconds(600));
                    }

                    textLifeHero.setString(to_string(hero.getPtsLife()));
                    textLifeBoss.setString(to_string(pla.getBoss()->getPtsLife()));

                    textShieldHero.setString(to_string(hero.getShield()));
                    textShieldBoss.setString(to_string(pla.getBoss()->getShield()));

                    if(pla.getBoss()->getPtsLife() > 0)
                    {
                        attackEvent = fight.attack(*pla.getBoss(), hero);


                textAttackEvent.setString("Attaque de " + pla.getBoss()->getName());

                if(pla.getBoss()->getPtsLife() > 0){
                    for(size_t i(0);i<5;i++)
                    {
                        windowJeu.clear();
                        cView.fightBoss();
                        pla.getBiome()->drawBiome(windowJeu);
                        barHero.drawLife(windowJeu);
                        barHero.drawShield(windowJeu);
                        barBoss.drawLife(windowJeu);
                        barBoss.drawShield(windowJeu);
                        cView.drawHero(windowJeu);
                        cView.drawBoss(windowJeu);
                        windowJeu.draw(versus_sprite);
                        windowJeu.draw(textHero);
                        windowJeu.draw(textBoss);
                        windowJeu.draw(textAttackEvent);


                        windowJeu.draw(textLifeHero);
                        windowJeu.draw(textLifeBoss);
                        windowJeu.draw(textShieldHero);
                        windowJeu.draw(textShieldBoss);
                        windowJeu.display();
                        sf::sleep(sf::milliseconds(200));
                    }

                    if(attackEvent == 2)
                    {
                        textAttackEvent.setString(hero.getName()+fight.eventAttack(attackEvent));
                    }
                    else
                    {
                        textAttackEvent.setString(fight.eventAttack(attackEvent)+pla.getBoss()->getName());
                    }

                    cView.rectBoss.left = 0;

                    for(int i(0);i<step;i++)
                    {
                        sf::sleep(sf::milliseconds(5));
                        windowJeu.clear();
                        cView.throwingBoss();
                        dimensionBoss.x -= 22;
                        cView.attack_boss_sprite.setPosition(dimensionBoss.x, dimensionBoss.y);
                        pla.getBiome()->drawBiome(windowJeu);
                        barHero.drawLife(windowJeu);
                        barHero.drawShield(windowJeu);
                        barBoss.drawLife(windowJeu);
                        barBoss.drawShield(windowJeu);
                        cView.drawHero(windowJeu);
                        cView.drawBoss(windowJeu);
                        cView.drawBoss2(windowJeu);
                        windowJeu.draw(versus_sprite);
                        windowJeu.draw(textHero);
                        windowJeu.draw(textBoss);
                        windowJeu.draw(textAttackEvent);


                        windowJeu.draw(textLifeHero);
                        windowJeu.draw(textLifeBoss);
                        windowJeu.draw(textShieldHero);
                        windowJeu.draw(textShieldBoss);
                        windowJeu.display();
                    }
                }

                textLifeHero.setString(to_string(hero.getPtsLife()));
                textLifeBoss.setString(to_string(pla.getBoss()->getPtsLife()));

                textShieldHero.setString(to_string(hero.getShield()));
                textShieldBoss.setString(to_string(pla.getBoss()->getShield()));

                dimensionBoss.x = pla.getBoss()->getX()-250;
                }

                dimensionBoss.x = pla.getBoss()->getX()-250;

                /*-----------------------------------*/


                    barHero.updateLife(hero.getPtsLife());
                    barHero.updateShield(hero.getShield());
                }

                    break;

                default:
                break;
                }
                break;
                default:
                    break;

            }
            }
        }
            else
            {       //
                if(pla.getBoss()->getPtsLife() == 0){
                    result = 1;
                    hero.setPtsLife(lifeHero);
                    hero.setShield(shieldHero);
                    pla.getBoss()->setPtsLife(lifeBoss);
                    pla.getBoss()->setShield(shieldBoss);
                    pla.getBoss()->resurrection();
                    pla.getBoss()->setCounterSpe(0);
                    fight.setNbRegen(2);
                    hero.setCounterSpe(0);
                    screenResult(result, windowJeu, *pla.getBiome());

                }
                if(hero.getPtsLife() == 0)
                {
                    result = 2;

                    hero.setPtsLife(lifeHero);
                    hero.setShield(shieldHero);
                    pla.getBoss()->setPtsLife(lifeBoss);
                    pla.getBoss()->setShield(shieldBoss);
                    pla.getBoss()->setCounterSpe(0);
                    hero.setCounterSpe(0);
                    fight.setNbRegen(2);
                    screenResult(result, windowJeu, *pla.getBiome());
                }


            }
            cout << to_string(result) << endl;




            if (event.type == sf::Event::Closed)
            {
                windowJeu.clear();
                launch(windowJeu);
            }



        }



        windowJeu.clear();

        pla.getBiome()->drawBiome(windowJeu);
        textHero.setPosition(400, 20);
        textBoss.setPosition(1150, 20);

        textHero.setString(cView.getCharacterHero().getName());
        textBoss.setString(pla.getBoss()->getName());
        barHero.drawLife(windowJeu);
        barHero.drawShield(windowJeu);
        barBoss.drawLife(windowJeu);
        barBoss.drawShield(windowJeu);
        cView.drawHero(windowJeu);
        cView.drawBoss(windowJeu);
        windowJeu.draw(versus_sprite);
        windowJeu.draw(textHero);
        windowJeu.draw(textBoss);
        windowJeu.draw(textLifeHero);
        windowJeu.draw(textLifeBoss);
        windowJeu.draw(textShieldHero);
        windowJeu.draw(textShieldBoss);
        windowJeu.display();

        statut = 0;
    }

}

void Management::screenResult(int result, sf::RenderWindow& windowJeu, BiomePlanet biom)
{
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
    {
        cout << "Internal error" <<endl;
    }
    windowJeu.clear();
    sf::Text textEvent;
    sf::Text textInstruction;
    textEvent.setFont(font);
    textInstruction.setFont(font);
    textEvent.setCharacterSize(100);
    textInstruction.setCharacterSize(80);
    textEvent.setStyle(sf::Text::Bold);
    textInstruction.setStyle(sf::Text::Bold);




    while (windowJeu.isOpen())
	{
		sf::Event event;
		while (windowJeu.pollEvent(event))
		{
            if (event.type == sf::Event::TextEntered)
            {
                if(result == 1)
                {
                    sf::View view(sf::FloatRect(2000, 2000, 3450, 1800));
                    view.reset(sf::FloatRect(2048, 1024, 1500, 900));
                    view.setCenter(750, 450);
                    windowJeu.setView(view);
                    increaseStats(windowJeu);
                }
                    else
                        launch(windowJeu);
            }
        }

        //afficher Victoire ou défaite condition
        windowJeu.clear();
        if(result == 1)
        {
            textEvent.setFillColor(sf::Color::Green);
            textEvent.setString("Victory");

            textInstruction.setFillColor(sf::Color(241, 159, 10));
            textInstruction.setString("> Press any key to get back to stat's menu <");

        }
        if(result == 2)
        {
            textEvent.setFillColor(sf::Color::Red);
            textEvent.setString("Wasted");

            textInstruction.setFillColor(sf::Color(241, 159, 10));
            textInstruction.setString("> Press any key to get back to the universe <");
        }


        textEvent.setPosition(825, 450);
        textInstruction.setPosition(50, 150);

        biom.drawBiome(windowJeu);
        windowJeu.draw(textEvent);
        windowJeu.draw(textInstruction);

        windowJeu.display();
	}

}

void Management::increaseStats(sf::RenderWindow & windowJeu)
{
	IncreaseStatsMenu stats;

	while (windowJeu.isOpen())
	{
		sf::Event event;
		while (windowJeu.pollEvent(event))
		{
			switch (event.type)
			{
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    stats.moveUp();
                    break;

                case sf::Keyboard::Down:
                    stats.moveDown();
                    break;

                case sf::Keyboard::Return:
                    switch(stats.getPressedItem())
                    {
                    case 0:
                        hero.setIncrease(new IncreaseLife);
                        break;

                    case 1:
                        hero.setIncrease(new IncreaseAttack);
                        break;

                    case 2:
                        hero.setIncrease(new IncreaseShield);

                        break;

                    case 3:
                        hero.setIncrease(new IncreaseRegeneration);

                        break;
                    default:
                        break;
                    }


                    hero.executeIncrease();
                    spv.showStats(hero);

                    cout << hero.str() << endl;
                    windowJeu.clear();
                    launch(windowJeu);
                    break;

                    default:
                    break;
                }
                break;
                case sf::Event::Closed:
                    windowJeu.close();

                default:
                break;

			}

		}

		windowJeu.clear();

		stats.draw(windowJeu);

		windowJeu.display();
	}
}


void Management::creditGame(sf::RenderWindow &window)
{

    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
    {
        cout << "Internal error" <<endl;
    }


	credit[0].setFont(font);
	credit[0].setFillColor(sf::Color::White);
	credit[0].setString("> Bruillet Baptiste ");
	credit[0].setPosition(sf::Vector2f(500,200));

	credit[1].setFont(font);
	credit[1].setFillColor(sf::Color::White);
	credit[1].setString("> Cornut Sylvain ");
	credit[1].setPosition(sf::Vector2f(500,350));

	credit[2].setFont(font);
	credit[2].setFillColor(sf::Color::White);
	credit[2].setString("> Danese Loris " );
	credit[2].setPosition(sf::Vector2f(500,500));

	credit[3].setFont(font);
	credit[3].setFillColor(sf::Color::White);
	credit[3].setString("> Smet Antoine " );
	credit[3].setPosition(sf::Vector2f(500,650));

	for (int i = 0; i < MAX_NUMBER_OF_STUDENTS; i++)
	{
		credit[i].setCharacterSize(66);
	}


   while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
		    // case revenir menu
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                window.clear();
                menu(window);
            }
		}
		window.clear();
		 for (int i = 0; i < MAX_NUMBER_OF_STUDENTS; i++)
            {
                window.draw(credit[i]);
            }
		window.display();
	}
}

void Management::showStats(sf::RenderWindow &windowJeu)
{

    while (windowJeu.isOpen())
	{
		sf::Event event;
		while (windowJeu.pollEvent(event))
		{
		    // case revenir menu
		    if (event.type == sf::Event::Closed)
            {
                launch(windowJeu);
            }
		}
        windowJeu.clear();
        spv.draw(windowJeu);
        windowJeu.display();
	}
}
