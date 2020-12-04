#ifndef SCREENRESULTVIEW_H
#define SCREENRESULTVIEW_H
#include "Management.h"


class ScreenResultView
{
    public:
        ScreenResultView();
        virtual ~ScreenResultView();
        void showResult(Management& man,sf::RenderWindow& window,int result);

    protected:

    private:
        sf::Font font;
};

#endif // SCREENRESULTVIEW_H
