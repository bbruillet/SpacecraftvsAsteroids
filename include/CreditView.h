#ifndef CREDITVIEW_H
#define CREDITVIEW_H
#include "Management.h"
#define MAX_NUMBER_OF_STUDENTS 4
class CreditView
{
    public:
        CreditView();
        virtual ~CreditView();
        void showCredit(Management& man,sf::RenderWindow& windowJeu);

    protected:

    private:
         sf::Font font;
         sf::Text credit[MAX_NUMBER_OF_STUDENTS];
};

#endif // CREDITVIEW_H
