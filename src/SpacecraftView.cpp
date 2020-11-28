#include "SpacecraftView.h"

SpacecraftView::SpacecraftView()
{
    //ctor
    sf::IntRect rect(0, 0, 125, 125);
    rectSourceSprite = rect;
}

SpacecraftView::~SpacecraftView()
{
    //dtor
}

SpacecraftView::SpacecraftView(const SpacecraftView& other)
{
    //copy ctor
}

SpacecraftView& SpacecraftView::operator=(const SpacecraftView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void SpacecraftView::drawSpacecraft(sf::RenderWindow &window)
{

    if (!spacecraft_texture.loadFromFile("Images/Avatars/X-Wing.png"))
    {
        std::cout << "Problem while loading spacecraft's picture" << std::endl;
    }

    spacecraft_sprite.setTexture(spacecraft_texture);
    spacecraft_sprite.setTextureRect(rectSourceSprite);
    spacecraft_sprite.setPosition(spacecraft->getX(), spacecraft->getY());
    spacecraft_sprite.setOrigin(VAISSEAU_COORDONNEE_ORIGINE, VAISSEAU_COORDONNEE_ORIGINE);
    window.draw(spacecraft_sprite);
}

int SpacecraftView::moveOnX(Event event, int x)
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
            }
            else
            {
                rectSourceSprite.top = 375;
            }
            break;
        }

        case sf::Keyboard::Right:
        {
            if(x<12000)
            {
                x = x + 50;
                rectSourceSprite.top = 375;
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
    spacecraft_sprite.setTextureRect(rectSourceSprite);
    return x;
}

int SpacecraftView::moveOnY(Event event, int y)
{
    switch (event.key.code)
    {
        case sf::Keyboard::Up:
        {
            if(y>1000)
            {
                y = y - 50;

                rectSourceSprite.top = 0;
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
    spacecraft_sprite.setTextureRect(rectSourceSprite);
    return y;
}

void SpacecraftView::setSpacecraft(Spacecraft& spacecraft)
{
    this->spacecraft = &spacecraft;
}

Spacecraft& SpacecraftView::getSpacecraft()const
{
    return *spacecraft;
}
