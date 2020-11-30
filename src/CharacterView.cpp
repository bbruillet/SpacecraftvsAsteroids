#include "CharacterView.h"

CharacterView::CharacterView(/*Personnage* personnage*/)//:personnage(personnage)
{
    //ctor
    sf::IntRect rect(0, 0, 350, 350);
    rectHero = rect;
    sf::IntRect rect2(0, 0, 500, 420);
    rectBoss = rect2;
    rectAttackBoss = rect2;
    sf::IntRect rect3(0, 0, 400, 400);
    rectRegen = rect3;
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
    character_boss_sprite.setTextureRect(rectBoss);
    character_boss_sprite.setPosition(boss->getX(),boss->getY());
    window.draw(character_boss_sprite);
}

void CharacterView::drawBoss2(sf::RenderWindow &window)
{
    if (!attack_boss_texture.loadFromFile(boss->getPicture()))
    {
        std::cout << "Problème for loading Boss's texture" << std::endl;
    }

    attack_boss_sprite.setTexture(attack_boss_texture);
    attack_boss_sprite.setTextureRect(rectAttackBoss);
    //attack_boss_sprite.setPosition(boss->getX(),boss->getY());
    window.draw(attack_boss_sprite);
}

void CharacterView::drawRegenCircles(sf::RenderWindow &window)
{
    if (!regen_texture.loadFromFile("Images/Avatars/Regen.png"))
    {
        std::cout << "Problème for loading Boss's texture" << std::endl;
    }

    regen_sprite.setTexture(regen_texture);
    regen_sprite.setTextureRect(rectRegen);
    window.draw(regen_sprite);
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

//350/350
void CharacterView::forwardHero()
{
    if(rectHero.left > 1050 || rectHero.left < 0)
    {
       rectHero.left = 0;
    }
    else
    {
        if(rectHero.left == 1050)
        {
            rectHero.left = 0;
        }
        else
        {
            rectHero.left += 350;
        }
    }

}

void CharacterView::backwardHero()
{
    if(rectHero.left > 2450 || rectHero.left < 2100)
    {
       rectHero.left = 2100;

    }
    else
    {
        if(rectHero.left == 2450)
        {
            rectHero.left = 2100;
        }
        else
        {
            rectHero.left += 350;
        }
    }
}

void CharacterView::fightHero()
{
    if(rectHero.left > 1750 || rectHero.left < 1400)
    {
       rectHero.left = 1400;
    }
    else
    {
        if(rectHero.left == 1750)
        {
            rectHero.left = 1400;
        }
        else
        {
            rectHero.left += 350;
        }
    }
}

void CharacterView::regenCircles()
{

    if(rectRegen.left == 2400)
    {
        rectRegen.left = 0;
    }
    else
    {
        rectRegen.left += 400;
    }
}

void CharacterView::throwingBoss()
{
    if(rectAttackBoss.left > 3500 || rectAttackBoss.left < 2000)
    {
       rectAttackBoss.left = 2000;

    }
    else
    {
        if(rectAttackBoss.left == 3500)
        {
            rectAttackBoss.left = 2000;
        }
        else
        {
            rectAttackBoss.left += 500;
        }
    }
}

void CharacterView::fightBoss()
{
    if(rectBoss.left > 1500 || rectBoss.left < 1000)
    {
       rectBoss.left = 1000;
    }
    else
    {
        if(rectBoss.left == 1500)
        {
            rectBoss.left = 1000;
        }
        else
        {
            rectBoss.left += 500;
        }
    }
}
