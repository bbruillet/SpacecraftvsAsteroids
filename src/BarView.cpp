#include "BarView.h"
#include <iostream>

//Constructeur
BarView::BarView(sf::Vector2f dimensionFrameLife,int maxLife,sf::Vector2f dimensionFrameShield,int maxShield)
:dimensionFrameLife(dimensionFrameLife),maxLife(maxLife),actualLife(maxLife),remainingLife(0),dimensionFrameShield(dimensionFrameShield),maxShield(maxShield),
actualShield(maxShield),remainingShield(0)
{
    /*-----------VIE-----------------*/
    //cadre de la vie
    frameLife = sf::RectangleShape(dimensionFrameLife);
    frameLife.setOrigin(250, 12.5);
    frameLife.setOutlineColor(sf::Color::Green);
    frameLife.setFillColor(sf::Color(255,141,141));

    //barre qui change en fonction de la vie
    barFrameLife = sf::RectangleShape(dimensionFrameLife);
    barFrameLife.setOrigin(250, 12.5);
    barFrameLife.setFillColor(sf::Color(198,10,10));

    /*-------------Bouclier-----------------------*/

    //cadre du bouclier
    frameShield = sf::RectangleShape(dimensionFrameShield);
    frameShield.setOutlineColor(sf::Color::Green);
    frameShield.setFillColor(sf::Color(121,127,199));
    frameShield.setOrigin(100, 6.25);

    //Barre du bouclier qui varie en fonction des dégats
    barFrameShield = sf::RectangleShape(dimensionFrameShield);
    barFrameShield.setOrigin(100, 6.25);
    barFrameShield.setFillColor(sf::Color::Blue);
    //ctor

}

BarView::~BarView()
{
    //dtor
}

BarView::BarView(const BarView& other)
{
    //copy ctor
}

BarView& BarView::operator=(const BarView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

//Permet de retourner la barre pour le heros pour que la vie découle à l'envers
void BarView::setRotation()
{
    barFrameLife.setRotation(180);
    frameLife.setRotation(180);

    barFrameShield.setRotation(180);
    frameShield.setRotation(180);
}

//envoie la nouvelle vie pour que la barrie de vie varie
void BarView::updateLife(int newlife)
{
    actualLife = newlife / coefSizeLife;
    remainingLife = maxLife / coefSizeLife - actualLife;

    barFrameLife.setSize(sf::Vector2f(dimensionFrameLife.x - (remainingLife * dimensionFrameLife.x/100.0),dimensionFrameLife.y));
}

//dessine la barrie de vie
void BarView::drawLife(sf::RenderWindow& window)
{
    window.draw(frameLife);
    window.draw(barFrameLife);


}

//change la vie maximum
void BarView::setMaxLife(int maxLife)
{
    this->maxLife = maxLife;
    this->actualLife = maxLife;
    coefSizeLife = maxLife/100.0;

}

//change la position de la barre de vie
void BarView::setBarLifePosition(int x,int y)
{
    this->xLife = x;
    this->yLife = y;
    frameLife.setPosition(xLife,yLife);
    barFrameLife.setPosition(xLife,yLife);



}

//fais changer la barre du bouclier avec la nouvelle valeur du bouclier
void BarView::updateShield(int newShield)
{
    actualShield = newShield / coefSizeShield;
    remainingShield = maxShield / coefSizeShield - actualShield;

    barFrameShield.setSize(sf::Vector2f(dimensionFrameShield.x - (remainingShield * dimensionFrameShield.x/100.0),dimensionFrameShield.y));
}

//dessine le bouclier
void BarView::drawShield(sf::RenderWindow& window)
{
    window.draw(frameShield);
    window.draw(barFrameShield);
}

//donne un nouveau bouclier maximum pour paremetrer la barre du bouclier
void BarView::setMaxShield(int maxShield)
{
    this->maxShield = maxShield;
    this->actualShield = maxShield;
    coefSizeShield = maxShield/100.0;

}

//change la position de la barre du bouclier
void BarView::setBarShieldPosition(int x,int y)
{
    this->xShield = x;
    this->yShield = y;
    frameShield.setPosition(xShield,yShield);
    barFrameShield.setPosition(xShield,yShield);
}

