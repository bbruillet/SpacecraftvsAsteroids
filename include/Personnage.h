#ifndef PERSONNAGE_H
#define PERSONNAGE_H


#include <iostream>
#include <ostream>
#include <string>
#include <sstream>

#include <cstdio>
#include <SFML/Graphics.hpp>

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::ostream;

class Personnage /*: public sf::Drawable, public sf::Event*/
{
    private:
        string nom;
        int ptsAttaque, ptsVie, ptsExperience, niveau, ptsAttaqueSpeciale, bouclier;
        double coupsCritique, esquive;
        int compteurSpe;
        int x,y;
        string image;
        int regeneration;

          virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            target.draw(personnage_sprite);
        }

    public:
        //Constucteurs et destructeurs
        Personnage(const string nom = "Joueur", const int ptsAttaque = 0, const int ptsVie = 10, const int ptsExperience = 0, const int niveau = 0,
                   const int ptsAttaqueSpeciale = 0, const int bouclier = 0 ,const double coupsCritique = 0.0, const double esquive = 0.0, const int x = 0, const int y = 0,
                   const string image = "Dossier", const int regeneration = 0);

        virtual ~Personnage();
        Personnage(const Personnage&);
        Personnage& operator=(const Personnage&);

        //Méthodes utiles
        virtual string str() const; //virtual -> héritage
        virtual Personnage* clone()const;
        //Getters et setters
        string getNom() const;
        void setNom(const string &);

        int getPtsAttaque() const;
        void setPtsAttaque(const int &);

        int getPtsVie() const;
        void setPtsVie(const int &);

        int getPtsExperience() const;
        void setPtsExperience(const int &);

        int getNiveau() const;
        void setNiveau(const int &);

        int getPtsAttaqueSpeciale() const;
        void setPtsAttaqueSpeciale(const int &);

        int getBouclier() const;
        void setBouclier(const int &);

        double getCoupsCritique() const;
        void setCoupsCritique(const double &);

        double getEsquive() const;
        void setEsquive(const double &);

        int getCompteurSpe() const;
        void setCompteurSpe(const int &);

        int getX() const;
        void setX(const int &);

        int getY() const;
        void setY(const int &);

        string getImage() const;
        void setImage(const string &);

        int getRegeneration() const;
        void setRegeneration(const int &);

        sf::Sprite personnage_sprite;
        sf::Texture personnage_texture;

};

#endif // PERSONNAGE_H
