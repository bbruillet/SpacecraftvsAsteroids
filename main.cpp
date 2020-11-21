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

    Combat c;

    cout << p1.str() << "\n\n\n" << p2.str() << "\n\n\n\n------\n\n"<< endl;

    c.combatBoss(p1, p2);

    return 0;
}
