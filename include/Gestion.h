#ifndef GESTION_H
#define GESTION_H


#include <SFML/Graphics.hpp>
class Gestion : public sf::Event
{
    public:
        int choixMenu = 0;
        Gestion();
        virtual ~Gestion();

        void fenetrePrincipale(); //Widow windowjeu
        void menu(sf::RenderWindow & windowJeu);
        void launch(sf::RenderWindow & windowJeu);
        void pause(sf::RenderWindow & windowJeu);

        void map_space(sf::RenderWindow & windowJeu);


    protected:

    private:
//        sf::RenderWindow windowJeu;
};

#endif // GESTION_H
