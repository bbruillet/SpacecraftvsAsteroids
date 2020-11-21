#include "PersonnageHeros.h"

PersonnageHeros::PersonnageHeros(const string nom, const int ptsAttaque, const int ptsVie, const int ptsExperience, const int niveau,
    const int ptsAttaqueSpeciale, const int bouclier, const double coupsCritique, const double esquive, const Race race)
    :Personnage(nom,ptsAttaque,ptsVie,ptsExperience,niveau,ptsAttaqueSpeciale,bouclier,coupsCritique,esquive),race(race)
{
    categorieHeros();
    //ctor
}

PersonnageHeros::PersonnageHeros(const string nom, const Race race)
    :Personnage(nom),race(race)
{
    categorieHeros();
    //ctor
}

PersonnageHeros::~PersonnageHeros()
{
    //dtor
}

PersonnageHeros::PersonnageHeros(const PersonnageHeros& pH):Personnage(pH),race(pH.race)
{

}

PersonnageHeros& PersonnageHeros::operator=(const PersonnageHeros& pH)
{
    if (this != &pH)
        {
            Personnage::operator=(pH);
            race = pH.race;
        } // handle self assignment
    //assignment operator
    return *this;
}

void PersonnageHeros::categorieHeros() {
    switch(race) {
    case HUMAIN:
        setPtsVie(150);
        setPtsAttaque(10);
        setPtsAttaqueSpeciale(15);
        setBouclier(10);

        setCoupsCritique(25.00);
        setEsquive(50.00);

        break;

    case VALDERA:
        setPtsVie(80);
        setPtsAttaque(15);
        setPtsAttaqueSpeciale(50);
        setBouclier(100);

        setCoupsCritique(30.00);
        setEsquive(40.00);

        break;
    case VANDUUL:
        setPtsVie(140);
        setPtsAttaque(20);
        setPtsAttaqueSpeciale(25);
        setBouclier(15);

        setCoupsCritique(40.00);
        setEsquive(35.00);
        setRegeneration(20);
        break;
    case COVENANTE:
        setPtsVie(250);
        setPtsAttaque(5);
        setPtsAttaqueSpeciale(15);
        setBouclier(0);

        setCoupsCritique(10.00);
        setEsquive(10.00);

        break;

    case AETWI:
        setPtsVie(160);
        setPtsAttaque(17);
        setPtsAttaqueSpeciale(26);
        setBouclier(26);

        setCoupsCritique(39.00);
        setEsquive(38.00);
        setRegeneration(10);

        break;
    default:
        break;
    }
}

string PersonnageHeros::str() const
{
    std::stringstream ss;
    ss << Personnage::str() << "\n\t"
        << to_string(race);
        return ss.str();
}
