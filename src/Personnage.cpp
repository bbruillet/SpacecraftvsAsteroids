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

void Personnage::setNom(const string &nom)
{
    this->nom = nom;
}

string Personnage::getNom() const
{
    return nom;
}

void Personnage::setRace(const string &race)
{
    this->race = race;
}

string Personnage::getRace() const
{
    return race;
}

void Personnage::setPtsAttaque(const int &ptsAttaque)
{
    this->ptsAttaque = ptsAttaque;
}

int Personnage::getPtsAttaque() const
{
    return ptsAttaque;
}

void Personnage::setPtsVie(const int &ptsVie)
{
    this->ptsVie = ptsVie;
}

int Personnage::getPtsVie() const
{
    return ptsVie;
}

void Personnage::setPtsExperience(const int &ptsExperience)
{
    this->ptsExperience = ptsExperience;
}

int Personnage::getPtsExperience() const
{
    return ptsExperience;
}

void Personnage::setNiveau(const int &niveau)
{
    this->niveau = niveau;
}

int Personnage::getNiveau() const
{
    return niveau;
}
