#ifndef GESTION_H
#define GESTION_H

#include "IConstante.h"

#include <SFML/Graphics.hpp>
#include "BiomePlanete.h"
#include "Univers.h"
#include "Vaisseau.h"
#include "VaisseauView.h"
#include "BarreView.h"
#include "PersonnageBoss.h"
#include "PersonnageHeros.h"
#include "PersonnageView.h"
#include "Personnage.h"
#include "Planete.h"
#include "Compte.h"
#include "Combat.h"
#include <vector>

using std::vector;

class Gestion : public sf::Event, public IConstante
{
    public:
        int choixMenu = INITIALISED_VALUE;
        Gestion();
        virtual ~Gestion();

        void fenetrePrincipale(); //Window windowjeu
        void menu(sf::RenderWindow & windowJeu);
        void comptePerso(sf::RenderWindow & windowJeu);
        void comptePseudo(sf::RenderWindow & windowJeu);
        void launch(sf::RenderWindow & windowJeu);
        void combatPlanete(sf::RenderWindow & windowJeu,Planete&);

        void map_space(sf::RenderWindow & windowJeu);

        sf::Sprite versus_sprite;
        sf::Texture versus_texture;


    protected:

    private:
        Univers univers;
        Vaisseau vaisseau;
        VaisseauView viewVaisseau;
        PersonnageHeros heros;
        PersonnageView pView;
        BarreView barreHeros;
        BarreView barreBoss;
        Compte compte;
        Combat combat;
//        vector <Planete*> planetes;
//        vector <Planete*> planetesInacc;

};

#endif // GESTION_H
