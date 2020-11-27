#include "BarreBouclierView.h"

BarreBouclierView::BarreBouclierView(sf::Vector2f dimensionCadreBouclier,int bouclierMax)
:dimensionCadreBouclier(dimensionCadreBouclier),bouclierMax(bouclierMax),
bouclierActuelle(bouclierMax),bouclierRestant(0)
{
    //ctor
    cadreBouclier = sf::RectangleShape(dimensionCadreBouclier);
    barreVariableBouclier = sf::RectangleShape(dimensionCadreBouclier);

    cadreBouclier.setOutlineColor(sf::Color::Green);
    cadreBouclier.setFillColor(sf::Color::White);

    barreVariableBouclier.setFillColor(sf::Color::Blue);
}

BarreBouclierView::~BarreBouclierView()
{
    //dtor
}

void BarreBouclierView::setRotation()
{
    cadreBouclier.setRotation(180);
    cadreBouclier.setPosition(3*xBouc,yBouc/4);
    barreVariableBouclier.setRotation(180);
    barreVariableBouclier.setPosition(3*xBouc,yBouc/4);
}

void BarreBouclierView::updateB(int nouveauBouclier)
{
    bouclierActuelle = nouveauBouclier / coefBouclier;
    bouclierRestant = bouclierMax / coefBouclier - bouclierActuelle;

    barreVariableBouclier.setSize(sf::Vector2f(dimensionCadreBouclier.x - (bouclierRestant * dimensionCadreBouclier.x/100.0),dimensionCadreBouclier.y));
}

void BarreBouclierView::drawBouclier(sf::RenderWindow& window)
{


    window.draw(cadreBouclier);
    window.draw(barreVariableBouclier);


}

void BarreBouclierView::setBouclierMax(int bouclierMax)
{
    this->bouclierMax = bouclierMax;
    this->bouclierActuelle = bouclierMax;
    coefBouclier = bouclierMax/100.0;

}

void BarreBouclierView::setPositionBarreBouclier(int x,int y)
{
    this->xBouc = x;
    this->yBouc = y;
    cadreBouclier.setPosition(xBouc,yBouc);
    barreVariableBouclier.setPosition(xBouc,yBouc);
}

