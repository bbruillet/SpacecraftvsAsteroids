#ifndef SCREENRESULTVIEW_H
#define SCREENRESULTVIEW_H
#include "Management.h"

/*This class is used to show to the player if it's a victory or a game over*/
class ScreenResultView
{
    private:
        /*
            These are members data to load a font, and create two texts !
        */
        sf::Font font;
        sf::Text textEvent;
        sf::Text textInstruction;

    public:
        /*
            The new 2 lines are :
                - The constructor
                - the destructor
        */
        ScreenResultView();
        virtual ~ScreenResultView();

        /*
            This function is going to be used in management
        */
        void showResult(Management& man,sf::RenderWindow& window,int result);

    protected:
};

#endif // SCREENRESULTVIEW_H
