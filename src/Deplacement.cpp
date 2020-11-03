#include "Deplacement.h"
#include "Personnage.h"
#include "Univers.h"

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

Deplacement::Deplacement()
{
    //ctor
}

Deplacement::~Deplacement()
{
    //dtor
}

int Deplacement::seDeplacerX(Event event, int x)
{
    switch (event.key.code)
    {
        case sf::Keyboard::Left:
        {
            x = x - 5;
            break;
        }

        case sf::Keyboard::Right:
        {
            x = x + 5;
            break;
        }
        default:
        break;

    }
//    perso.perso_sprite.setPosition(x,y);
    return x;
}

int Deplacement::seDeplacerY(Event event, int y)
{
    switch (event.key.code)
    {
        case sf::Keyboard::Up:
        {
            y = y - 5;
            break;
        }

        case sf::Keyboard::Down:
        {
            y = y + 5;
            break;
        }
        default:
        break;
    }
    return y;
}
