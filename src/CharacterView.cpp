#include "CharacterView.h"

/*
    This is the constructor.
    InRect's members are initialized here.
    How does it work ? --> rect(where you want to start -> x,
                                where you want to start -> y,
                                width of a sample,
                                height of a sample)
*/
CharacterView::CharacterView()
{
    sf::IntRect rect(0, 0, 350, 350);
    rectHero = rect;
    sf::IntRect rect2(0, 0, 500, 420);
    rectBoss = rect2;
    rectAttackBoss = rect2;
    sf::IntRect rect3(0, 0, 400, 400);
    rectRegen = rect3;
    sf::IntRect rect4(0, 0, 600, 600);
    rectBadge = rect4;
}

/*
    This is the destructor
*/
CharacterView::~CharacterView()
{
    delete(hero);
    delete(boss);
}

/*
    This is the copy constructor
*/
CharacterView::CharacterView(const CharacterView& other)
{

}

/*
    This is operator='s function
*/
CharacterView& CharacterView::operator=(const CharacterView& rhs)
{
    if (this != &rhs){
        hero = rhs.hero;
        boss = rhs.boss;

    }; // handle self assignment
    //assignment operator
    return *this;
}

/*
    This is where we load a texture (of the hero).
    The texture is added to a sprite and the rect to.
    After that, the sprite is draw in the window
*/
void CharacterView::drawHero(sf::RenderWindow &window)
{
    if (!character_hero_texture.loadFromFile(hero->getPicture()))
    {
        std::cout << "Problem while loading the picture of the hero" << std::endl;
    }

    character_hero_sprite.setTexture(character_hero_texture);
    character_hero_sprite.setTextureRect(rectHero);
    window.draw(character_hero_sprite);
}

/*
    This is where we load a texture (of the boss).
    The texture is added to a sprite and the rect to.
    The sprite is placed in the window
    After that, the sprite is draw in the window
*/
void CharacterView::drawBoss(sf::RenderWindow &window)
{
    if (!character_boss_texture.loadFromFile(boss->getPicture()))
    {
        std::cout << "Problem while loading the picture of the boss" << std::endl;
    }

    character_boss_sprite.setTexture(character_boss_texture);
    character_boss_sprite.setTextureRect(rectBoss);
    character_boss_sprite.setPosition(boss->getX(),boss->getY());
    window.draw(character_boss_sprite);
}

/*
    This is where we load a texture (of the attacking boss).
    The texture is added to a sprite and the rect to.
    After that, the sprite is draw in the window
*/
void CharacterView::drawBoss2(sf::RenderWindow &window)
{
    if (!attack_boss_texture.loadFromFile(boss->getPicture()))
    {
        std::cout << "Problem while loading animated boss picture" << std::endl;
    }

    attack_boss_sprite.setTexture(attack_boss_texture);
    attack_boss_sprite.setTextureRect(rectAttackBoss);
    window.draw(attack_boss_sprite);
}

/*
    This is where we load a texture (of regen circles).
    The texture is added to a sprite and the rect to.
    After that, the sprite is draw in the window
*/
void CharacterView::drawRegenCircles(sf::RenderWindow &window)
{
    if (!regen_texture.loadFromFile("Images/Avatars/Regen.png"))
    {
        std::cout << "Problem while loading regen circles" << std::endl;
    }

    regen_sprite.setTexture(regen_texture);
    regen_sprite.setTextureRect(rectRegen);
    window.draw(regen_sprite);
}

/*
    This is where we load a texture (of badges box).
    The texture is added to a sprite and the rect to.
    The sprite is placed in the window
    After that, the sprite is draw in the window
    the first instruction says that there is a new simple every 600 puxels on the left
*/
void CharacterView::drawBadges(sf::RenderWindow& window, int x, int y)
{

    rectBadge.left = hero->getBadge()*600;

    if (!badge_texture.loadFromFile("Images/Avatars/badges.png"))
    {
        std::cout << "Problem while loading badges" << std::endl;
    }

    badge_sprite.setTexture(badge_texture);
    badge_sprite.setTextureRect(rectBadge);
    badge_sprite.setPosition(x,y);
    window.draw(badge_sprite);
}

/*This is the setter of the hero*/
void CharacterView::setCharacterHero(CharacterHero& carH)
{
    this->hero = &carH;
}

/*This is the getter of the hero*/
CharacterHero& CharacterView::getCharacterHero()const
{
    return *hero;
}

/*This is the setter of the hero*/
void CharacterView::setCharacterBoss(CharacterBoss& carB)
{
    this->boss = &carB;
}

/*This is the getter of the hero*/
CharacterBoss& CharacterView::getCharacterBoss()const
{
    return *boss;
}

/*
    This function is used to animate the hero while going to the boss
    A sample is 350x350 pixels long in the sprite sheet.
*/
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

/*
    This function is used to animate the hero while going back to his place
    A sample is 350x350 pixels long in the sprite sheet.
*/
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

/*
    This function is used to animate the hero while fighting the boss
    A sample is 350x350 pixels long in the sprite sheet.
*/
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

/*
    This function is used to animate the hero while going back to his place
    A sample is 400x400 pixels long in the sprite sheet.
*/
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

/*
    This function is used to animate the hero while preparing the attack to the hero
    A sample is 350x350 pixels long in the sprite sheet.
*/
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

/*
    This function is used to animate the hero while throwing the ball to the hero
    A sample is 500x420 pixels long in the sprite sheet.
*/
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
