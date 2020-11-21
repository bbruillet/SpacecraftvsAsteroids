#include "Planete.h"
#include "BiomePlanete.h"
#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>

Planete::Planete(string nom, string image, int x, int y)
{
    this->nom = nom;
    this->image = image;
    this->x=x;
    this->y=y;
    if (!planete_texture.loadFromFile(image))
    {
        std::cout << "Problème de planète" << std::endl;
    }

    planete_sprite.setTexture(planete_texture);
    planete_sprite.setPosition(x, y);
    //planete_sprite.setOrigin(500, 500);
}

Planete::Planete(const Planete& plan)
{
    nom = plan.nom;
    image = plan.image;
    x = plan.x;
    y = plan.y;

    if (!planete_texture.loadFromFile(image))
    {
        std::cout << "Problème de planète" << std::endl;
    }

    planete_sprite.setTexture(planete_texture);
    planete_sprite.setPosition(x, y);
}


Planete::Planete()
{

}

Planete::~Planete()
{
    //dtor
}

bool Planete::operator==(const Planete& plan)
{
    return (nom==plan.nom);
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

//void Planete::ajouter(PersonnageBoss boss)
//{
//      this->bosses.push_back(boss);
//}
