#ifndef GESTION_H
#define GESTION_H

#include "IConstante.h"

#include <SFML/Graphics.hpp>
#include "BiomePlanete.h"
class Gestion : public sf::Event, public IConstante
{
    public:
        int choixMenu = INITIALISED_VALUE;
        Gestion();
        virtual ~Gestion();

        void fenetrePrincipale(); //Widow windowjeu
        void menu(sf::RenderWindow & windowJeu);
        void launch(sf::RenderWindow & windowJeu);
        void pause(sf::RenderWindow & windowJeu);
        void combatPlanete(sf::RenderWindow & windowJeu,BiomePlanete&);

        void map_space(sf::RenderWindow & windowJeu);


    protected:

    private:
//        sf::RenderWindow windowJeu;
};

#endif // GESTION_H
