#ifndef BARVIEW_H
#define BARVIEW_H

#include <SFML/Graphics.hpp>

class BarView
{
    public:
        /*Constructeur*/
        BarView(sf::Vector2f dimensionFrameLife = sf::Vector2f(500,25),int maxLife = 100,sf::Vector2f dimensionFrameShield = sf::Vector2f(200,12.5),int maxShield=100);
        virtual ~BarView();
        BarView(const BarView& other);
        BarView& operator=(const BarView& other);
        /*----------------*/

        /*Méthode concernant la barre de vie*/
        void updateLife(int life);
        void drawLife(sf::RenderWindow& window);
        void setMaxLife(int maxLife);
        void setBarLifePosition(int xLife,int ylife);
        /*--------------------------------*/


        /*-----------------Bouclier*/
        void updateShield(int shield);
        void drawShield(sf::RenderWindow& window);
        void setMaxShield(int maxShield);
        void setBarShieldPosition(int xShield,int yShield);

        /*----Commun*/

        void setRotation();

    private:
        /*--------------VIE--------------*/
        sf::RectangleShape frameLife;
        sf::RectangleShape barFrameLife;
        sf::Vector2f dimensionFrameLife;

        int maxLife;
        int actualLife;
        int remainingLife;
        float coefSizeLife;
        int xLife,yLife;
        /*------------------------------*/


        /*-------------BOUCLIER-------------*/
        sf::RectangleShape frameShield;
        sf::RectangleShape barFrameShield;
        sf::Vector2f dimensionFrameShield;

        int maxShield;
        int actualShield;
        int remainingShield;
        float coefSizeShield;
        int xShield,yShield;
        /*--------------------------------*/





};

#endif // BARREVIEW_H
