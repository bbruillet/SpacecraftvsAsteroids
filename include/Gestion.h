#ifndef GESTION_H
#define GESTION_H


#include <SFML/Graphics.hpp>
class Gestion : public sf::Event
{
    public:
        int choixMenu = 0;
        Gestion();
        virtual ~Gestion();

        void menu();
        void launch();


    protected:

    private:
};

#endif // GESTION_H
