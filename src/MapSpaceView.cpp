#include "MapSpaceView.h"

/*
Constructor
*/

MapSpaceView::MapSpaceView()
{
    //ctor
}

/*
Destructor
*/

MapSpaceView::~MapSpaceView()
{
    //dtor
}

MapSpaceView::MapSpaceView(const MapSpaceView& other)
{
    //copy ctor
}

/*
operator =
*/
MapSpaceView& MapSpaceView::operator=(const MapSpaceView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/*
Display the map in large, display the universe with planets
*/
void MapSpaceView::showMap(Management& man,sf::RenderWindow& window)
{
    sf::View view(sf::FloatRect(0, 0, 16000, 8642));
    view.setCenter(7130, 3150);
    window.setView(view);

    while (window.isOpen())
    {

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                    window.close();
            }

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::M)
                {
                    window.clear();

                    man.launch();
                }
            }
        }

        sf::Font font;

        if (!font.loadFromFile("Polices/SpaceFont.ttf"))
        {
            cout << "Internal error" <<endl;
        }

        sf::Text text;
        text.setFont(font);
        text.setString("> Press M to get back in the universe <");
        text.setCharacterSize(500);
        text.setPosition(200, -600);

        window.clear();

        window.setView(view);
        window.draw(man.getUniverse().getUniverse_sprite());

        for(int i(0);i<man.getUniverse().getSizePlanets();i++)
        {
            window.draw(*man.getUniverse().getPlanet(i));
        }

        for(int i(0); i < man.getUniverse().getSizePlanetsUnreach(); i++)
        {
            window.draw(*man.getUniverse().getPlanetUnreach(i));
        }

        window.draw(text);
        window.display();

    }
}

/*
Display the map concentrate on spaceship, display the universe with planets
In this function, we compare the position of the spaceship with planets,
if this last is on the planet we can enter on it
*/

void MapSpaceView::playMap(Management& man,sf::RenderWindow& window)
{

 sf::Font font;

    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
    {
        cout << "Internal error" <<endl;
    }

    sf::View view(sf::FloatRect(2000, 2000, 3450, 1800));
    view.setCenter(man.getSpaceCraft().getX(), man.getSpaceCraft().getY());

    Planet planetInProgress;

    int display = 0;

    int x = man.getSpaceCraft().getX();
    int y = man.getSpaceCraft().getY();

    int a,b;

    while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                switch (event.type)
                {
                    case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                    case sf::Keyboard::Escape:

                        window.clear();
                        view.reset(sf::FloatRect(2048, 1024, 1500, 900));
                        view.setCenter(750, 450);
                        window.setView(view);

                        man.pauseMenu();
                        break;
                        default:
                        break;
                    }
                    default:
                        break;
                }
                for (int i (0); i< man.getUniverse().getSizePlanets();i++){
                    if((man.getSpaceCraft().getX() >= man.getUniverse().getPlanet(i)->getX()+200 && man.getSpaceCraft().getX() <= man.getUniverse().getPlanet(i)->getX()+800)
                       && (man.getSpaceCraft().getY() >= man.getUniverse().getPlanet(i)->getY()+200 && man.getSpaceCraft().getY() <= man.getUniverse().getPlanet(i)->getY() + 800))
                    {
                        display = 1;
                        planetInProgress = *man.getUniverse().getPlanet(i);

                            switch (event.type)
                            {
                                case sf::Event::KeyReleased:
                                switch(event.key.code)
                                {
                                    case sf::Keyboard::Return:
                                        /*
                                        we set the background of the planet
                                        and we launch the function of fight
                                        */
                                        man.getBiome().setBackground("Images/Backgrounds/"+planetInProgress.getName()+"_Background.png");
                                        man.fightPlanet(planetInProgress);


                                    break;
                                    default:
                                        break;
                                }
                                default:
                                    break;
                            }


                    }
                    else
                    {
                        if(*man.getUniverse().getPlanet(i) == planetInProgress){
                            display = 0;
                        }
                    }

            }

                if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::M)
                {
                    window.clear();
                    man.mapSpace();
                }
            }

                /*
                We move on the space map, and the view is moving at the same time we move
                */
                if(event.type == sf::Event::EventType::KeyPressed)
                {
                    a = x;
                    b = y;


                    x = man.getSpaceCraftView().moveOnX(event, x);
                    y = man.getSpaceCraftView().moveOnY(event, y);

                    a = x-a;
                    b = y-b;
                    view.move(a,b);

                    man.getSpaceCraft().setX(x);
                    man.getSpaceCraft().setY(y);
                    man.getSpaceCraftView().getSpacecraft_sprite().setPosition(x,y);
                }
            }

            sf::Text text;
            text.setFont(font);
            text.setString("> Press enter key to land <");
            text.setCharacterSize(100);
            text.setPosition(sf::Vector2f(planetInProgress.getX()-200, planetInProgress.getY()-100));


            window.clear();
            window.setView(view);
            window.draw(man.getUniverse().getUniverse_sprite());

            for(int i(0);i<man.getUniverse().getSizePlanets();i++)
            {
                window.draw(*man.getUniverse().getPlanet(i));
            }

            for(int i(0); i < man.getUniverse().getSizePlanetsUnreach(); i++)
            {
                window.draw(*man.getUniverse().getPlanetUnreach(i));
            }

            if(display == 1)
            {
                window.draw(text);
            }

            man.getSpaceCraftView().setSpacecraft(man.getSpaceCraft());
            man.getSpaceCraftView().drawSpacecraft(window);
            window.display();



        }
}
