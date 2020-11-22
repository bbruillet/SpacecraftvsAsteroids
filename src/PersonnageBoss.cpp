#include "PersonnageBoss.h"
#include "Planete.h"

PersonnageBoss::PersonnageBoss(const string nom, const int ptsAttaque, const int ptsVie, const int ptsExperience, const int niveau,
    const int ptsAttaqueSpeciale, const int bouclier, const double coupsCritique, const double esquive, const int x, const int y, const string image,
    const int regeneration)
    :Personnage(nom,ptsAttaque,ptsVie,ptsExperience,niveau,ptsAttaqueSpeciale,bouclier,coupsCritique,esquive, x, y, image, regeneration)
{
    Planete plan;
    categorieBoss();
    //ctor
}

//PersonnageBoss::PersonnageBoss(const string nom)
//    :Personnage(nom)
//{
//    categorieBoss();
//    //ctor
//}

PersonnageBoss::~PersonnageBoss()
{
    //dtor
}

PersonnageBoss::PersonnageBoss(const PersonnageBoss& pB):Personnage(pB)
{
    //copy ctor
}

PersonnageBoss& PersonnageBoss::operator=(const PersonnageBoss& pB)
{
    if (this != &pB)
    {
        Personnage::operator=(pB);
    }
    return *this;
}


void PersonnageBoss::categorieBoss() {
    cout << "OK" << endl;



}



string PersonnageBoss::str() const
{
    std::stringstream ss;
    ss << Personnage::str();
        return ss.str();
}
