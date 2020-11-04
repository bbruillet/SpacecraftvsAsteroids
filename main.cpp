#include <iostream>
#include <list>

#include "Gestion.h"

using namespace std;


int main()
{
    int choix;

//    cout << "Entrez votre nom : ";
//    cin <<
    cout << "1 --> Lancer le jeu" << endl;
    cout << "Faites votre choix: ";
    cin >> choix;

    if (choix == 1)
    {
        Gestion gestion;
        gestion.launch();
    }

    return 0;
}
