#ifndef SPACECRAFTVIEW_H
#define SPACECRAFTVIEW_H
#include <SFML/Graphics.hpp>
#include "Spacecraft.h"

/*
    This class is used to draw the spacecraft ine the universe
*/
class SpacecraftView : public sf::Event
{
    private:
        /*
            This member data is a pointeur of a spacecraft
        */
        Spacecraft* spacecraft;

         /*
            This is the sprite & the texture of a spacecraft.
            IntRect is used for using a sprite sheet
        */
        sf::Sprite spacecraft_sprite;
        sf::Texture spacecraft_texture;
        sf::IntRect rectSourceSprite;


    public:
        /*
            The 4 next lines are :
                - constructor
                - destructor
                - copy contructor
                - operator=
        */
        SpacecraftView();
        virtual ~SpacecraftView();
        SpacecraftView(const SpacecraftView& other);
        SpacecraftView& operator=(const SpacecraftView& other);

        /*This function is used to draw a sprite of a spacecraft*/
        void drawSpacecraft(sf::RenderWindow &window);


        /*
            These 2 functions are used by a spacecraft to move in the universe
            You can move on x and y axis
        */
        int moveOnX(Event event, int x);
        int moveOnY(Event event, int y);

        /*
            This is the getter ans detter of a spacecraft
        */
        Spacecraft& getSpacecraft()const;
        void setSpacecraft(Spacecraft&);

        /*
            This is the getter od the sprite of a spacecraft
        */
        sf::Sprite getSpacecraft_sprite() const;
};

#endif // VAISSEAUVIEW_H
