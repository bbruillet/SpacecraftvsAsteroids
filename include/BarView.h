#ifndef BARVIEW_H
#define BARVIEW_H

#include <SFML/Graphics.hpp>

/*
    This class is used to implement life bar and shield bar.
*/
class BarView
{
    private:
        /*
            The 3 next members data are the frame (or bar) of your life.
            The first two are our frames.
            The next one is just used to set the dimensions of your frame
        */
        sf::RectangleShape frameLife;
        sf::RectangleShape barFrameLife;
        sf::Vector2f dimensionFrameLife;

        /*
            The members data are used to :
                - know the amount of your life you have at the beginning of the game
                - knwow the amount of life you have at the moment
                - know the amount of life you remain
                - It's a coefficient of life used for calculate you life bar decreased
        */
        int maxLife;
        int actualLife;
        int remainingLife;
        float coefSizeLife;
        int xLife,yLife;


        /*
            The 3 next members data are the frame (or bar) of your shield.
            The first two are our frames.
            The next one is just used to set the dimensions of your frame
        */
        sf::RectangleShape frameShield;
        sf::RectangleShape barFrameShield;
        sf::Vector2f dimensionFrameShield;


        /*
            The members data are used to :
                - know the amount of your shield you have at the beginning of the game
                - knwow the amount of shield you have at the moment
                - know the amount of shield you remain
                - It's a coefficient of shield used for calculate you shield bar decreased
        */
        int maxShield;
        int actualShield;
        int remainingShield;
        float coefSizeShield;
        int xShield,yShield;


    public:
        /*
            The 4 next lines are :
                - construcor
                - destructor
                - copy contructor
                - operator=

            The constructor is defined by default.
        */
        BarView(sf::Vector2f dimensionFrameLife = sf::Vector2f(500,25),int maxLife = 100,sf::Vector2f dimensionFrameShield = sf::Vector2f(200,12.5),int maxShield=100);
        virtual ~BarView();
        BarView(const BarView& other);
        BarView& operator=(const BarView& other);


        /*
            These functions are used for life.
            updateLife is used to update the frame of your life
            drawLife is used to draw the frame
            setMaxLife is used to set the amount of life points that you heroes have at the beginning
            setBarLifePosition is used to put the frame in the window
        */
        void updateLife(int life);
        void drawLife(sf::RenderWindow& window);
        void setMaxLife(int maxLife);
        void setBarLifePosition(int xLife,int ylife);

        /*
            These functions are used for life.
            updateShield is used to update the frame of your shield points
            drawShield is used to draw the frame
            setMaxShield is used to set the amount of shield points that you heroes have at the beginning
            setBarShieldPosition is used to put the frame in the window
        */
        void updateShield(int shield);
        void drawShield(sf::RenderWindow& window);
        void setMaxShield(int maxShield);
        void setBarShieldPosition(int xShield,int yShield);

        /*
            This function is used to set a roation for lifes's frame.
            In fact, as you can see, this frame is upsided down.
        */
        void setRotation();
};

#endif // BARVIEW_H
