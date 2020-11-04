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

    sf::View view(sf::FloatRect(2000, 2000, 2000, 2000));
    view.setCenter(3750, 2026);

    Personnage pers;
//    Deplacement dep;
    Univers univers;
    Planete planete("Blue", "Bleu.png", 3000, 1000);
    Planete planete2("Orange", "DeathStar.png", 7000, 3500);
//    Planete planete;

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
            window.draw(planete.planete_sprite);
            window.draw(planete2.planete_sprite);
            window.draw(pers.perso_sprite);
            window.display();
        }
}
