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
#include "PersonnageHeros.h"
#include "PersonnageBoss.h"
#include "Menu.h"
#include "Compte.h"

using namespace std;

Gestion::Gestion()
{
    this->univers = univers;
    this->vaisseau = vaisseau;
    vector <Planete*> planetes(6);
    vector <Planete*> planetesInacc(3);
    vector <PersonnageBoss*> boss(6);

    planetes[0] = new Planete("Bleue", "Images/Planetes/Bleu.png", 2000, 750, 319, 650); //319
    planetes[1] = new Planete("Orange", "Images/Planetes/Orange.png", 9000, 1250, 291, 450); //291
    planetes[2] = new Planete("Mauve_Detruite", "Images/Planetes/Mauve_Detruite.png", 7000, 5500, 417, 700); //417
    planetes[3] = new Planete("Anneau_Rouge", "Images/Planetes/Anneau_Rouge.png", 11000, 3000, 1083, 810); //1083
    planetes[4] = new Planete("Verte", "Images/Planetes/Verte.png", 5000, 3200, 703, 700); //703
    planetes[5] = new Planete("Anneau_Bleu", "Images/Planetes/Anneau_Bleu.png", 1500, 5100, 318, 823); //318

    planetesInacc[0] = new Planete("Mort", "Images/Planetes/Etoile_De_La_Mort.png", 8000, 6120, 200, 300);
    planetesInacc[1] = new Planete("Plateforme", "Images/Planetes/Plateforme.png", 6900, 3300, 200, 300);
    planetesInacc[2] = new Planete("Soleil", "Images/Planetes/Soleil.png", 12000, 0, 200, 300);

    boss[0] = new PersonnageBoss("BossBleu",BLEUE);
    boss[1] = new PersonnageBoss("BossOrange",ORANGE);
    boss[2] = new PersonnageBoss("BossMauve",MAUVE_DETRUITE);
    boss[3] = new PersonnageBoss("BossRouge",ANNEAU_ROUGE);
    boss[4] = new PersonnageBoss("BossVert",VERTE);
    boss[5] = new PersonnageBoss("BossAnneauBleu",ANNEAU_BLEU);


    for ( size_t i = 0; i < planetes.size(); i++ )
    {
        for ( size_t j = 0; j < boss.size(); j++ )
        {
            if(boss[j]->getOrigine() == i){
                planetes[i]->DonnerBoss(*boss[j]);
            }
        }
        univers.add(planetes[i]);
    }

    for ( size_t i = 0; i < planetesInacc.size(); i++ )
    {
        univers.addInacc(planetesInacc[i]);
    }



}

void Gestion::fenetrePrincipale()
{
    /*MUSIQUE*/
//    sf::SoundBuffer Buffer;
//    if (!Buffer.loadFromFile("Musiques/MusiqueMenu.wav"))
//    {
//        cout << "Pas de musique sélectionnée" <<endl;
//    }
//    sf::Sound sound;
//    sound.setBuffer(Buffer);
//
//    sound.setLoop(true);
//    sound.play();

    sf::RenderWindow windowJeu(sf::VideoMode(1600, 900), "Spacecraft vs Asteroids"/*, sf::Style::Fullscreen*/);
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
                        compte(windowJeu);
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

void Gestion::compte(sf::RenderWindow & windowJeu)
{
	Compte compte;
	PersonnageHeros p1("Test", HUMAIN);

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
                    compte.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    compte.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch(compte.GetPressedItem())
                    {
                    case 0:
                        p1.setRace(HUMAIN);
//                        PersonnageHeros* p1 = new PersonnageHeros("Humain",HUMAIN);
                        cout << p1.str() << endl;
                        launch(windowJeu);
//                        cout << p1->str() << endl;

                        break;

                    case 1:
                        p1.setRace(VALDERA);
                        cout << p1.str() << endl;
                        launch(windowJeu);
//                        PersonnageHeros* p1 = new PersonnageHeros("VALDERA",VALDERA);
//                        cout << p1->str() << endl;

                        break;

                    case 2:
                        p1.setRace(VANDUUL);
                        cout << p1.str() << endl;
                        launch(windowJeu);
//                        PersonnageHeros* p1 = new PersonnageHeros("VANDUUL",VANDUUL);
//                        cout << p1->str() << endl;

                       break;

                    case 3:
                        p1.setRace(COVENANTE);
                        cout << p1.str() << endl;
                        launch(windowJeu);
//                        PersonnageHeros* p1 = new PersonnageHeros("COVENANTE",COVENANTE);
//                        cout << p1->str() << endl;

                       break;

                    case 4:
                        p1.setRace(AETWI);
                        cout << p1.str() << endl;
                        launch(windowJeu);
//                        PersonnageHeros* p1 = new PersonnageHeros("AETWI",AETWI);
//                        cout << p1->str() << endl;

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

		compte.draw(windowJeu);

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
                    if((vaisseau.getX() >= univers.planetes[i]->getX()+200 && vaisseau.getX() <= univers.planetes[i]->getX()+800)
                       && (vaisseau.getY() >= univers.planetes[i]->getY()+200 && vaisseau.getY() <= univers.planetes[i]->getY() + 800))
                    {
                        affichage = 1;
                        planeteEnCours = *univers.planetes[i];
                        univers.planetes[i]->getBoss();
                        planeteEnCours.getBoss();
                            switch (event.type)
                            {
                                case sf::Event::KeyReleased:
                                switch(event.key.code)
                                {
                                    case sf::Keyboard::Return:
                                        cout << "Vous avez bien attéri" << endl;

                                        biomtest.setBackground("Images/Backgrounds/"+planeteEnCours.getNom()+"_Background.png");


                                        cout << planeteEnCours.getNom() << endl;

                                        planeteEnCours.DonnerBiome(biomtest);
                                      //  planeteEnCours.DonnerBoss(persoBoss);


                                        //combatPlanete(windowJeu,*planeteEnCours.getBiome());
                                        //combatPlanete(windowJeu,univers.planetes[i]);
                                        combatPlanete(windowJeu,planeteEnCours);


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
                        if(*univers.planetes[i] == planeteEnCours){
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
                windowJeu.draw(*univers.planetes[i]);
            }

            for(size_t i(0); i < univers.planetesInaccessibles.size(); i++)
            {
                windowJeu.draw(*univers.planetesInaccessibles[i]);
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
        windowJeu.draw(univers.univers_sprite);

        for(size_t i(0);i<univers.planetes.size();i++)
        {
            windowJeu.draw(*univers.planetes[i]);
        }

        for(size_t i(0); i < univers.planetesInaccessibles.size(); i++)
        {
            windowJeu.draw(*univers.planetesInaccessibles[i]);
        }

        windowJeu.draw(text);
        windowJeu.display();

    }
}

void Gestion::combatPlanete(sf::RenderWindow & windowJeu,Planete& pla)
{
    sf::View view(sf::FloatRect(2048, 1024, 2048, 1024));
    view.setCenter(1024, 512);

    windowJeu.setView(view);
//    PersonnageHeros pHeros("Baptaber", VANDUUL);
//ERROr
//   cout <<  pla.getBoss()->getNom() << endl;

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
//       cout << "test " << endl;
        //windowJeu.draw(bio.biome_sprite);
        windowJeu.draw(pla.getBiome()->biome_sprite);

        //cout << pla.getBoss()->getNom() << endl;
        //cout <<pla.getNom() <<endl;
        windowJeu.draw(pla.getBoss()->personnage_sprite);
       // windowJeu.draw(heroTest.personnage_sprite);
//        windowJeu.draw(pHeros.persoHeros_sprite);
        windowJeu.display();

    }


}

