#ifndef VAISSEAUVIEW_H
#define VAISSEAUVIEW_H
#include <SFML/Graphics.hpp>
#include "Vaisseau.h"


class VaisseauView : public sf::Event, public IConstante
{
    public:
        VaisseauView();
        virtual ~VaisseauView();
        VaisseauView(const VaisseauView& other);
        VaisseauView& operator=(const VaisseauView& other);

        void drawVaisseau(sf::RenderWindow &window);

         //Sprite et texture du vaisseau
        sf::Sprite vaisseau_sprite;
        sf::Texture vaisseau_texture;
        sf::IntRect rectSourceSprite;


        //Méthodes de positions
        int seDeplacerX(Event event, int x);
        int seDeplacerY(Event event, int y);

        Vaisseau& getVaisseau()const;
        void setVaisseau(Vaisseau&);

    private:
        Vaisseau* vaisseau;


};

#endif // VAISSEAUVIEW_H
