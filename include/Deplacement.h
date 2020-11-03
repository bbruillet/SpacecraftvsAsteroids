#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include <SFML/Graphics.hpp>


#include <iostream>
#include <vector>

class Deplacement : public sf::Event
{
    private:

    public:
        Deplacement();
        virtual ~Deplacement();

        int seDeplacerX(Event event, int x);
        int seDeplacerY(Event event, int y);

    protected:

};

#endif // DEPLACEMENT_H
