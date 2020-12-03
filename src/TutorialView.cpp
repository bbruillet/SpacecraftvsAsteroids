#include "TutorialView.h"

TutorialView::TutorialView()
{
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}

	if (!tuto_texture.loadFromFile("Images/Backgrounds/Tutorial.png"))
    {
        std::cout << "Problem for loading background" << std::endl;
    }

    tuto_sprite.setTexture(tuto_texture);
    tuto_sprite.setPosition(0, 0);
    tuto_sprite.scale(1.0f, 1.0f);

	tuto[0].setString("Ceci est un test");
	tuto[0].setPosition(sf::Vector2f(815,20));

	tuto[1].setString("Ceci est un test de combat");
	tuto[1].setPosition(sf::Vector2f(20,470));

	continueKey.setFont(font);
	continueKey.setFillColor(sf::Color::White);
	continueKey.setString("> Press space key to continue <");
	continueKey.setPosition(sf::Vector2f(820,870));
	continueKey.setCharacterSize(20);
	continueKey.setStyle(sf::Text::Bold);

	for(int i =0; i< 2; i++)
    {
        tuto[i].setFont(font);
        tuto[i].setCharacterSize(40);
        tuto[i].setFillColor(sf::Color::White);
    }
    //ctor
}

TutorialView::~TutorialView()
{
    //dtor
}

void TutorialView::draw(Management& man,sf::RenderWindow &window)
{
    while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Space:
                    window.clear();
                    man.launch(window);
                    break;

                default:
                break;

			}
			break;
                default:
                    break;
			}

		}

		window.clear();

		window.draw(tuto_sprite);
		window.draw(continueKey);
		for(int i =0; i< 2; i++)
        {
            window.draw(tuto[i]);
        }

		window.display();
	}
}
