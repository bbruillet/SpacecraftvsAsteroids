#include "CharacterBoss.h"
#include "Planet.h"
#include "Character.h"


CharacterBoss::CharacterBoss(const string name, const int ptsAttack, const int ptsLife, const int ptsExperience, const int level,
    const int ptsSpecialAttack, const int shield, const double criticalHit, const double dodge, const int x, const int y, const string picture, const int regeneration, const Origin origin)
:Character(name,ptsAttack,ptsLife,ptsExperience,level,ptsSpecialAttack,shield,criticalHit,dodge, x, y, picture, regeneration), origin(origin)
{
   // Planete plan;
   categoryBoss();

    //ctor
}

CharacterBoss::CharacterBoss(const string name, const Origin origin)
:Character(name),origin(origin)
{
    categoryBoss();
}


CharacterBoss::~CharacterBoss()
{
    //dtor

}

CharacterBoss::CharacterBoss(const CharacterBoss& cB):Character(cB), origin(cB.origin)
{
    categoryBoss();
}

CharacterBoss& CharacterBoss::operator=(const CharacterBoss& cB)
{
    if (this != &cB)
    {
        Character::operator=(cB);
        origin = cB.origin;
    }
    return *this;
}

string CharacterBoss::str() const
{
    std::stringstream ss;
    ss << Character::str();
        return ss.str();
}

CharacterBoss* CharacterBoss::clone()const
{
    return new CharacterBoss(*this);
}

void CharacterBoss::categoryBoss() {
    switch(origin) {
    case BLUE:
        setPtsLife(550);
        setPtsAttack(10);
        setCriticalHit(15.0);
        setPtsSpecialAttack(20);
        setShield(50);
        setX(1545);
        setY(525);
        setPicture("Images/Avatars/Bleue_Boss.png");
        break;

    case ORANGE:
        setPtsLife(200);
        setPtsAttack(10);
        setCriticalHit(15.0);
        setPtsSpecialAttack(20);
        setShield(400);
        setX(1550);
        setY(520);
        setPicture("Images/Avatars/Orange_Boss.png");
        break;

    case GREEN:
        setPtsLife(150);
        setPtsAttack(20);
        setCriticalHit(15.0);
        setPtsSpecialAttack(30);
        setShield(50);
        setX(1500);
        setY(600);
        setPicture("Images/Avatars/Verte_Boss.png");
        break;

    case RING_BLUE:
        setPtsLife(250);
        setPtsAttack(5);
        setCriticalHit(50.0);
        setPtsSpecialAttack(20);
        setShield(150);
        setX(1110);
        setY(575);
        setPicture("Images/Avatars/Anneau_Bleu_Boss.png");
        break;

    case RING_RED:
        setPtsLife(500);
        setPtsAttack(5);
        setCriticalHit(15.0);
        setPtsSpecialAttack(20);
        setShield(100);
        setX(1630);
        setY(400);
        setPicture("Images/Avatars/Anneau_Rouge_Boss.png");
        break;

    case PURPLE_DESTROYED:
        setPtsLife(500);
        setPtsAttack(5);
        setCriticalHit(15.0);
        setPtsSpecialAttack(20);
        setShield(100);
        setX(1340);
        setY(600);
        setPicture("Images/Avatars/Mauve_Detruite_Boss.png");
        break;
    default:
        break;
    }
}

Origin CharacterBoss::getOrigin()const
{
    return origin;
}
