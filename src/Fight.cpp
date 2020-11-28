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
void Fight::attackBoss(Character &c1,Character &c2, sf::RenderWindow &windowJeu)
{


    while(windowJeu.isOpen())
    {
        sf::Event event;
        while (windowJeu.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::A:
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
                    return;
                    break;
                case sf::Keyboard::R:
                    if(nbRegen == 0)
                    {
                        cout << "VOUS DEVEZ ATTAQUER !" << endl;
                    }

//                    if(getHealth() <= c1.getPtsLife()+c1.getRegeneration())
//                    {
//                        cout << "VOUS DEVEZ ATTAQUER !" << endl;
//                    }
                    else
                    {
                        cout << "REGEN de "+c1.getName() << endl;
                        c1.setPtsLife(c1.getPtsLife() + c1.getRegeneration());
                        nbRegen--;
                        return;

                    }

                    break;
                default:
                    break;
                }
                break;
                default:
                    break;
            }
        }
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
    cout << c1.str() << endl << endl;
    cout << c2.str() << endl;
}

void Fight::fightBoss(Character &c1, Character &c2, sf::RenderWindow &windowJeu)
{
    int round = 0;
//    health = c1.getPtsLife();
//    setHealth(health);
//    int test = 0;
        round ++;
        cout << "Round numéro "+to_string(round) << endl;


            nbFirst = (rand()% 2) +1;


            if(nbFirst == 1){
                attackBoss(c1,c2,windowJeu);
                if(c2.getPtsLife() > 0)
                {
                    attackHero(c2,c1);
                    if(c1.getPtsLife() == 0){
                        cout << "mort de p1" << endl;
                    }
                }
            }
            if (nbFirst ==2)
            {
                attackHero(c2,c1);
                if(c1.getPtsLife() > 0)
                {
                    attackBoss(c1,c2,windowJeu);

                    if(c2.getPtsLife() == 0){
                        cout << "mort de p2";
                    }
                }
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
