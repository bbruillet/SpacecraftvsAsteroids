#include "BarView.h"
#include <iostream>

/*
    This is the constructor
    remaininglife and remainingshield are setted at '0', because they'll be used for making operations
*/
BarView::BarView(sf::Vector2f dimensionFrameLife, int maxLife, sf::Vector2f dimensionFrameShield, int maxShield)
:dimensionFrameLife(dimensionFrameLife),maxLife(maxLife),actualLife(maxLife),remainingLife(0),dimensionFrameShield(dimensionFrameShield),maxShield(maxShield),
actualShield(maxShield),remainingShield(0)
{
    /*Here, we are making life's frame properties*/
    frameLife = sf::RectangleShape(dimensionFrameLife);
    frameLife.setOrigin(250, 12.5);
    frameLife.setOutlineColor(sf::Color::White);
    frameLife.setFillColor(sf::Color(255,141,141));

    /*Here, we are making remaining life's frame properties*/
    barFrameLife = sf::RectangleShape(dimensionFrameLife);
    barFrameLife.setOrigin(250, 12.5);
    barFrameLife.setFillColor(sf::Color(198,10,10));

    /*Here, we are making shield's frame properties*/
    frameShield = sf::RectangleShape(dimensionFrameShield);
    frameShield.setOutlineColor(sf::Color::White);
    frameShield.setFillColor(sf::Color(121,127,199));
    frameShield.setOrigin(100, 6.25);

    /*Here, we are making remaining shield's frame properties*/
    barFrameShield = sf::RectangleShape(dimensionFrameShield);
    barFrameShield.setOrigin(100, 6.25);
    barFrameShield.setFillColor(sf::Color::Blue);

}

/*
    This is the destructor
*/
BarView::~BarView()
{

}

/*
    This is the copy constructor
*/
BarView::BarView(const BarView& other)
{

}

/*
    This is operator='s function
*/
BarView& BarView::operator=(const BarView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/*
    Heroes frames are upsided down in this function.
    We have defined an origin int the constructor
*/
void BarView::setRotation()
{
    barFrameLife.setRotation(180);
    frameLife.setRotation(180);

    barFrameShield.setRotation(180);
    frameShield.setRotation(180);
}

/*
    This function will set your maxLife and actualLife. It'll also set your coefficiant by diving your maxLife by 100 (.0 because it's a double type)
*/
void BarView::setMaxLife(int maxLife)
{
    this->maxLife = maxLife;
    this->actualLife = maxLife;
    coefSizeLife = maxLife/100.0;
}

/*
    This function'll send an update of your life's frame for updating this frame.
*/
void BarView::updateLife(int newLife)
{
    /*This operation'll create an actualLife by dividing the newLife (placed in argument) by the coefficient of your life (see setMaxLife's function)*/
    actualLife = newLife / coefSizeLife;

    /*This one will set your remainingLife by dividing your maxLife by your coefficient and after that by subtracting this by your actualLife*/
    remainingLife = maxLife / coefSizeLife - actualLife;

    /*The frame of your remaining life will be resized here*/
    barFrameLife.setSize(sf::Vector2f(dimensionFrameLife.x - (remainingLife * dimensionFrameLife.x/100.0),dimensionFrameLife.y));
}

/*
    This function will draw the two frames of your life
*/
void BarView::drawLife(sf::RenderWindow& window)
{
    window.draw(frameLife);
    window.draw(barFrameLife);
}

/*
    This function'll put the 2 frames in the window
*/
void BarView::setBarLifePosition(int x,int y)
{
    this->xLife = x;
    this->yLife = y;
    frameLife.setPosition(xLife,yLife);
    barFrameLife.setPosition(xLife,yLife);
}


/*
    This function will set your maxShield and actualShield. It'll also set your coefficiant by diving your maxShield by 100 (.0 because it's a double type)
*/
void BarView::setMaxShield(int maxShield)
{
    this->maxShield = maxShield;
    this->actualShield = maxShield;
    coefSizeShield = maxShield/100.0;

}

/*
    This function'll send an update of your shield's frame for updating this frame.
*/
void BarView::updateShield(int newShield)
{
    /*This operation'll create an actualShield by dividing the newShield (placed in argument) by the coefficient of your shield (see setMaxShield's function)*/
    actualShield = newShield / coefSizeShield;

    /*This one will set your remainingShield by dividing your maxShield by your coefficient and after that by subtracting this by your actualShield*/
    remainingShield = maxShield / coefSizeShield - actualShield;

    /*The frame of your remaining shield will be resized here*/
    barFrameShield.setSize(sf::Vector2f(dimensionFrameShield.x - (remainingShield * dimensionFrameShield.x/100.0),dimensionFrameShield.y));
}

/*
    This function will draw the two frames of your shield
*/
void BarView::drawShield(sf::RenderWindow& window)
{
    window.draw(frameShield);
    window.draw(barFrameShield);
}

/*
    This function'll put the 2 frames in the window
*/
void BarView::setBarShieldPosition(int x,int y)
{
    this->xShield = x;
    this->yShield = y;
    frameShield.setPosition(xShield,yShield);
    barFrameShield.setPosition(xShield,yShield);
}

