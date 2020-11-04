#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include <SFML/Graphics.hpp>
#include "Personnage.h"


#include <iostream>
#include <vector>

class Deplacement : public sf::Event, sf::Drawable
{
    private:
//        Personnage personnage;

  //      virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
  //      {
  //          target.draw(personnage.perso_sprite);
  //      }

    public:
        Deplacement();
        virtual ~Deplacement();

//        int seDeplacerX(Event event, int x);
//        int seDeplacerY(Event event, int y);
//
//        Personnage getPersonnage() const;
//        void setPersonnage(Personnage personnage);

    protected:

};

#endif // DEPLACEMENT_H
