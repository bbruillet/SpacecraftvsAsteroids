#ifndef MAPSPACEVIEW_H
#define MAPSPACEVIEW_H
#include "Management.h"

/*
this class allows us to show the universe map
*/

class MapSpaceView
{
    public:
        /*
        Constructor
        Destructor
        copy constructor
        operator =
        */

        MapSpaceView();
        virtual ~MapSpaceView();
        MapSpaceView(const MapSpaceView& other);
        MapSpaceView& operator=(const MapSpaceView& other);

        /*
        show map display the map in large
        */
        void showMap(Management& man,sf::RenderWindow& window);

        /*
        play map display the map but, we are concentrate on our spaceship
        */
        void playMap(Management& man,sf::RenderWindow& window);

    protected:

    private:
};

#endif // MAPSPACEVIEW_H
