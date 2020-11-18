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

#include "Menu.h"

using namespace std;


Gestion::Gestion()
{

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

//    sf::RenderWindow windowJeu(sf::VideoMode(900, 900), "Spacecraft vs Asteroids");
    sf::RenderWindow windowJeu(sf::VideoMode(1500, 900), "Spacecraft vs Asteroids", sf::Style::Fullscreen);

//    while (windowJeu.isOpen())
//	{
        menu(windowJeu);
//	}
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
//                    default:
                    break;

                case sf::Keyboard::Return:
                    switch(menu.GetPressedItem())
                    {
                    case 0:
                        launch(windowJeu);
                        windowJeu.close();

                        break;

                    case 1:
                        std::cout << "Map button has been pressed" << std::endl;
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
//
		menu.draw(windowJeu);
//
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
    view.setCenter(7150, 3500);

//    if(choixMenu == 1) {
//        view.setSize(2500,2500);
//    }
//    else if(choixMenu == 2) {
//        view.setSize(13500, 13500);
//    }
    Vaisseau vaisseau;
    Univers univers; //Taille 13883x7500

    Planete planeteBleu("Blue", "Images/Planetes/Bleu.png", 2000, 750);

    //Decor = BlueBackground - OrangeBackground, ...

//    "images/"+univers.plaetes.getNom()+"Background.png"


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
    Planete planeteSoleil("Soleil", "Images/Planetes/Soleil.png", 11250, 100);
    univers.add(planeteBleu);
    univers.add(planeteOrange);
    univers.add(planeteRouge);
    univers.add(planeteMauve);
    univers.addInacc(planeteMort);
    univers.add(planeteVerte);
    univers.addInacc(planetePlateforme);
    univers.add(planeteAnneauBleu);
    univers.addInacc(planeteSoleil);

    Planete planeteEnCours;

    //Planete planete;

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
                    cout << "closed"<<endl;
                }

                //Faire pause dans le jeu
                switch (event.type)
                {
                    case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                    case sf::Keyboard::Escape:
                        windowJeu.close();
                        pause(windowJeu);
                        break;
                        default:
                        break;
                    }
                    default:
                        break;
                }

                //collisions
               /* if((std::abs((pers.perso_sprite.getPosition().x+62.5) - (planeteSoleil.planete_sprite.getPosition().x+62.5) >= 200)) &&
                   (std::abs((pers.perso_sprite.getPosition().y+62.5) - (planeteSoleil.planete_sprite.getPosition().y+62.5) <= 2350)))
                {
                    //cout << "pos de x = " << (pers.perso_sprite.getPosition().x+62.5) << endl;
                    //cout << "pos de y = " << (planeteSoleil.planete_sprite.getPosition().x+1250) << endl;
                    //cout << "x = " << (((pers.perso_sprite.getPosition().x+62.5) - (planeteSoleil.planete_sprite.getPosition().x+62.5))) << endl;
                    pers.perso_sprite.setPosition(pers.perso_sprite.getPosition().x+50, pers.perso_sprite.getPosition().y+50);
                    pers.perso_sprite.setRotation(270);
                }*/
                //________________

                for (size_t i (0); i< univers.planetes.size();i++){
                    if((vaisseau.getX() >= univers.planetes[i].getX()+200 && vaisseau.getX() <= univers.planetes[i].getX()+800)
                       && (vaisseau.getY() >= univers.planetes[i].getY()+200 && vaisseau.getY() <= univers.planetes[i].getY() + 800))
                    {
                        affichage = 1;
                        planeteEnCours = univers.planetes[i];

                            //cout << "Voulez-vous vraiment atterir?" << endl;


                            switch (event.type)
                            {
                                case sf::Event::KeyReleased:
                                switch(event.key.code)
                                {
                                    case sf::Keyboard::Return:
                                        cout << "Vous avez bien attéri" << endl;
//                                        windowJeu.setActive(false);
                                        windowJeu.close();
                                        //combat --> background en fonction planete

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

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                    map_space(windowJeu);
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
            text.setString("appuyez sur la touche enter pour atterir");
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

void Gestion::pause(sf::RenderWindow & windowJeu)
{
    sf::RenderWindow windowJeu2(sf::VideoMode(1500, 900), "Spacecraft vs Asteroids",sf::Style::Fullscreen);
    menu(windowJeu2);
}

void Gestion::map_space(sf::RenderWindow & windowJeu)
{
cout << "map"<<endl;
//sf::View view(sf::FloatRect(2500, 2500, 2500, 2500));
//view.setSize(13500, 13500);
}



