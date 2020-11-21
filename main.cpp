#include <iostream>
#include <list>

#include "Gestion.h"
#include "Personnage.h"
#include "PersonnageHeros.h"
#include "PersonnageBoss.h"
#include "Combat.h"
#include "Planete.h"
#include <SFML/Audio.hpp>

using namespace std;


int main()
{

//    Gestion gestion;
//    gestion.fenetrePrincipale();

        /**
        *
        *--------------------
        *
        */

    PersonnageHeros p1("Baptaber", VANDUUL);
    PersonnageHeros p2("Young $hmet", AETWI);
    PersonnageHeros p3("DanzZ",VALDERA);

//    Planete plan1("Terre", "Images/Planetes/Bleu.png", 10, 10);
//    PersonnageBoss boss1("Monster",FEU);

//    Personnage p1("Fitspade", 40, 100, 0, 1, 20, 10, 60.0, 5.0);
//    Personnage p2("Dan'Zz", 15, 200, 0, 1, 20, 20, 10.0, 5.0);
    Combat c;

//    cout << p.str() << endl;
    cout << p1.str() << "\n\n\n" << p2.str() << "\n\n\n\n------\n\n"<< endl;

    c.combatBoss(p1, p2);
//    c.combatBoss(p2,p3);

    return 0;
}
