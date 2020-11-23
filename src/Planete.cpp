#include "Planete.h"
#include "BiomePlanete.h"
#include "PersonnageBoss.h"
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>


Planete::Planete(string nom, string image, int x, int y, const int xPerso, const int yPerso):nom(nom), image(image), x(x), y(y), xPerso(xPerso), yPerso(yPerso)
{
//    this->bossPlan = bossPlan;
    cout << "constru planete" << endl;
    PersonnageBoss *p1 = new PersonnageBoss("",BLEUE);
    this->bossPlan = p1;
    //planete_sprite.setOrigin(500, 500);
}

Planete::Planete(const Planete& plan)
{
    nom = plan.nom;
    image = plan.image;
    x = plan.x;
    y = plan.y;
    yPerso = plan.yPerso;
    xPerso = plan.yPerso;
    biom = plan.biom;
    bossPlan = plan.bossPlan;
   // cout <<"2 " +bossPlan->str()<< endl;

    if (!planete_texture.loadFromFile(image))
    {
        std::cout << "Problème de planète" << std::endl;
    }

    planete_sprite.setTexture(planete_texture);
    planete_sprite.setPosition(x, y);

}

Planete::~Planete()
{
    //dtor
}

bool Planete::operator==(const Planete& plan)
{
    return (nom==plan.nom);
}

Planete& Planete::operator=(const Planete& plan)
{
    if (this != &plan)
    {
        nom = plan.nom;
        image = plan.image;
        x = plan.x;
        y = plan.y;
        biom = plan.biom;
        bossPlan = plan.bossPlan;

    }
    return *this;
}

int Planete::getX() const
{
    return x;
}

void Planete::setX(int x)
{
    this->x = x;
}

int Planete::getY() const
{
    return y;
}

void Planete::setY(int y)
{
    this->y = y;
}

void Planete::setNom(const string &nom)
{
    this->nom = nom;
}

string Planete::getNom() const
{
    return nom;
}

void Planete::DonnerBiome(BiomePlanete &biom)
{

    this->biom = &biom;
}

BiomePlanete* Planete::getBiome()const
{
    return biom;
}

PersonnageBoss* Planete::getBoss()const
{
    return bossPlan;
}

void Planete::DonnerBoss(PersonnageBoss &boss)
{
    PersonnageBoss* b1 = new PersonnageBoss(boss);
    this->bossPlan = b1;
}

int Planete::getXPerso() const
{
    return xPerso;
}

void Planete::setXPerso(int xPerso)
{
    this->xPerso = xPerso;
}

int Planete::getYPerso() const
{
    return yPerso;
}

void Planete::setYPerso(int yPerso)
{
    this->yPerso = yPerso;
}

Planete* Planete::clone() const
{
    return new Planete(*this);
}
