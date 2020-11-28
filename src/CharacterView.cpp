#include "CharacterView.h"

CharacterView::CharacterView(/*Personnage* personnage*/)//:personnage(personnage)
{
    //ctor
    sf::IntRect rect(0, 0, 200, 200);
    rectHero = rect;
}

CharacterView::~CharacterView()
{
    //dtor
}

CharacterView::CharacterView(const CharacterView& other)
{
    //copy ctor
    //personnage = other.personnage;
}

CharacterView& CharacterView::operator=(const CharacterView& rhs)
{
    if (this != &rhs){
        hero = rhs.hero;
        boss = rhs.boss;

    }; // handle self assignment
    //assignment operator
    return *this;
}

void CharacterView::drawHero(sf::RenderWindow &window)
{
    if (!character_hero_texture.loadFromFile(hero->getPicture()))
    {
        std::cout << "Problème for loading hero's texture" << std::endl;
    }

    character_hero_sprite.setTexture(character_hero_texture);
    character_hero_sprite.setTextureRect(rectHero);
    window.draw(character_hero_sprite);
}

void CharacterView::drawBoss(sf::RenderWindow &window)
{
    if (!character_boss_texture.loadFromFile(boss->getPicture()))
    {
        std::cout << "Problème for loading Boss's texture" << std::endl;
    }

    character_boss_sprite.setTexture(character_boss_texture);
    character_boss_sprite.setPosition(boss->getX(),boss->getY());
    window.draw(character_boss_sprite);
}

void CharacterView::setCharacterHero(CharacterHero& carH)
{
    this->hero = &carH;
}

CharacterHero& CharacterView::getCharacterHero()const
{
    return *hero;
}

void CharacterView::setCharacterBoss(CharacterBoss& carB)
{
    this->boss = &carB;
}

CharacterBoss& CharacterView::getCharacterBoss()const
{
    return *boss;
}

void CharacterView::course()

{
    if(rectHero.left == 1200){
        rectHero.left = 0;
        cout<< "Animation" << endl;
    }
    else
    {
        rectHero.left += 200;
    }

}
