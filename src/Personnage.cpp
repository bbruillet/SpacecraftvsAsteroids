#include "Personnage.h"

#include <cstdio>
#include <iostream>
#include <SFML/Graphics.hpp>

Personnage::Personnage(const string nom, const int ptsAttaque, const int ptsVie, const int ptsExperience, const int niveau,
    const int ptsAttaqueSpeciale, const int bouclier, const double coupsCritique, const double esquive, const int regeneration)
:nom(nom), ptsAttaque(ptsAttaque), ptsExperience(ptsExperience), niveau(niveau), ptsAttaqueSpeciale(ptsAttaqueSpeciale), bouclier(bouclier),
coupsCritique(coupsCritique), esquive(esquive), regeneration(regeneration)
{
    setPtsVie(ptsVie);
    compteurSpe = 0;
}

Personnage::~Personnage()
{
    //dtor
}

Personnage::Personnage(const Personnage& other):nom(other.nom), ptsAttaque(other.ptsAttaque), ptsVie(other.ptsVie), ptsExperience(other.ptsExperience), niveau(other.niveau),
ptsAttaqueSpeciale(other.ptsAttaqueSpeciale), bouclier(other.bouclier), coupsCritique(other.coupsCritique), esquive(other.esquive), regeneration(other.regeneration)
{
    //copy ctor
}

Personnage& Personnage::operator=(const Personnage& p)
{
    if (this != &p)
    {
        nom = p.nom;
        ptsAttaque = p.ptsAttaque;
        ptsVie = p.ptsVie;
        ptsExperience = p.ptsExperience;
        niveau = p.niveau;
        ptsAttaqueSpeciale = p.ptsAttaqueSpeciale;
        bouclier = p.bouclier;
        coupsCritique = p.coupsCritique;
        esquive = p.esquive;
        regeneration = p.regeneration;
    }// handle self assignment
    //assignment operator
    return *this;
}

string Personnage::str() const
{
    std::stringstream ss;
    ss << "Nom : " << nom << "\n\t" <<
        "Points d'attaque : " << to_string(ptsAttaque) << "\n\t" <<
        "Points de vie : " << to_string(ptsVie) << "\n\t" <<
        "Points d'expérience : " << to_string(ptsExperience) << "\n\t" <<
        "Niveau : " << to_string(niveau) << "\n\t" <<
        "Points d'attaque spéciale : " << to_string(ptsAttaqueSpeciale) << "\n\t" <<
        "Bouclier : " << to_string(bouclier) << "\n\t" <<
        "Coups critique : " << to_string(coupsCritique) << "\n\t"
        "Esquive : " << to_string(esquive) << "\n\t" <<
        "Regénération : " << to_string(regeneration);
        return ss.str();
}

void Personnage::setNom(const string &nom)
{
    this->nom = nom;
}

string Personnage::getNom() const
{
    return nom;
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
    this->ptsVie = (ptsVie < 0)? 0 : ptsVie;
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

void Personnage::setPtsAttaqueSpeciale(const int &ptsAttaqueSpeciale)
{
    this->ptsAttaqueSpeciale = ptsAttaqueSpeciale;
}

int Personnage::getPtsAttaqueSpeciale() const
{
    return ptsAttaqueSpeciale;
}

void Personnage::setBouclier(const int &bouclier)
{
    this->bouclier = bouclier;
}

int Personnage::getBouclier() const
{
    return bouclier;
}

void Personnage::setCoupsCritique(const double &coupsCritique)
{
    this->coupsCritique = coupsCritique;
}

double Personnage::getCoupsCritique() const
{
    return coupsCritique;
}

void Personnage::setEsquive(const double &esquive)
{
    this->esquive = esquive;
}

double Personnage::getEsquive() const
{
    return esquive;
}

void Personnage::setCompteurSpe(const int &compteurSpe)
{
    this->compteurSpe = compteurSpe;
}

int Personnage::getCompteurSpe() const
{
    return compteurSpe;
}

void Personnage::setRegeneration(const int &regeneration)
{
    this->regeneration = regeneration;
}

int Personnage::getRegeneration() const
{
    return regeneration;
}
