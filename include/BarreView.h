#ifndef BARREVIEW_H
#define BARREVIEW_H

#include <SFML/Graphics.hpp>

class BarreView
{
    public:
        /*Constructeur*/
        BarreView(sf::Vector2f dimensionCadre = sf::Vector2f(500,25),int vieMax = 100,sf::Vector2f dimensionCadreBouclier = sf::Vector2f(200,12.5),int BouclierMax=100);
        virtual ~BarreView();
        BarreView(const BarreView& other);
        BarreView& operator=(const BarreView& other);
        /*----------------*/

        /*Méthode concernant la barre de vie*/
        void updateV(int vie);
        void drawVie(sf::RenderWindow& window);
        void setVieMax(int vieMax);
        void setPositionBarre(int xVie,int yVie);
        /*--------------------------------*/


        /*-----------------Bouclier*/
        void updateB(int nouveauBouclier);
        void drawBouclier(sf::RenderWindow& window);
        void setBouclierMax(int bouclierMax);
        void setPositionBarreBouclier(int xBouc,int yBouc);

        /*----Commun*/

        void setRotation();

    private:
        /*--------------VIE--------------*/
        sf::RectangleShape cadreVie;
        sf::RectangleShape barreVariableVie;
        sf::Vector2f dimensionCadre;

        int vieMax;
        int vieActuelle;
        int vieRestante;
        float coefTaille;
        int xVie,yVie;
        /*------------------------------*/


        /*-------------BOUCLIER-------------*/
        sf::RectangleShape cadreBouclier;
        sf::RectangleShape barreVariableBouclier;
        sf::Vector2f dimensionCadreBouclier;

        int bouclierMax;
        int bouclierActuelle;
        int bouclierRestant;
        float coefBouclier;
        int xBouc,yBouc;
        /*--------------------------------*/





};

#endif // BARREVIEW_H
