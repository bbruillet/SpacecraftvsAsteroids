#ifndef SPACECRAFTVIEW_H
#define SPACECRAFTVIEW_H
#include <SFML/Graphics.hpp>
#include "Spacecraft.h"


class SpacecraftView : public sf::Event, public IConstante
{
    public:
        SpacecraftView();
        virtual ~SpacecraftView();
        SpacecraftView(const SpacecraftView& other);
        SpacecraftView& operator=(const SpacecraftView& other);

        void drawSpacecraft(sf::RenderWindow &window);

         //Sprite et texture du vaisseau
        sf::Sprite spacecraft_sprite;
        sf::Texture spacecraft_texture;
        sf::IntRect rectSourceSprite;


        //Méthodes de positions
        int moveOnX(Event event, int x);
        int moveOnY(Event event, int y);

        Spacecraft& getSpacecraft()const;
        void setSpacecraft(Spacecraft&);

    private:
        Spacecraft* spacecraft;


};

#endif // VAISSEAUVIEW_H
