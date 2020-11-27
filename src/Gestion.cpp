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
    planetes[0] = new Planete("Bleue", "Images/Planetes/Bleu.png", 2000, 750, 319, 525); //319
    planetes[1] = new Planete("Orange", "Images/Planetes/Orange.png", 9000, 1250, 291, 520); //291
    planetes[2] = new Planete("Mauve_Detruite", "Images/Planetes/Mauve_Detruite.png", 7000, 5500, 417, 600); //417
    planetes[3] = new Planete("Anneau_Rouge", "Images/Planetes/Anneau_Rouge.png", 11000, 3000, 1083, 400); //1083
    planetes[4] = new Planete("Verte", "Images/Planetes/Verte.png", 5000, 3200, 703, 600); //703
    planetes[5] = new Planete("Anneau_Bleu", "Images/Planetes/Anneau_Bleu.png", 1500, 5100, 318, 575); //318

    planetesInacc[0] = new Planete("Mort", "Images/Planetes/Etoile_De_La_Mort.png", 8000, 6120, 0, 0);
    planetesInacc[1] = new Planete("Plateforme", "Images/Planetes/Plateforme.png", 6900, 3300, 0, 0);
    planetesInacc[2] = new Planete("Soleil", "Images/Planetes/Soleil.png", 12000, 0, 0, 0);

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
    sf::SoundBuffer Buffer;
    if (!Buffer.loadFromFile("Musiques/Musique_Menu.wav"))
    {
        cout << "Pas de musique sélectionnée" <<endl;
    }
    sf::Sound sound;
    sound.setBuffer(Buffer);

    sound.setLoop(true);
    sound.play();

    sf::RenderWindow windowJeu(sf::VideoMode(1600, 900), "Spacecraft vs Asteroids"/*, sf::Style::Fullscreen*/);
    //menu(windowJeu);
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
                        comptePerso(windowJeu);
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

void Gestion::comptePerso(sf::RenderWindow & windowJeu)
{
	//PersonnageHeros p1("Joueur1", HUMAIN);

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
                    compte.haut();
                    break;

                case sf::Keyboard::Down:
                    compte.bas();
                    break;

                case sf::Keyboard::Return:
                    switch(compte.getElementPresse())
                    {
                    case 0:
                        heros.setRace(HUMAIN);
                        comptePseudo(windowJeu);

                        break;

                    case 1:
                        heros.setRace(VALDERA);
                        comptePseudo(windowJeu);
//

                        break;

                    case 2:
                        heros.setRace(VANDUUL);
                        comptePseudo(windowJeu);
//

                       break;

                    case 3:
                        heros.setRace(COVENANTE);
                        comptePseudo(windowJeu);
//

                       break;

                    case 4:
                        heros.setRace(AETWI);

                        comptePseudo(windowJeu);
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

		compte.dessiner(windowJeu);

		windowJeu.display();
	}
}

void Gestion::comptePseudo(sf::RenderWindow & windowJeu)
{
    compte.PseudoUtilisateur(windowJeu);
    heros.setNom(compte.getPseudo());


    launch(windowJeu);
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

                            switch (event.type)
                            {
                                case sf::Event::KeyReleased:
                                switch(event.key.code)
                                {
                                    case sf::Keyboard::Return:
                                        cout << "Vous avez bien attéri" << endl;

                                        biomtest.setBackground("Images/Backgrounds/"+planeteEnCours.getNom()+"_Background.png");




                                        cout << "X :" + to_string(planeteEnCours.getXPerso()) << endl;
                                        cout << "Y :" + to_string(planeteEnCours.getYPerso()) << endl;

                                        planeteEnCours.DonnerBiome(biomtest);
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


                    x = viewVaisseau.seDeplacerX(event, x);
                    y = viewVaisseau.seDeplacerY(event, y);

                    a = x-a;
                    b = y-b;
                    view.move(a,b);

                    vaisseau.setX(x);
                    vaisseau.setY(y);
                    viewVaisseau.vaisseau_sprite.setPosition(x,y);
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

            viewVaisseau.setVaisseau(vaisseau);
            viewVaisseau.drawVaisseau(windowJeu);
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

    versus_sprite.setTexture(versus_texture);
    versus_sprite.setPosition(775, -25);

    sf::Text textHeros;
    sf::Text textBoss;

    textHeros.setFont(font);
    textBoss.setFont(font);

    textHeros.setFillColor(sf::Color::Yellow);
    textBoss.setFillColor(sf::Color::Yellow);

    textHeros.setCharacterSize(30);
    textBoss.setCharacterSize(30);

    pView.setPersonnageBoss(*pla.getBoss());
    pView.setPersonnageHeros(heros);


    barreHeros.setVieMax(heros.getPtsVie());
    barreHeros.setPositionBarre(650,75);
    barreHeros.setPositionBarreBouclier(800,100);
    barreHeros.setBouclierMax(heros.getBouclier());

    barreBoss.setPositionBarre(1400,75);
    barreBoss.setVieMax(pla.getBoss()->getPtsVie());
    barreBoss.setPositionBarreBouclier(1250,100);
    barreBoss.setBouclierMax(pla.getBoss()->getBouclier());

    barreHeros.setRotation();


    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

    windowJeu.setView(view);
    while (windowJeu.isOpen())
    {


        sf::Event event;
        while (windowJeu.pollEvent(event))
        {

            if(heros.getPtsVie() > 0 && pla.getBoss()->getPtsVie() > 0 ){



                combat.combatBoss(heros,*pla.getBoss(), windowJeu);


                for(size_t i(0);i<50;i++)
                {
                    windowJeu.clear();
                    pView.course();
                    pView.personnage_heros_sprite.setPosition(pla.getXPerso()+ 16*i, pla.getYPerso());
                    pla.getBiome()->draw(windowJeu);
                    barreHeros.drawVie(windowJeu);
                    barreHeros.drawBouclier(windowJeu);
                    barreBoss.drawVie(windowJeu);
                    barreBoss.drawBouclier(windowJeu);
                    pView.drawHeros(windowJeu);
                    pView.drawBoss(windowJeu);
                    windowJeu.draw(versus_sprite);
                    windowJeu.draw(textHeros);
                    windowJeu.draw(textBoss);
                    windowJeu.display();
                    sf::sleep(sf::milliseconds(10));
                }
                    barreHeros.updateV(heros.getPtsVie());
                    barreHeros.updateB(heros.getBouclier());

                    barreBoss.updateV(pla.getBoss()->getPtsVie());
                    barreBoss.updateB(pla.getBoss()->getBouclier());
                    pView.rectHeros.left = 0;


            }
            else
            {
                    cout << "Victoire" << endl;
                    pView.getPersonnageHeros().categorieHeros();
                    launch(windowJeu);

            }

            if (event.type == sf::Event::Closed)
            {
                windowJeu.clear();
                launch(windowJeu);
            }



        }
        windowJeu.clear();

        pla.getBiome()->draw(windowJeu);
        textHeros.setPosition(400, 20);
        textBoss.setPosition(1150, 20);
        pView.personnage_heros_sprite.setPosition(pla.getXPerso(), pla.getYPerso());



        textHeros.setString(pView.getPersonnageHeros().getNom());
        textBoss.setString(pla.getBoss()->getNom());
        barreHeros.drawVie(windowJeu);
        barreHeros.drawBouclier(windowJeu);
        barreBoss.drawVie(windowJeu);
        barreBoss.drawBouclier(windowJeu);
        pView.drawHeros(windowJeu);
        pView.drawBoss(windowJeu);
        windowJeu.draw(versus_sprite);
        windowJeu.draw(textHeros);
        windowJeu.draw(textBoss);

        //windowJeu.draw(pla.getBoss()->personnage_sprite);
        windowJeu.display();

    }


}

