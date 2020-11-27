#include "VaisseauView.h"

VaisseauView::VaisseauView()
{
    //ctor
    sf::IntRect rect(0, 0, 125, 125);
    rectSourceSprite = rect;
}

VaisseauView::~VaisseauView()
{
    //dtor
}

VaisseauView::VaisseauView(const VaisseauView& other)
{
    //copy ctor
}

VaisseauView& VaisseauView::operator=(const VaisseauView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void VaisseauView::drawVaisseau(sf::RenderWindow &window)
{

    if (!vaisseau_texture.loadFromFile("Images/Avatars/X-Wing.png"))
    {
        std::cout << "ok" << std::endl;
    }

    vaisseau_sprite.setTexture(vaisseau_texture);
    vaisseau_sprite.setTextureRect(rectSourceSprite);
    vaisseau_sprite.setPosition(vaisseau->getX(), vaisseau->getY());
    vaisseau_sprite.setOrigin(VAISSEAU_COORDONNEE_ORIGINE, VAISSEAU_COORDONNEE_ORIGINE);
    window.draw(vaisseau_sprite);
}

int VaisseauView::seDeplacerX(Event event, int x)
{

    if(rectSourceSprite.left == 0)
    {
        rectSourceSprite.left = 125;
    }
    else if (rectSourceSprite.left == 125)
    {
        rectSourceSprite.left = 250;
    }
    else if (rectSourceSprite.left == 250)
    {
        rectSourceSprite.left = 125;
    }


    switch (event.key.code)
    {
        case sf::Keyboard::Left:
        {
            if(x>1000)
            {
                x = x - 50;
                rectSourceSprite.top = 125;

                cout << "X: "<< x << endl;
            }
            else
            {
                rectSourceSprite.top = 375;
                //vaisseau_sprite.setRotation(90);

            }
            break;
        }

        case sf::Keyboard::Right:
        {
            if(x<12000)
            {
                x = x + 50;

                rectSourceSprite.top = 375;
                cout << "X: "<< x << endl;
            }
            else
            {
                rectSourceSprite.top = 125;
            }
            break;
        }
        default:
        break;
    }
    vaisseau_sprite.setTextureRect(rectSourceSprite);
    return x;
}

int VaisseauView::seDeplacerY(Event event, int y)
{
    switch (event.key.code)
    {
        case sf::Keyboard::Up:
        {
            if(y>1000)
            {
                y = y - 50;

                rectSourceSprite.top = 0;
                cout << "Y: "<< y << endl;
            }
            else
            {
                rectSourceSprite.top = 250;
            }
            break;
        }

        case sf::Keyboard::Down:
        {
            if(y<6500)
            {
                y = y + 50;
                rectSourceSprite.top = 250;
                cout << "Y: "<< y << endl;
            }
            else
            {

                rectSourceSprite.top = 0;
            }
            break;
        }
        default:
        break;
    }
    vaisseau_sprite.setTextureRect(rectSourceSprite);
    return y;
}

void VaisseauView::setVaisseau(Vaisseau& vaisseau)
{
    this->vaisseau = &vaisseau;
}

Vaisseau& VaisseauView::getVaisseau()const
{
    return *vaisseau;
}
