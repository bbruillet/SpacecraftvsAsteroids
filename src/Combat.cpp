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
void Combat::attaquerBoss(Personnage &p1,Personnage &p2)
{
    cout << "COMPTEUR REGEN " + to_string(nbRegen) << endl;
    int choix;
    if (nbRegen == 0){
        choix = 1;
    }
    else
    {
    cout << "1 = ATTAQUE 2 = REGEN" << endl;

    cin >> choix;

    }

    //ATTAQUE
    if (choix == 1){

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

            p2.setPtsVie(p2.getPtsVie()-attaque);
            p1.setCompteurSpe(p1.getCompteurSpe() + 1);
            cout << p1.str() << endl << endl;
            cout << p2.str() << endl;
    }
    //Regen
    else if (choix == 2)
    {
        cout << "REGEN de "+p1.getNom() << endl;
        p1.setPtsVie(p1.getPtsVie() + p1.getRegeneration());
        nbRegen--;
        if(nbRegen == 0){
        cout << "VOUS NE POUVEZ PLUS REGEN !" << endl;
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
            if(p2.getBouclier() > 0) {
            p2.setPtsVie(p2.getBouclier()+p2.getPtsVie());
            p2.setBouclier(0);


        }

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
        cout << "------------------------------------" << endl;
        cin >> test;
          if ( test > 0){
            nbPrem = (rand()% 2) +1;


            //p1.setPtsVie(p1.getPtsVie() + p.getRegeneration);

            if(nbPrem == 1){
                attaquerBoss(p1,p2);
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
                    attaquerBoss(p1,p2);

                    if(p2.getPtsVie() == 0){
                        cout << "mort de p2";
                    }
                }
            }
        }
    }
}
