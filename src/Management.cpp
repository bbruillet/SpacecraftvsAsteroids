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
    planets[0] = new Planet("Bleue", "Images/Planetes/Bleu.png", 2000, 750, 319, 525); //319
    planets[1] = new Planet("Orange", "Images/Planetes/Orange.png", 9000, 1250, 291, 520); //291
    planets[2] = new Planet("Mauve_Detruite", "Images/Planetes/Mauve_Detruite.png", 7000, 5500, 417, 600); //417
    planets[3] = new Planet("Anneau_Rouge", "Images/Planetes/Anneau_Rouge.png", 11000, 3000, 1083, 400); //1083
    planets[4] = new Planet("Verte", "Images/Planetes/Verte.png", 5000, 3200, 703, 600); //703
    planets[5] = new Planet("Anneau_Bleu", "Images/Planetes/Anneau_Bleu.png", 1500, 5100, 318, 575); //318

    unreachPlanets[0] = new Planet("Mort", "Images/Planetes/Etoile_De_La_Mort.png", 8000, 6120, 0, 0);
    unreachPlanets[1] = new Planet("Plateforme", "Images/Planetes/Plateforme.png", 6900, 3300, 0, 0);
    unreachPlanets[2] = new Planet("Soleil", "Images/Planetes/Soleil.png", 12000, 0, 0, 0);

    boss[0] = new CharacterBoss("BossBleu",BLUE);
    boss[1] = new CharacterBoss("BossOrange",ORANGE);
    boss[2] = new CharacterBoss("BossMauve",PURPLE_DESTROYED);
    boss[3] = new CharacterBoss("BossRouge",RING_RED);
    boss[4] = new CharacterBoss("BossVert",GREEN);
    boss[5] = new CharacterBoss("BossAnneauBleu",RING_BLUE);






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
                        mapSpace(windowJeu);
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
                        windowJeu.close();

                        break;

                    case 1:
                        mapSpace(windowJeu);
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

void Management::playerAccount(sf::RenderWindow & windowJeu)
{
	//PersonnageHeros p1("Joueur1", HUMAIN);
    player.getStats(hero);
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
                        playerPseudo(windowJeu);

                        break;

                    case 1:
                        hero.setRace(VALDERA);
                        playerPseudo(windowJeu);
//

                        break;

                    case 2:
                        hero.setRace(VANDUUL);
                        playerPseudo(windowJeu);
//

                       break;

                    case 3:
                        hero.setRace(COVENANTE);
                        playerPseudo(windowJeu);
//

                       break;

                    case 4:
                        hero.setRace(AETWI);
                        playerPseudo(windowJeu);

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

		player.draw(windowJeu);

		windowJeu.display();
	}
}

void Management::playerPseudo(sf::RenderWindow & windowJeu)
{
    player.pseudoPlayer(windowJeu);
    hero.setName(player.getPseudo());


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
                                        cout << "Vous avez bien attéri" << endl;

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

    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    sf::Font font;

    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
    {
        cout << "Internal error" <<endl;
    }

    if (!versus_texture.loadFromFile("Images/Backgrounds/versus.png"))
    {
        std::cout << "Problème d'image du 'versus'" << std::endl;
    }

    sf::Vector2f dimension(pla.getXChar(),pla.getYChar());
    cView.character_hero_sprite.setPosition(dimension.x, dimension.y);


    versus_sprite.setTexture(versus_texture);
    versus_sprite.setPosition(775, -25);

    sf::Text textHero;
    sf::Text textBoss;

    textHero.setFont(font);
    textBoss.setFont(font);

    textHero.setFillColor(sf::Color::Yellow);
    textBoss.setFillColor(sf::Color::Yellow);

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


    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

    windowJeu.setView(view);
    while (windowJeu.isOpen())
    {


        sf::Event event;
        while (windowJeu.pollEvent(event))
        {

            if(hero.getPtsLife() > 0 && pla.getBoss()->getPtsLife() > 0 ){



                fight.fightBoss(hero,*pla.getBoss(), windowJeu);


                for(size_t i(0);i<50;i++)
                {
                    windowJeu.clear();
                    cView.forwardHero();
                    dimension.x += 11;
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
                    windowJeu.display();
                    sf::sleep(sf::milliseconds(5));
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
                    windowJeu.display();
                    sf::sleep(sf::milliseconds(600));
                }



                for(size_t i(0);i<50;i++)
                {
                    windowJeu.clear();
                    cView.backwardHero();
                    dimension.x -= 11;
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
                    windowJeu.display();
                    sf::sleep(sf::milliseconds(5));
                }





                /*-------------------------*/
//                for(size_t i(0);i<50;i++)
//                {
//                    windowJeu.clear();
//                    cView.fightBoss();
//                    dimension.x += 11;
//                    cView.character_boss_sprite.setPosition(dimension.x, dimension.y);
//                    pla.getBiome()->drawBiome(windowJeu);
//                    barHero.drawLife(windowJeu);
//                    barHero.drawShield(windowJeu);
//                    barBoss.drawLife(windowJeu);
//                    barBoss.drawShield(windowJeu);
//                    cView.drawHero(windowJeu);
//                    cView.drawBoss(windowJeu);
//                    windowJeu.draw(versus_sprite);
//                    windowJeu.draw(textHero);
//                    windowJeu.draw(textBoss);
//                    windowJeu.display();
//                    sf::sleep(sf::milliseconds(5));
//                }

                /*for(size_t i(0);i<5;i++)
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
                    windowJeu.display();
                    sf::sleep(sf::milliseconds(600));
                }



                for(size_t i(0);i<50;i++)
                {
                    windowJeu.clear();
                    cView.throwingBoss();
                    dimension.x -= 11;
                    cView.character_boss_sprite.setPosition(dimension.x, dimension.y);
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
                    windowJeu.display();
                    sf::sleep(sf::milliseconds(5));
                }*/

                /*-----------------------------------*/


                    barHero.updateLife(hero.getPtsLife());
                    barHero.updateShield(hero.getShield());

                    barBoss.updateLife(pla.getBoss()->getPtsLife());
                    barBoss.updateShield(pla.getBoss()->getShield());
                    cView.rectHero.left = 0;


            }
            else
            {       //
                    if(pla.getBoss()->getPtsLife() == 0){
                        cout << "Victoire" << endl;
                        cView.getCharacterHero().categoryHero();
//                    screenResult(windowJeu);
                        increaseStats(windowJeu);
                    }
                    //launch(windowJeu);

            }

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

        //windowJeu.draw(pla.getBoss()->personnage_sprite);
        windowJeu.display();

    }


}

void Management::screenResult(sf::RenderWindow& windowJeu)
{
    while (windowJeu.isOpen())
	{
		sf::Event event;
		while (windowJeu.pollEvent(event))
		{
		    cout << "Tu as gagné" << endl;
        }
        windowJeu.clear();
        //afficher Victoire ou défaite condition

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
                    launch(windowJeu);
                    switch(stats.getPressedItem())
                    {
                    case 0:
                        hero.setPtsLife(hero.getPtsLife()+10);
                        break;

                    case 1:
                        hero.setPtsAttack(hero.getPtsAttack()+5);
                        break;

                    case 2:
                        hero.setPtsSpecialAttack(hero.getPtsSpecialAttack()+5);
                        break;

                    case 3:
                        hero.setShield(hero.getShield()+10);

                        break;

                    case 4:
                        hero.setCriticalHit(hero.getCriticalHit()+5.00);

                        break;

                    case 5:
                        hero.setDodge(hero.getDodge()+7.00);

                        break;

                    case 6:
                        hero.setRegeneration(hero.getRegeneration()+10);

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

		stats.draw(windowJeu);

		windowJeu.display();
	}
}
