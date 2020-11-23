#include "PersonnageBoss.h"
#include "Planete.h"
#include "Personnage.h"


PersonnageBoss::PersonnageBoss(const string nom, const int ptsAttaque, const int ptsVie, const int ptsExperience, const int niveau,
    const int ptsAttaqueSpeciale, const int bouclier, const double coupsCritique, const double esquive, const int x, const int y, const string image, const int regeneration, const Origine origine)
:Personnage(nom,ptsAttaque,ptsVie,ptsExperience,niveau,ptsAttaqueSpeciale,bouclier,coupsCritique,esquive, x, y, image, regeneration), origine(origine)
{
   // Planete plan;
   categorieBoss();

    //ctor
}

PersonnageBoss::PersonnageBoss(const string nom, const Origine origine)
:Personnage(nom),origine(origine)
{
    categorieBoss();
}


PersonnageBoss::~PersonnageBoss()
{
    //dtor

}

PersonnageBoss::PersonnageBoss(const PersonnageBoss& pB):Personnage(pB), origine(pB.origine)
{
    categorieBoss();
}

PersonnageBoss& PersonnageBoss::operator=(const PersonnageBoss& pB)
{
    if (this != &pB)
    {
        Personnage::operator=(pB);
        cout << "Erreur 3" << endl;
        origine = pB.origine;
    }
    return *this;
}

string PersonnageBoss::str() const
{
    std::stringstream ss;
    ss << Personnage::str();
        return ss.str();
}

PersonnageBoss* PersonnageBoss::clone()const
{
    return new PersonnageBoss(*this);
}

void PersonnageBoss::categorieBoss() {
    switch(origine) {
    case BLEUE:
        setPtsVie(500);
        setPtsAttaque(5);
        setCoupsCritique(10.0);
        setPtsAttaqueSpeciale(20);
        setBouclier(100);
        setImage("Images/Avatars/Bleue_Boss.png");

        break;

    case ORANGE:
        setImage("Images/Avatars/Orange_Boss.png");
        break;

    case VERTE:
        setImage("Images/Avatars/Verte_Boss.png");
        break;

    case ANNEAU_BLEU:
        setImage("Images/Avatars/Anneau_Bleu_Boss.png");
        break;

    case ANNEAU_ROUGE:
        setImage("Images/Avatars/Anneau_Rouge_Boss.png");
        break;

    case MAUVE_DETRUITE:
        setImage("Images/Avatars/Mauve_Detruite_Boss.png");
        break;
    default:
        break;
    }
}

Origine PersonnageBoss::getOrigine()const
{
    return origine;
}
