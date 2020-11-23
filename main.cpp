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

    Gestion gestion;
    gestion.fenetrePrincipale();

        /**
        *
        *--------------------
        *
        */
//
//    PersonnageHeros p1("Baptaber", VANDUUL);
//    PersonnageHeros p2("Young $hmet", AETWI);
//    PersonnageHeros p3("DanzZ",VALDERA);
//    PersonnageHeros p4("Fitspade", COVENANTE);

//PersonnageBoss p1("Baptiste", BLEUE);
/*PersonnageBoss p2("Loris", VERTE);
PersonnageBoss p3("Baptiste2", ORANGE);
PersonnageBoss p4("Loris2", ANNEAU_BLEU);
PersonnageBoss p5("Baptiste3", ANNEAU_ROUGE);
PersonnageBoss p6("Loris3", MAUVE_DETRUITE);*/

//cout << p1.str() << endl;



//
//    Combat c;
//
//    cout << p3.str() << "\n\n\n" << p1.str() << "\n\n\n\n------\n\n"<< endl;
//
//    c.combatBoss(p3, p1);

    return 0;
}
