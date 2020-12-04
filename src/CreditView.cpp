#include "CreditView.h"

CreditView::CreditView()
{
    //ctor


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


	credit[0].setFont(font);
	credit[0].setFillColor(sf::Color::White);
	credit[0].setString("> Bruillet Baptiste ");
	credit[0].setPosition(sf::Vector2f(950,200));

	credit[1].setFont(font);
	credit[1].setFillColor(sf::Color::White);
	credit[1].setString("> Cornut Sylvain ");
	credit[1].setPosition(sf::Vector2f(950,350));

	credit[2].setFont(font);
	credit[2].setFillColor(sf::Color::White);
	credit[2].setString("> Danese Loris " );
	credit[2].setPosition(sf::Vector2f(950,500));

	credit[3].setFont(font);
	credit[3].setFillColor(sf::Color::White);
	credit[3].setString("> Smet Antoine " );
	credit[3].setPosition(sf::Vector2f(950,650));

	for (int i = 0; i < MAX_NUMBER_OF_STUDENTS; i++)
	{
		credit[i].setCharacterSize(66);
	}

}

CreditView::~CreditView()
{
    //dtor
}

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
		    // case revenir menu
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                window.clear();
                man.menu(window);
            }
		}
		window.clear();
        window.draw(credit_sprite);
		 for (int i = 0; i < MAX_NUMBER_OF_STUDENTS; i++)
            {
                window.draw(credit[i]);
            }

		window.display();
	}
}
