#include <iostream>
#include <list>

#include "Gestion.h"
#include "Personnage.h"
#include "PersonnageBoss.h"
#include "PersonnageHeros.h"
#include "PersonnageView.h"
#include "Combat.h"
#include "Planete.h"
#include <SFML/Audio.hpp>
#include "BarreView.h"

using namespace std;


int main()
{
    Gestion gestion;
    gestion.fenetrePrincipale();



//sf::RenderWindow windowJeu(sf::VideoMode(1600, 900), "Spacecraft vs Asteroids"/*, sf::Style::Fullscreen*/);
//PersonnageHeros p;
//
//cout << p.str() << endl;
//BarreView barreVieHeros(sf::Vector2f(300,25),p.getPtsVie());

/*
PersonnageView pView(&p);
cout << pView.getPersonnage().str() << endl;
//int test = 0;
//cin >> test;

	while (windowJeu.isOpen())
	{
		sf::Event event;
		while (windowJeu.pollEvent(event))
		{

            p.setPtsVie(p.getPtsVie()-50);
            barreVieHeros.update(p.getPtsVie());
             sf::sleep(sf::milliseconds(1000));


        }


		windowJeu.clear();

		//pView.draw(windowJeu);
		barreVieHeros.draw(windowJeu);

		windowJeu.display();
		//windowJeu.close();

	}
	//cout << "ICI\t\t"+pView.getPersonnage().str() << endl;*/
    return 0;
}
