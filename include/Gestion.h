#ifndef GESTION_H
#define GESTION_H


#include <SFML/Graphics.hpp>

class Gestion : public sf::Event
{
    public:
        Gestion();
        virtual ~Gestion();

        void launch();

    protected:

    private:
};

#endif // GESTION_H
