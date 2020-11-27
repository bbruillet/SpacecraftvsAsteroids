#ifndef PERSONNAGEVIEW_H
#define PERSONNAGEVIEW_H
#include "PersonnageHeros.h"
#include "PersonnageBoss.h"
#include <SFML/Graphics.hpp>

class PersonnageView
{
    public:
        PersonnageView(/*Personnage* personnage*/);
        virtual ~PersonnageView();
        PersonnageView(const PersonnageView& other);
        PersonnageView& operator=(const PersonnageView& other);

      /*      virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(personnage_sprite);
        }*/
        sf::Sprite personnage_heros_sprite;
        sf::Texture personnage_heros_texture;
        sf::IntRect rectHeros;

        sf::Sprite personnage_boss_sprite;
        sf::Texture personnage_boss_texture;

        void drawHeros(sf::RenderWindow &window);
        void drawBoss(sf::RenderWindow &window);

        PersonnageHeros& getPersonnageHeros()const;
        void setPersonnageHeros(PersonnageHeros&);

        PersonnageBoss& getPersonnageBoss()const;
        void setPersonnageBoss(PersonnageBoss&);

        void course();

    private:

        PersonnageHeros* heros;
        PersonnageBoss* boss;
};

#endif // PERSONNAGEVIEW_H
