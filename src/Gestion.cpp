#include "Gestion.h"

#include <SFML/Graphics.hpp>

#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>
#include <cmath>

#include "Personnage.h"
#include "Univers.h"
#include "Planete.h"
#include "Vaisseau.h"
#include "BiomePlanete.h"

#include "Menu.h"

using namespace std;


Gestion::Gestion()
{
    this->univers = univers;
    this->vaisseau = vaisseau;

    Planete planeteBleu("Bleue", "Images/Planetes/Bleu.png", 2000, 750);
    Planete planeteOrange("Orange", "Images/Planetes/Orange.png", 9000, 1250);
    Planete planeteMauve("Mauve_Detruite", "Images/Planetes/Mauve_Detruite.png", 7000, 5500);
    Planete planeteMort("Mort", "Images/Planetes/Etoile_De_La_Mort.png", 8000, 6120);
    //Ok
    Planete planeteRouge("Anneau_Rouge", "Images/Planetes/Anneau_Rouge.png", 11000, 3000);
    //ok
    Planete planeteVerte("Verte", "Images/Planetes/Verte.png", 5000, 3200);
    //ok
    Planete planetePlateforme("Plateforme", "Images/Planetes/Plateforme.png", 6900, 3300);
    Planete planeteAnneauBleu("Anneau_Bleu", "Images/Planetes/Anneau_Bleu.png", 1500, 5100);
    //ok
    Planete planeteSoleil("Soleil", "Images/Planetes/Soleil.png", 12000, 0);

    univers.add(planeteBleu);
    univers.add(planeteOrange);
    univers.add(planeteRouge);
    univers.add(planeteMauve);
    univers.addInacc(planeteMort);
    univers.add(planeteVerte);
    univers.addInacc(planetePlateforme);
    univers.add(planeteAnneauBleu);
    univers.addInacc(planeteSoleil);
}

void Gestion::fenetrePrincipale()
{
    /*MUSIQUE*/
    sf::SoundBuffer Buffer;
    if (!Buffer.loadFromFile("Musiques/MusiqueMenu.wav")){
        cout << "Pas de musique sélectionnée" <<endl;
    }
    sf::Sound sound;
    sound.setBuffer(Buffer);

    sound.setLoop(true);
    sound.play();
    sf::RenderWindow windowJeu(sf::VideoMode(1500, 900), "Spacecraft vs Asteroids"/*, sf::Style::Fullscreen*/);
    menu(windowJeu);
}


void Gestion::menu(sf::RenderWindow & windowJeu)
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
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch(menu.GetPressedItem())
                    {
                    case 0:
                        launch(windowJeu);
                        windowJeu.close();

                        break;

                    case 1:
                        map_space(windowJeu);
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

Gestion::~Gestion()
{
    //dtor
}

void Gestion::launch(sf::RenderWindow & windowJeu)
{
    sf::View view(sf::FloatRect(2000, 2000, 3450, 1800));
    view.setCenter(vaisseau.getX(), vaisseau.getY());

    BiomePlanete biomtest;


    Planete planeteEnCours;



    int affichage = 0;


    int x = vaisseau.getX();
    int y = vaisseau.getY();


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
                        menu(windowJeu);
                        break;
                        default:
                        break;
                    }
                    default:
                        break;
                }

                for (size_t i (0); i< univers.planetes.size();i++){
                    if((vaisseau.getX() >= univers.planetes[i].getX()+200 && vaisseau.getX() <= univers.planetes[i].getX()+800)
                       && (vaisseau.getY() >= univers.planetes[i].getY()+200 && vaisseau.getY() <= univers.planetes[i].getY() + 800))
                    {
                        affichage = 1;
                        planeteEnCours = univers.planetes[i];


                            switch (event.type)
                            {
                                case sf::Event::KeyReleased:
                                switch(event.key.code)
                                {
                                    case sf::Keyboard::Return:
                                        cout << "Vous avez bien attéri" << endl;

                                        biomtest.setBackground("Images/Backgrounds/"+planeteEnCours.getNom()+"_Background.png");

                                        planeteEnCours.DonnerBiome(biomtest);

                                        combatPlanete(windowJeu,*planeteEnCours.getBiome());


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
                        if(univers.planetes[i] == planeteEnCours){
                        affichage = 0;
                        }
                    }

            }

                if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::M)
                {
                    windowJeu.clear();
                    map_space(windowJeu);
                }
            }


                if(event.type == sf::Event::EventType::KeyPressed)
                {
                    a = x;
                    b = y;


                    x = vaisseau.seDeplacerX(event, x);
                    y = vaisseau.seDeplacerY(event, y);

                    a = x-a;
                    b = y-b;
                    view.move(a,b);

                    vaisseau.setX(x);
                    vaisseau.setY(y);
                    vaisseau.vaisseau_sprite.setPosition(x,y);
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
            text.setPosition(sf::Vector2f(planeteEnCours.getX()-600, planeteEnCours.getY()-100));


            windowJeu.clear();
            windowJeu.setView(view);
            windowJeu.draw(univers.univers_sprite);

            for(size_t i(0);i<univers.planetes.size();i++)
            {
                windowJeu.draw(univers.planetes[i]);
            }

            for(size_t i(0); i < univers.planetesInaccessibles.size(); i++)
            {
                windowJeu.draw(univers.planetesInaccessibles[i]);
            }

            if(affichage == 1)
            {
                windowJeu.draw(text);
            }


            windowJeu.draw(vaisseau.vaisseau_sprite);
            windowJeu.display();

        }
}


void Gestion::map_space(sf::RenderWindow & windowJeu)
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

        windowJeu.clear();
        windowJeu.setView(view);
        windowJeu.draw(univers.univers_sprite);

        for(size_t i(0);i<univers.planetes.size();i++)
        {
            windowJeu.draw(univers.planetes[i]);
        }

        for(size_t i(0); i < univers.planetesInaccessibles.size(); i++)
        {
            windowJeu.draw(univers.planetesInaccessibles[i]);
        }

        windowJeu.display();

    }
}

void Gestion::combatPlanete(sf::RenderWindow & windowJeu,BiomePlanete& bio)
{
    sf::View view(sf::FloatRect(2048, 1024, 2048, 1024));
    view.setCenter(1024, 512);

    windowJeu.setView(view);

    while (windowJeu.isOpen())
    {
        sf::Event event;
        while (windowJeu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                windowJeu.clear();
                launch(windowJeu);
            }

        }
        windowJeu.clear();
//        cout << "test " << endl;
        windowJeu.draw(bio.biome_sprite);
        windowJeu.display();

    }



}

