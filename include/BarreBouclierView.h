#ifndef BARREBOUCLIERVIEW_H
#define BARREBOUCLIERVIEW_H

#include <SFML/Graphics.hpp>

class BarreBouclierView
{
    public:
        /* CONSTRU */
        BarreBouclierView(sf::Vector2f dimensionCadreBouclier = sf::Vector2f(200,12.5),int BouclierMax=100);
        virtual ~BarreBouclierView();

        /*Méthodes*/
        void updateB(int nouveauBouclier);
        void drawBouclier(sf::RenderWindow& window);
        void setBouclierMax(int bouclierMax);
        void setPositionBarreBouclier(int xBouc,int yBouc);
        void setRotation();

    private:


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

#endif // BARREBOUCLIERVIEW_H
