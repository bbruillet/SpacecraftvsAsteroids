#include "Gestion.h"

#include <SFML/Graphics.hpp>

#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>

#include "Personnage.h"
#include "Deplacement.h"
#include "Univers.h"
#include "Planete.h"

#include "Menu.h"

using namespace std;

Gestion::Gestion()
{
//    sf::RenderWindow windowJeu(sf::VideoMode(900, 900), "Spacecraft vs Asteroids");

}



void Gestion::menu()
{
//    do {
//        cout<<endl<<" ----------------------- MENU -----------------------"<<endl<<endl;
//        cout<<"1. Jouer"<<endl;
//        cout<<"2. Voir la map"<<endl;
//        cin>>choixMenu;
//        cout<<endl;
//        sf::SoundBuffer Buffer;
//            if (!Buffer.loadFromFile("MusiqueMenu.wav")){
//
//            }
//        sf::Sound sound;
//        sound.setBuffer(Buffer);
//
//        sound.setLoop(true);
//        sound.play();
//
//        switch(choixMenu)
//        {
//            case 1 : launch();
//            break;
//
//            case 2 : launch();
//            break;
//        }
//    }while(choixMenu!=0);

    //sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");
sf::RenderWindow windowJeu(sf::VideoMode(900, 900), "Spacecraft vs Asteroids");
    sf::SoundBuffer Buffer;
            if (!Buffer.loadFromFile("MusiqueMenu.wav")){

            }
        sf::Sound sound;
        sound.setBuffer(Buffer);

        sound.setLoop(true);
        sound.play();


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
                        launch();
//                        window.close();
                        break;

                    case 1:
                        std::cout << "Option button has been pressed" << std::endl;
                        break;

                    case 2:

                        windowJeu.close();
;
                        default:
                        break;
                    }

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

void Gestion::launch()
{
sf::RenderWindow windowJeu(sf::VideoMode(900, 900), "Spacecraft vs Asteroids");

    //Sound.SetLoop(true);
//    sound.play();

    sf::View view(sf::FloatRect(2500, 2500, 2500, 2500));
    view.setCenter(7150, 3500);

    if(choixMenu == 1) {
        view.setSize(2500,2500);
    }
    else if(choixMenu == 2) {
        view.setSize(13500, 13500);
    }
    Personnage pers;
    Univers univers; //Taille 13883x7500

    Planete planeteBleu("Blue", "images/Bleu.png", 2000, 750);
    Planete planeteOrange("Orange", "images/Orange.png", 9000, 1250);
    Planete planeteMauve("Mauve_Detruite", "images/Mauve_Detruite.png", 7000, 5500);
    Planete planeteMort("Mort", "images/Etoile_De_La_Mort.png", 8000, 6120);
    //Ok
    Planete planeteRouge("Anneau_Rouge", "images/Anneau_Rouge.png", 11000, 3000);
    //ok
    Planete planeteVerte("Verte", "images/Verte.png", 5000, 3200);
    //ok
    Planete planetePlateforme("Plateforme", "images/Plateforme.png", 6900, 3300);
    Planete planeteAnneauBleu("Anneau_Bleu", "images/Anneau_Bleu.png", 1500, 5100);
    //ok
    Planete planeteSoleil("Soleil", "images/Soleil.png", 11250, 100);
    univers.add(planeteBleu);
    univers.add(planeteOrange);
    univers.add(planeteRouge);
    univers.add(planeteMauve);
    univers.add(planeteMort);
    univers.add(planeteVerte);
    univers.add(planetePlateforme);
    univers.add(planeteAnneauBleu);
    univers.add(planeteSoleil);

    //Planete planete;



    int x = pers.getX();
    int y = pers.getY();

    int a,b;

    while (windowJeu.isOpen())
        {
            sf::Event event;
            while (windowJeu.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    menu();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                    view.setSize(13500, 13500);
                }

                if(event.type == sf::Event::EventType::KeyPressed)
                {
                    a = x;
                    b = y;


                    x = pers.seDeplacerX(event, x);
                    y = pers.seDeplacerY(event, y);

                    a = x-a;
                    b = y-b;
                    view.move(a,b);

                    pers.setX(x);
                    pers.setY(y);
                    pers.perso_sprite.setPosition(x,y);
                }
            }



            windowJeu.clear();
            windowJeu.setView(view);
            windowJeu.draw(univers.univers_sprite);
//            planete.show(0, 3000, 1000);
            for(size_t i(0);i<univers.planetes.size();i++){
                windowJeu.draw(univers.planetes[i]);
            }

            //window.draw(planete.sprites[1]);
//            planete.show(1, 7000, 3500);
//            window.draw(test);
//            window.draw(planete2.planete_sprite);
            windowJeu.draw(pers.perso_sprite);
            windowJeu.display();

        }
}
