#include "Fight.h"
#include <stdlib.h>

#include <time.h>

#include "Character.h"
//#include "CharacterHero.h"

Fight::Fight()
{
    srand((int)time(0));
    nbRegen = 2;
}

Fight::~Fight()
{
    //dtor
}

Fight::Fight(const Fight& other)
{
    //copy ctor
}

Fight& Fight::operator=(const Fight& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}


//Heros attaque Boss
void Fight::attackBoss(Character &c1,Character &c2)
{

                    int attack;
                    if(c1.getCounterSpe() == 3)
                    {
                        attack = c1.getPtsSpecialAttack();
                        c1.setCounterSpe(-1);
                    }

                    else
                    {
                        attack = c1.getPtsAttack();

                            nb = (rand()% 100) +1;

                            if (nb <= c1.getCriticalHit())
                            {
                                attack = attack + (c1.getPtsAttack()/2);
                                cout << attack << endl;
                            }
                    }

                    nbDodge = (rand()%100) + 1;
                    if(nbDodge <= c2.getDodge())
                    {
                        attack = 0;
                    }

                    if(c2.getShield() > 0) {
                            if(c2.getShield() > attack){
                                c2.setShield(c2.getShield() - attack);
                            }
                            else if(c2.getShield() == attack)
                                {
                                    c2.setShield(0);
                                }
                                else
                                {
                                    attack = attack - c2.getShield();
                                    c2.setShield(0);
                                    c2.setPtsLife(c2.getPtsLife()-attack);
                                }
                    }
                    else
                    {
                        c2.setPtsLife(c2.getPtsLife()-attack);
                    }

                    c1.setCounterSpe(c1.getCounterSpe() + 1);




        }

void Fight::regenHero(Character &c1)
{
    if(nbRegen == 0)
                {
                    cout << "VOUS DEVEZ ATTAQUER !" << endl;
                }

                else
                {
                    cout << "REGEN de "+c1.getName() << endl;
                    c1.setPtsLife(c1.getPtsLife() + c1.getRegeneration());
                    nbRegen--;
                    return;

                }
}

//Boss attaque Heros
void Fight::attackHero(Character &c1, Character &c2)
{
    int attack;
    if(c1.getCounterSpe() == 3)
    {
        attack = c1.getPtsSpecialAttack();
        c1.setCounterSpe(-1);
        cout << "Coup spécial de " << c1.getName() << endl;
    }

    else
    {
        cout << "Coup physique de " << c1.getName() << endl;
        attack = c1.getPtsAttack();


            nb = (rand()% 100) +1;


            cout << "\n-------------\n" << to_string(nb) << "\n-------------\n" << endl;
            if (nb <= c1.getCriticalHit())
            {
                cout << "Attaque critique !" << endl;
                attack = attack + (c1.getPtsAttack()/2);
                cout << attack << endl;
            }
    }

    nbDodge = (rand()%100) + 1;
//    nbEsquive = (rand()%100) + 1;
    if(nbDodge <= c2.getDodge())
    {
        cout << "Esquive de " << c2.getName() << endl;
        attack = 0;
    }

                       if(c2.getShield() > 0) {
                            if(c2.getShield() > attack){
                                c2.setShield(c2.getShield() - attack);
                            }
                            else if(c2.getShield() == attack)
                            {
                                c2.setShield(0);
                            }
                            else
                            {
                                attack = attack - c2.getShield();
                                c2.setShield(0);
                                c2.setPtsLife(c2.getPtsLife()-attack);
                            }
                        }
                        else
                        {
                            c2.setPtsLife(c2.getPtsLife()-attack);
                        }
    c1.setCounterSpe(c1.getCounterSpe() + 1);
}

void Fight::fightBoss(Character &c1, Character &c2)
{
    attackBoss(c1,c2);
        if(c2.getPtsLife() > 0)
        {
            attackHero(c2,c1);
            if(c1.getPtsLife() == 0){
                cout << "mort de p1" << endl;
            }
        }

}

void Fight::regenFight(Character &c1, Character &c2)
{
    regenHero(c1);

    attackHero(c2,c1);
    if(c1.getPtsLife() == 0){
        cout << "mort de p1" << endl;
    }

}

void Fight::setHealth(const int &health)
{
    this->health = health;
}

int Fight::getHealth() const
{
    return health;
}
