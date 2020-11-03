#include <SFML/Graphics.hpp>


#include <iostream>
#include <vector>

#include "Personnage.h"
#include "Deplacement.h"
#include "Univers.h"

using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(850, 850), "Spacecraft vs Asteroids");

    sf::View view(sf::FloatRect(1000, 1000, 1000, 1000));
    view.setCenter(1000, 1000);


    Personnage perso;
    Univers univers;

    int x = perso.getX();
    int y = perso.getY();


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

                Deplacement dep;
                x = dep.seDeplacerX(event, x);
                y = dep.seDeplacerY(event, y);

                a = x-a;
                b = y-b;
                view.move(a,b);

                perso.setX(x);
                perso.setY(y);
                perso.perso_sprite.setPosition(x,y);
            }
        }



        window.clear();
        window.setView(view);
        window.draw(univers.univers_sprite);
        window.draw(perso.perso_sprite);
        window.display();
    }



    Personnage p("Nous <3", "Humain", 130, 1000, 0, 1);
    cout << p.str() << endl;

    return 0;
}
