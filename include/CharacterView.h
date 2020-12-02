#ifndef PERSONNAGEVIEW_H
#define PERSONNAGEVIEW_H
#include "CharacterHero.h"
#include "CharacterBoss.h"
#include <SFML/Graphics.hpp>

class CharacterView
{
    public:
        CharacterView(/*Personnage* personnage*/);
        virtual ~CharacterView();
        CharacterView(const CharacterView& other);
        CharacterView& operator=(const CharacterView& other);

      /*      virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(personnage_sprite);
        }*/
        sf::Sprite character_hero_sprite;
        sf::Texture character_hero_texture;
        sf::IntRect rectHero;

        sf::Sprite character_boss_sprite;
        sf::Texture character_boss_texture;
        sf::IntRect rectBoss;

        sf::Sprite attack_boss_sprite;
        sf::Texture attack_boss_texture;
        sf::IntRect rectAttackBoss;

        sf::Sprite regen_sprite;
        sf::Texture regen_texture;
        sf::IntRect rectRegen;

        sf::Sprite badge_sprite;
        sf::Texture badge_texture;
        sf::IntRect rectBadge;

        void drawHero(sf::RenderWindow &window);
        void drawBoss(sf::RenderWindow &window);
        void drawBoss2(sf::RenderWindow &window);
        void drawRegenCircles(sf::RenderWindow &window);
        void drawBadges(sf::RenderWindow& window);

        CharacterHero& getCharacterHero()const;
        void setCharacterHero(CharacterHero&);

        CharacterBoss& getCharacterBoss()const;
        void setCharacterBoss(CharacterBoss&);

        void forwardHero();
        void backwardHero();
        void fightHero();

//        void forwardBoss();
        void throwingBoss();
        void fightBoss();

        void regenCircles();

    private:

        CharacterHero* hero;
        CharacterBoss* boss;

        int test;
};

#endif // PERSONNAGEVIEW_H
