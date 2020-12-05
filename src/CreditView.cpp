#include "CreditView.h"

/*
constructor
*/
CreditView::CreditView()
{
    //ctor

    /*
    Load the sprite and the texture
    */
    if (!credit_texture.loadFromFile("Images/Backgrounds/credit.png"))
    {
        std::cout << "Problem while loading the background" << std::endl;
    }
    credit_sprite.setTexture(credit_texture);
    credit_sprite.setPosition(0, 0);


      if (!font.loadFromFile("Polices/SpaceFont.ttf"))
    {
        cout << "Internal error" <<endl;
    }

    /*
    Text to display
    */

	credits[0].setFont(font);
	credits[0].setFillColor(sf::Color::White);
	credits[0].setString("> Bruillet Baptiste ");
	credits[0].setPosition(sf::Vector2f(950,200));

	credits[1].setFont(font);
	credits[1].setFillColor(sf::Color::White);
	credits[1].setString("> Cornut Sylvain ");
	credits[1].setPosition(sf::Vector2f(950,350));

	credits[2].setFont(font);
	credits[2].setFillColor(sf::Color::White);
	credits[2].setString("> Danese Loris " );
	credits[2].setPosition(sf::Vector2f(950,500));

	credits[3].setFont(font);
	credits[3].setFillColor(sf::Color::White);
	credits[3].setString("> Smet Antoine " );
	credits[3].setPosition(sf::Vector2f(950,650));

	for (int i = 0; i < MAX_NUMBER_OF_STUDENTS; i++)
	{
		credits[i].setCharacterSize(66);
	}

}

CreditView::~CreditView()
{
    //dtor
}

/*
this function contains a RenderWindow, we will draw our text and sprite into this one
*/

void CreditView::showCredit(Management& man,sf::RenderWindow& window)
{
while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
		    if (event.type == sf::Event::Closed) {
                window.close();
            }

		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                window.clear();
                man.menu();
            }
		}
		window.clear();
        window.draw(credit_sprite);
		 for (int i = 0; i < MAX_NUMBER_OF_STUDENTS; i++)
            {
                window.draw(credits[i]);
            }

		window.display();
	}
}
