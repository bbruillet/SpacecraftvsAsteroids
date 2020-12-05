#include "SpacecraftView.h"

/*
    This is the constructor.
    InRect's member is initialized here.
    How does it work ? --> rect(where you want to start -> x,
                                where you want to start -> y,
                                width of a sample,
                                height of a sample)
*/
SpacecraftView::SpacecraftView()
{
    //ctor
    sf::IntRect rect(0, 0, 125, 125);
    rectSourceSprite = rect;
}

/*
    This is the destructor
*/
SpacecraftView::~SpacecraftView()
{
    delete(spacecraft);
}

/*
    This is the copy constructor
*/
SpacecraftView::SpacecraftView(const SpacecraftView& other)
{
    //copy ctor
}

/*
    This operato='s function
*/
SpacecraftView& SpacecraftView::operator=(const SpacecraftView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/*
    This is where we load a texture (of the spacecraft).
    The texture is added to a sprite and the rect too.
    After that, the sprite is draw in the window
*/
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

/*
    This function is used to use a sprite sheet for the spacecraft.
    THis function, particularly is used to move your spacecraft on x axis !
*/
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

/*
    This function is used to use a sprite sheet for the spacecraft.
    THis function, particularly is used to move your spacecraft on y axis !
*/
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

/*This is the setter of a spacecraft*/
void SpacecraftView::setSpacecraft(Spacecraft& spacecraft)
{
    this->spacecraft = &spacecraft;
}

/*This is the getter of a spacecraft*/
Spacecraft& SpacecraftView::getSpacecraft()const
{
    return *spacecraft;
}

sf::Sprite SpacecraftView::getSpacecraft_sprite() const
{
    return spacecraft_sprite;
}
