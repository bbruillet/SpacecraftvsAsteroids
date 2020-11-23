#include "Univers.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

Univers::Univers()
{
    cout << "constru univers" << endl;
    //Sf::Image image;
    //image.loadFromMemory("Images/Backgrounds/Universe.png")
    if (!univers_texture.loadFromFile("Images/Backgrounds/Universe.png"))
    {
        std::cout << "Problème" << std::endl;
    }

    int x = 0;
    int y = 0;
    univers_sprite.setTexture(univers_texture);
    univers_sprite.setOrigin(1000,1000);
    univers_sprite.setPosition(x, y);
    univers_sprite.scale(3.0f, 3.0f);
   // univers_sprite.setTextureRect(sf::IntRect(13000, 13000, 13000, 13000));//ctor
}

Univers::Univers(const Univers& univ)
{
    cout << "cpy univers" << endl;
    for(size_t i(0);i<univ.planetes.size();i++)
    {
        planetes.push_back(univ.planetes[i]->clone()); //AIP
    }

    for(size_t i(0);i<univ.planetesInaccessibles.size();i++)
    {
        planetesInaccessibles.push_back(univ.planetesInaccessibles[i]); //AIP
    }
    //copy ctor
}

Univers::~Univers()
{
    //dtor
     for(size_t i(0);i<planetes.size();i++)
    {
        delete planetes[i]; //AIP
    }
    planetes.clear();
    for(size_t i(0);i<planetesInaccessibles.size();i++)
    {
        delete planetesInaccessibles[i]; //AIP
    }
    planetesInaccessibles.clear();
}

int Univers::getX() const
{
    return x;
}

void Univers::setX(int x)
{
    this->x = x;
}

int Univers::getY() const
{
    return y;
}

void Univers::setY(int y)
{
    this->y = y;
}

void Univers::add(const Planete* pla)
{
      planetes.push_back(pla->clone());
}

void Univers::addInacc(const Planete* pla)
{
    planetesInaccessibles.push_back(pla->clone());
}
