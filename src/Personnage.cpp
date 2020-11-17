#include "Personnage.h"

#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>


Personnage::Personnage(string nom, string race, int ptsAttaque, int ptsVie, int ptsExperience, int niveau)
{
    this->nom = nom;
    this->race = race;
    this->ptsAttaque = ptsAttaque;
    this->ptsVie = ptsVie;
    this->ptsExperience = ptsExperience;
    this->niveau = niveau;
}

Personnage::~Personnage()
{
    //dtor
}

Personnage::Personnage(const Personnage& other):nom(other.nom),race(other.race), ptsAttaque(other.ptsAttaque), ptsVie(other.ptsVie), ptsExperience(other.ptsExperience), niveau(other.niveau)
{
    //copy ctor
}

Personnage& Personnage::operator=(const Personnage& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

string Personnage::str() const
{
    string result = nom + " " + race + " " + to_string(ptsAttaque) + " " +
    to_string(ptsVie) + " " + to_string(ptsExperience) + " " + to_string(niveau);
    return result;
}
