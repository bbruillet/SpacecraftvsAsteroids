#include "BarreView.h"
#include <iostream>

//Constructeur
BarreView::BarreView(sf::Vector2f dimensionCadre,int vieMax,sf::Vector2f dimensionCadreBouclier,int bouclierMax)
:dimensionCadre(dimensionCadre),vieMax(vieMax),vieActuelle(vieMax),vieRestante(0),dimensionCadreBouclier(dimensionCadreBouclier),bouclierMax(bouclierMax),
bouclierActuelle(bouclierMax),bouclierRestant(0)
{
    /*-----------VIE-----------------*/
    //cadre de la vie
    cadreVie = sf::RectangleShape(dimensionCadre);
    cadreVie.setOrigin(250, 12.5);
    cadreVie.setOutlineColor(sf::Color::Green);
    cadreVie.setFillColor(sf::Color::White);

    //barre qui change en fonction de la vie
    barreVariableVie = sf::RectangleShape(dimensionCadre);
    barreVariableVie.setOrigin(250, 12.5);
    barreVariableVie.setFillColor(sf::Color::Red);

    /*-------------Bouclier-----------------------*/

    //cadre du bouclier
    cadreBouclier = sf::RectangleShape(dimensionCadreBouclier);
    cadreBouclier.setOutlineColor(sf::Color::Green);
    cadreBouclier.setFillColor(sf::Color::White);
    cadreBouclier.setOrigin(100, 6.25);

    //Barre du bouclier qui varie en fonction
    barreVariableBouclier = sf::RectangleShape(dimensionCadreBouclier);
    barreVariableBouclier.setOrigin(100, 6.25);
    barreVariableBouclier.setFillColor(sf::Color::Blue);
    //ctor

}

BarreView::~BarreView()
{
    //dtor
}

BarreView::BarreView(const BarreView& other)
{
    //copy ctor
}

BarreView& BarreView::operator=(const BarreView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

//Permet de retourner la barre pour le heros pour que la vie découle à l'envers
void BarreView::setRotation()
{
    barreVariableVie.setRotation(180);
    cadreVie.setRotation(180);

    barreVariableBouclier.setRotation(180);
    cadreBouclier.setRotation(180);

}

//envoie la nouvelle vie pour que la barrie de vie varie
void BarreView::updateV(int nouvelleVie)
{
    vieActuelle = nouvelleVie / coefTaille;
    vieRestante = vieMax / coefTaille - vieActuelle;

    barreVariableVie.setSize(sf::Vector2f(dimensionCadre.x - (vieRestante * dimensionCadre.x/100.0),dimensionCadre.y));
}

//dessine la barrie de vie
void BarreView::drawVie(sf::RenderWindow& window)
{
    window.draw(cadreVie);
    window.draw(barreVariableVie);


}

//change la vie maximum
void BarreView::setVieMax(int vieMax)
{
    this->vieMax = vieMax;
    this->vieActuelle = vieMax;
    coefTaille = vieMax/100.0;

}

//change la position de la barre de vie
void BarreView::setPositionBarre(int x,int y)
{
    this->xVie = x;
    this->yVie = y;
    cadreVie.setPosition(xVie,yVie);
    barreVariableVie.setPosition(xVie,yVie);

}

//fais changer la barre du bouclier avec la nouvelle valeur du bouclier
void BarreView::updateB(int nouveauBouclier)
{
    bouclierActuelle = nouveauBouclier / coefBouclier;
    bouclierRestant = bouclierMax / coefBouclier - bouclierActuelle;

    barreVariableBouclier.setSize(sf::Vector2f(dimensionCadreBouclier.x - (bouclierRestant * dimensionCadreBouclier.x/100.0),dimensionCadreBouclier.y));
}

//dessine le bouclier
void BarreView::drawBouclier(sf::RenderWindow& window)
{
    window.draw(cadreBouclier);
    window.draw(barreVariableBouclier);
}

//donne un nouveau bouclier maximum pour paremetrer la barre du bouclier
void BarreView::setBouclierMax(int bouclierMax)
{
    this->bouclierMax = bouclierMax;
    this->bouclierActuelle = bouclierMax;
    coefBouclier = bouclierMax/100.0;

}

//change la position de la barre du bouclier
void BarreView::setPositionBarreBouclier(int x,int y)
{
    this->xBouc = x;
    this->yBouc = y;
    cadreBouclier.setPosition(xBouc,yBouc);
    barreVariableBouclier.setPosition(xBouc,yBouc);
}

