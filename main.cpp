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
    PersonnageHeros p4("Fitspade", COVENANTE);


    Combat c;

    cout << p4.str() << "\n\n\n" << p3.str() << "\n\n\n\n------\n\n"<< endl;

    c.combatBoss(p4, p3);

    return 0;
}
