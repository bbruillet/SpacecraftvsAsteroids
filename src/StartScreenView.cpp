#include "StartScreenView.h"

/*
    This is the constructor
*/
StartScreenView::StartScreenView()
{
    //ctor
    /*
        it is a function to load the font
    */
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}
    //it is a function to load the background

	if (!start_texture.loadFromFile("Images/Backgrounds/Spacefighter.png"))
    {
        std::cout << "Problem while loading background" << std::endl;
    }
    /*
  	  Allows to give a texture and position
    */
    start_sprite.setTexture(start_texture);
    start_sprite.setPosition(0, 0);
    start_sprite.scale(1.0f, 1.0f);

    continueKey.setFont(font);
	continueKey.setFillColor(sf::Color::White);
	continueKey.setString("> Press space key to continue <");
	continueKey.setPosition(sf::Vector2f(400,700));
	continueKey.setCharacterSize(50);
	continueKey.setStyle(sf::Text::Bold);
}

/*This is the destructor*/
StartScreenView::~StartScreenView()
{
    //dtor
}

/*This is the copy constructor*/
StartScreenView::StartScreenView(const StartScreenView& other)
{
    //copy ctor
}

/*This is operator='s function*/
StartScreenView& StartScreenView::operator=(const StartScreenView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/*
    This function is used to use something in Management.h
    Here, some event with a keyReleased will be mainly done
*/
void StartScreenView::show(Management& man,sf::RenderWindow& window)
{
while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
		    if (event.type == sf::Event::Closed) {
                window.close();
            }
			switch (event.type)
			{
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Space:
                    window.clear();
                    man.menu();
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
		window.draw(start_sprite);
		window.display();
		sf::sleep(sf::milliseconds(500));
        window.clear();
        window.draw(start_sprite);
		window.draw(continueKey);
		window.display();
        sf::sleep(sf::milliseconds(500));

	}
}
