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

void Combat::attaquer(Personnage &p1, Personnage &p2)
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
            if(p2.getBouclier() > 0) {
            p2.setPtsVie(p2.getBouclier()+p2.getPtsVie());
            p2.setBouclier(0);


        }

            nb = (rand()% 100) +1;


            cout << "\n-------------\n" << to_string(nb) << "\n-------------\n" << endl;
            if (nb <= p1.getCoupsCritique())
            {
                cout << "Attaque critique !" << endl;
                attaque *= 2;
            }
    }

    nbEsquive = (rand()%100) + 1;
//    nbEsquive = (rand()%100) + 1;
    if(nbEsquive <= p2.getEsquive())
    {
        cout << "Esquive dans ta gueule de " << p2.getNom() << endl;
        attaque = 0;
    }

    p2.setPtsVie(p2.getPtsVie()-attaque);
    p1.setCompteurSpe(p1.getCompteurSpe() + 1);
    cout << p1.str() << endl << endl;
    cout << p2.str() << endl;
}

void Combat::combatBoss(Personnage &p1, Personnage &p2)
{
    int round = 0;
    int test = 0;

    while(p1.getPtsVie() > 0 && p2.getPtsVie() > 0)
    {
        round ++;
        cout << "Round numéro "+to_string(round) << endl;
        cout << "Entrez un chiffre pour démarrer un round\n" << endl;
        cout << "------------------------------------\n" << endl;
        cin >> test;
          if ( test >= 0){
            nbPrem = (rand()% 2) +1;


            //p1.setPtsVie(p1.getPtsVie() + p.getRegeneration);



            if(nbPrem == 1){
                attaquer(p1,p2);
                if(p2.getPtsVie() > 0)
                {
                    attaquer(p2,p1);
                    if(p1.getPtsVie() == 0){
                        cout << "mort de p1" << endl;
                    }
                }
            }
            if (nbPrem ==2)
            {
                attaquer(p2,p1);
                if(p1.getPtsVie() > 0)
                {
                    attaquer(p1,p2);

                    if(p2.getPtsVie() == 0){
                        cout << "mort de p2";
                    }
                }
            }
        }
    }
}
