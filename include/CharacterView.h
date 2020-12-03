#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H
#include "CharacterHero.h"
#include "CharacterBoss.h"
#include <SFML/Graphics.hpp>

/*
    This clas sis used to draw all characters sprite and preparing animation for the fight
*/
class CharacterView
{
    private:
        /*
            These 2 members data are pointeurs of two different characters : hero and boss
        */
        CharacterHero* hero;
        CharacterBoss* boss;

    public:
        /*
            The 4 next lines are :
                - constructor
                - destructor
                - copy contructor
                - operator=
        */
        CharacterView();
        virtual ~CharacterView();
        CharacterView(const CharacterView& other);
        CharacterView& operator=(const CharacterView& other);

        /*
            This is the sprite & the texture of a hero.
            IntRect is used for using a sprite sheet
        */
        sf::Sprite character_hero_sprite;
        sf::Texture character_hero_texture;
        sf::IntRect rectHero;

        /*
            This is the sprite & the texture of a boss.
            IntRect is used for using a sprite sheet
        */
        sf::Sprite character_boss_sprite;
        sf::Texture character_boss_texture;
        sf::IntRect rectBoss;

        /*
            This is the sprite & the texture of a boss used to attack a hero.
            Intrect is used for using a sprite sheet
        */
        sf::Sprite attack_boss_sprite;
        sf::Texture attack_boss_texture;
        sf::IntRect rectAttackBoss;

        /*
            This is the sprite & the texture of the regeneration used by the hero.
            Intrect is used for using a sprite sheet
        */
        sf::Sprite regen_sprite;
        sf::Texture regen_texture;
        sf::IntRect rectRegen;

        /*
            This is the sprite & the texture of badges's box.
            Intrect is used for using a sprite sheet
        */
        sf::Sprite badge_sprite;
        sf::Texture badge_texture;
        sf::IntRect rectBadge;

                /*This function is used to draw a sprite of a hero*/
        void drawHero(sf::RenderWindow &window);

        /*This function is used to draw a sprite of a boss*/
        void drawBoss(sf::RenderWindow &window);

        /*This function is used to draw a sprite of a boss during the attack*/
        void drawBoss2(sf::RenderWindow &window);

        /*This function is used to draw a sprite of regeneration used by the hero*/
        void drawRegenCircles(sf::RenderWindow &window);

        /*This function is used to draw the sprite of badges*/
        void drawBadges(sf::RenderWindow& window, int x, int y);

        /*
            These 4 functions are setters and getters of the hero and a boss
        */
        CharacterHero& getCharacterHero()const;
        void setCharacterHero(CharacterHero&);
        CharacterBoss& getCharacterBoss()const;
        void setCharacterBoss(CharacterBoss&);

        /*
            These 3 functions are used to make an animation of the hero during the fight
        */
        void forwardHero();
        void backwardHero();
        void fightHero();

        /*
            These 2 functions are used to make an animation of the boss during the fight
        */
        void throwingBoss();
        void fightBoss();

        /*
            This function is used by the hero. It's where regeneration circles are animated
        */
        void regenCircles();
};

#endif // PERSONNAGEVIEW_H

