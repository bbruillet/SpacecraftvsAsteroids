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
//    this->personnage = personnage;
}

Deplacement::~Deplacement()
{
    //dtor
}


//int Deplacement::seDeplacerX(Event event, int x)
//{
//    switch (event.key.code)
//    {
//        case sf::Keyboard::Left:
//        {
//            x = x - 5;
//            personnage.perso_sprite.rotate(200);
//            break;
//        }
//
//        case sf::Keyboard::Right:
//        {
//            x = x + 5;
//            break;
//        }
//        default:
//        break;0.
//    }
//    return x;
//}
//
//int Deplacement::seDeplacerY(Event event, int y)
//{
//    switch (event.key.code)
//    {
//        case sf::Keyboard::Up:
//        {
//            y = y - 5;
//            break;
//        }
//
//        case sf::Keyboard::Down:
//        {
//            y = y + 5;
//            break;
//        }
//        default:
//        break;
//    }
//    return y;
//}
//
///*Getter et setter*/
//Personnage Deplacement::getPersonnage() const
//{
//    return personnage;
//}
//
//void Deplacement::setPersonnage(Personnage personnage)
//{
//    this->personnage = personnage;
//z}
