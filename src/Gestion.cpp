#include "Gestion.h"

#include <SFML/Graphics.hpp>


#include <iostream>
#include <vector>

#include "Personnage.h"
#include "Deplacement.h"
#include "Univers.h"
#include "Planete.h"

using namespace std;

Gestion::Gestion()
{
    //ctor
}

Gestion::~Gestion()
{
    //dtor
}

void Gestion::launch()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "Spacecraft vs Asteroids");

    sf::View view(sf::FloatRect(2500, 2500, 2500, 2500));
    view.setCenter(7150, 3500);

    Personnage pers;
//    Deplacement dep;
    Univers univers; //Taille 13883x7500

    Planete planeteBleu("Blue", "Bleu.png", 2000, 750);
    Planete planeteOrange("Orange", "Orange.png", 9000, 1250);
    Planete planeteMauve("Mauve_Detruite", "Mauve_Detruite.png", 7000, 5500);
    Planete planeteMort("Mort", "Etoile_De_La_Mort.png", 8000, 6120);
    //Ok
    Planete planeteRouge("Anneau_Rouge", "Anneau_Rouge.png", 11000, 3000);
    //ok
    Planete planeteVerte("Verte", "Verte.png", 5000, 3200);
    //ok
    Planete planetePlateforme("Plateforme", "Plateforme.png", 6900, 3300);
    Planete planeteAnneauBleu("Anneau_Bleu", "Anneau_Bleu.png", 1500, 5100);
    //ok
    Planete planeteSoleil("Soleil", "Soleil.png", 11250, 100);
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

    while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

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



            window.clear();
            window.setView(view);
            window.draw(univers.univers_sprite);
//            planete.show(0, 3000, 1000);
            for(int i= 0;i<9;i++){
                window.draw(univers.planetes[i]);
            }

            //window.draw(planete.sprites[1]);
//            planete.show(1, 7000, 3500);
//            window.draw(test);
//            window.draw(planete2.planete_sprite);
            window.draw(pers.perso_sprite);
            window.display();
        }
}
