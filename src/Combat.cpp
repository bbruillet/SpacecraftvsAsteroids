#include "Combat.h"
#include <stdlib.h>
//#include <stdio.h>
#include <time.h>

#include "Personnage.h"
#include "PersonnageHeros.h"
//#include "PersonnageBoss.h"

Combat::Combat()
{
    srand((int)time(0));
    nbRegen = 2;
}

Combat::~Combat()
{
    //dtor
}

Combat::Combat(const Combat& other)
{
    //copy ctor
}

Combat& Combat::operator=(const Combat& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


//Heros attaque Boss
void Combat::attaquerBoss(Personnage &p1,Personnage &p2, sf::RenderWindow &windowJeu)
{


    while(windowJeu.isOpen())
    {
        sf::Event event;
        while (windowJeu.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::A:
                    int attaque;
                    if(p1.getCompteurSpe() == 3)
                    {
                        attaque = p1.getPtsAttaqueSpeciale();
                        p1.setCompteurSpe(-1);
                        cout << "Coup spécial de " << p1.getNom() << endl;
                    }

                    else
                    {
                        cout << "Coup physique de " << p1.getNom() << endl;
                        attaque = p1.getPtsAttaque();
                         /*   if(p2.getBouclier() > 0) {
                            p2.setPtsVie(p2.getBouclier()+p2.getPtsVie());
                            p2.setBouclier(0);

                        }*/

                            nb = (rand()% 100) +1;


                            cout << "\n-------------\n" << to_string(nb) << "\n-------------\n" << endl;
                            if (nb <= p1.getCoupsCritique())
                            {
                                cout << "Attaque critique !" << endl;
                                attaque = attaque + (p1.getPtsAttaque()/2);
                                cout << attaque << endl;
                            }
                    }

                    nbEsquive = (rand()%100) + 1;
                //    nbEsquive = (rand()%100) + 1;
                    if(nbEsquive <= p2.getEsquive())
                    {
                        cout << p2.getNom() << " a esquivé ton attaque" << endl;
                        attaque = 0;
                    }

                    if(p2.getBouclier() > 0) {
                            if(p2.getBouclier() > attaque){
                                p2.setBouclier(p2.getBouclier() - attaque);
                            }
                            else if(p2.getBouclier() == attaque)
                                {
                                    p2.setBouclier(0);
                                }
                                else
                                {
                                 attaque = attaque - p2.getBouclier();
                                 p2.setBouclier(0);
                                p2.setPtsVie(p2.getPtsVie()-attaque);
                                }
                    }
                    else
                    {
                        p2.setPtsVie(p2.getPtsVie()-attaque);
                    }

                    p1.setCompteurSpe(p1.getCompteurSpe() + 1);
                    cout << p1.str() << endl << endl;
                    cout << p2.str() << endl;
                    return;
                    break;
                case sf::Keyboard::R:
                    if(nbRegen == 0)
                    {
                        cout << "VOUS DEVEZ ATTAQUER !" << endl;
                    } else
                    {
                        cout << "REGEN de "+p1.getNom() << endl;
                        p1.setPtsVie(p1.getPtsVie() + p1.getRegeneration());
                        nbRegen--;
                        return;

                    }

                    break;
                default:
                    break;
                }
                break;
                default:
                    break;
            }
        }
    }

}

//Boss attaque Heros
void Combat::attaquerHeros(Personnage &p1, Personnage &p2)
{
    int attaque;
    if(p1.getCompteurSpe() == 3)
    {
        attaque = p1.getPtsAttaqueSpeciale();
        p1.setCompteurSpe(-1);
        cout << "Coup spécial de " << p1.getNom() << endl;
    }

    else
    {
        cout << "Coup physique de " << p1.getNom() << endl;
        attaque = p1.getPtsAttaque();


            nb = (rand()% 100) +1;


            cout << "\n-------------\n" << to_string(nb) << "\n-------------\n" << endl;
            if (nb <= p1.getCoupsCritique())
            {
                cout << "Attaque critique !" << endl;
                attaque = attaque + (p1.getPtsAttaque()/2);
                cout << attaque << endl;
            }
    }

    nbEsquive = (rand()%100) + 1;
//    nbEsquive = (rand()%100) + 1;
    if(nbEsquive <= p2.getEsquive())
    {
        cout << "Esquive de" << p2.getNom() << endl;
        attaque = 0;
    }

                       if(p2.getBouclier() > 0) {
                            if(p2.getBouclier() > attaque){
                                p2.setBouclier(p2.getBouclier() - attaque);
                            }
                            else if(p2.getBouclier() == attaque)
                                {
                                    p2.setBouclier(0);
                                }
                                else
                                {
                                 attaque = attaque - p2.getBouclier();
                                 p2.setBouclier(0);
                                p2.setPtsVie(p2.getPtsVie()-attaque);
                                }
                    }
                    else
                    {
                        p2.setPtsVie(p2.getPtsVie()-attaque);
                    }
    p1.setCompteurSpe(p1.getCompteurSpe() + 1);
    cout << p1.str() << endl << endl;
    cout << p2.str() << endl;
}

void Combat::combatBoss(Personnage &p1, Personnage &p2, sf::RenderWindow &windowJeu)
{
    int round = 0;
//    int test = 0;
        round ++;
        cout << "Round numéro "+to_string(round) << endl;


            nbPrem = (rand()% 2) +1;


            //p1.setPtsVie(p1.getPtsVie() + p.getRegeneration);

            if(nbPrem == 1){
                attaquerBoss(p1,p2,windowJeu);
                if(p2.getPtsVie() > 0)
                {
                    attaquerHeros(p2,p1);
                    if(p1.getPtsVie() == 0){
                        cout << "mort de p1" << endl;
                    }
                }
            }
            if (nbPrem ==2)
            {
                attaquerHeros(p2,p1);
                if(p1.getPtsVie() > 0)
                {
                    attaquerBoss(p1,p2,windowJeu);

                    if(p2.getPtsVie() == 0){
                        cout << "mort de p2";
                    }
                }
            }

}
