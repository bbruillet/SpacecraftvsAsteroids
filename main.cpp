#include <iostream>
#include <list>

#include "Management.h"
#include "Character.h"
#include "CharacterBoss.h"
#include "CharacterHero.h"
#include "CharacterView.h"
#include "Fight.h"
#include "Planet.h"
#include <SFML/Audio.hpp>
#include "BarView.h"

using namespace std;


int main()
{
    Management management;
    management.mainWindow();



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
