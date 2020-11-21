#include "PersonnageBoss.h"
#include "Planete.h"

PersonnageBoss::PersonnageBoss(const string nom, const int ptsAttaque, const int ptsVie, const int ptsExperience, const int niveau,
    const int ptsAttaqueSpeciale, const int bouclier, const double coupsCritique, const double esquive, const Origine origine)
    :Personnage(nom,ptsAttaque,ptsVie,ptsExperience,niveau,ptsAttaqueSpeciale,bouclier,coupsCritique,esquive),origine(origine)
{
    Planete plan;
    categorieBoss();
    //ctor
}

PersonnageBoss::PersonnageBoss(const string nom, const Origine origine)
    :Personnage(nom),origine(origine)
{
    categorieBoss();
    //ctor
}

PersonnageBoss::~PersonnageBoss()
{
    //dtor
}

PersonnageBoss::PersonnageBoss(const PersonnageBoss& pB):Personnage(pB),origine(pB.origine)
{
    //copy ctor
}

PersonnageBoss& PersonnageBoss::operator=(const PersonnageBoss& pB)
{
    if (this != &pB){

            // handle self assignment
            Personnage::operator=(pB);
            origine = pB.origine;

         }
    return *this;
}


void PersonnageBoss::categorieBoss() {
    switch(origine)
    {
    case TERRE:
        cout << "Terre" << endl;
        break;
    case POLAIRE:
        cout << "Polaire" << endl;
        break;
    case FEU:
        cout << "FEU" << endl;
        break;
        default:
            break;
    }



}





string PersonnageBoss::str() const
{
    std::stringstream ss;
    ss << Personnage::str() << "\n\t"
        << to_string(origine);
        return ss.str();
}
