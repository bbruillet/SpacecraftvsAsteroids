#ifndef MAPSPACEVIEW_H
#define MAPSPACEVIEW_H
#include "Management.h"

class MapSpaceView
{
    public:
        MapSpaceView();
        virtual ~MapSpaceView();
        MapSpaceView(const MapSpaceView& other);
        MapSpaceView& operator=(const MapSpaceView& other);

        void showMap(Management& man,sf::RenderWindow& window);
        void playMap(Management& man,sf::RenderWindow& window);

    protected:

    private:
};

#endif // MAPSPACEVIEW_H
