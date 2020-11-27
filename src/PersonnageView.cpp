#include "PersonnageView.h"

PersonnageView::PersonnageView(/*Personnage* personnage*/)//:personnage(personnage)
{
    //ctor
    sf::IntRect rect(0, 0, 200, 200);
    rectHeros = rect;
}

PersonnageView::~PersonnageView()
{
    //dtor
}

PersonnageView::PersonnageView(const PersonnageView& other)
{
    //copy ctor
    //personnage = other.personnage;
}

PersonnageView& PersonnageView::operator=(const PersonnageView& rhs)
{
    if (this != &rhs){
        heros = rhs.heros;
        boss = rhs.boss;

    }; // handle self assignment
    //assignment operator
    return *this;
}

void PersonnageView::drawHeros(sf::RenderWindow &window)
{
    if (!personnage_heros_texture.loadFromFile(heros->getImage()))
    {
        std::cout << "Problème d'image du héros" << std::endl;
    }

    personnage_heros_sprite.setTexture(personnage_heros_texture);
    personnage_heros_sprite.setTextureRect(rectHeros);
    window.draw(personnage_heros_sprite);
}

void PersonnageView::drawBoss(sf::RenderWindow &window)
{
    if (!personnage_boss_texture.loadFromFile(boss->getImage()))
    {
        std::cout << "Problème d'image du BOSS" << std::endl;
    }

    personnage_boss_sprite.setTexture(personnage_boss_texture);
    personnage_boss_sprite.setPosition(boss->getX(),boss->getY());
    window.draw(personnage_boss_sprite);
}

void PersonnageView::setPersonnageHeros(PersonnageHeros& per)
{
    this->heros = &per;
}

PersonnageHeros& PersonnageView::getPersonnageHeros()const
{
    return *heros;
}

void PersonnageView::setPersonnageBoss(PersonnageBoss& per)
{
    this->boss = &per;
}

PersonnageBoss& PersonnageView::getPersonnageBoss()const
{
    return *boss;
}

void PersonnageView::course()

{
    if(rectHeros.left == 1200){
        rectHeros.left = 0;
        cout<< "ts" << endl;
    }
    else
    {
        rectHeros.left += 200;
    }

}
