#ifndef CREDITVIEW_H
#define CREDITVIEW_H
#include "Management.h"
#define MAX_NUMBER_OF_STUDENTS 4

/*
    This class allows us to display who create the game
*/
class CreditView
{
    public:
        /*
        Constructor and destructor
        */
        CreditView();
        virtual ~CreditView();

        /*
        function which display the credits
        */
        void showCredit(Management& man,sf::RenderWindow& windowJeu);

    protected:

    private:
        /*
             These members data are
             -the font of the police used
             -the text we will display
             -and the background sprite
        */

         sf::Font font;
         sf::Text credits[MAX_NUMBER_OF_STUDENTS];

         sf::Texture credit_texture;
         sf::Sprite credit_sprite;
};

#endif // CREDITVIEW_H
