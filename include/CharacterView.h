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

        void drawHero(sf::RenderWindow &window);
        void drawBoss(sf::RenderWindow &window);

        CharacterHero& getCharacterHero()const;
        void setCharacterHero(CharacterHero&);

        CharacterBoss& getCharacterBoss()const;
        void setCharacterBoss(CharacterBoss&);

        void forwardHero();

    private:

        CharacterHero* hero;
        CharacterBoss* boss;
};

#endif // PERSONNAGEVIEW_H
