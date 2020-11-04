#ifndef PERSONNAGE_H
#define PERSONNAGE_H


#include <iostream>
#include <ostream>
#include <string>

#include <cstdio>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

/*enum Orientation
{
    Droite,
    Bas,
    Gauche,
    Haut
};*/

class Personnage : public sf::Drawable, public sf::Event
{
    private:
        string nom, race;
        int ptsAttaque, ptsVie, ptsExperience, niveau;
        int x, y;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(perso_sprite);
        }

    public:
        Personnage(string nom, string race, int ptsAttaque, int ptsVie, int ptsExperience, int niveau);
        Personnage();
        virtual ~Personnage();
        Personnage(const Personnage& other);
        Personnage& operator=(const Personnage& other);

        sf::Sprite perso_sprite;
        sf::Texture perso_texture;




        //Méthodes utiles
        string str() const;

        int seDeplacerX(Event event, int x);
        int seDeplacerY(Event event, int y);
        //Méthodes de positions


        //Getters et setters
        int getPtsAttaque() const;
        void setPtsAttaque(int ptsAttaque);

        int getPtsVie() const;
        void setPtsVie(int ptsVie);

        int getPtsExperience() const;
        void setPtsExperience(int ptsExperience);

        int getNiveau() const;
        void setNiveau(int ptsNiveau);

        string getNom() const;
        void setNom(string nom);

        string getRace() const;
        void setRace(string race);

        int getX() const;
        void setX(int x);

        int getY() const;
        void setY(int y);

    protected:


};

#endif // PERSONNAGE_H
