#include "StoryView.h"
#include <iostream>

using std::cout;
using std::endl;

StoryView::StoryView()
{
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}

	if (!story_texture.loadFromFile("Images/Backgrounds/Story.png"))
    {
        std::cout << "Problem for loading background" << std::endl;
    }

    story_sprite.setTexture(story_texture);
    story_sprite.setPosition(0, 0);
    story_sprite.scale(1.0f, 1.0f);

	intro.setFont(font);
	intro.setFillColor(sf::Color::White);
	intro.setString("Hello brave warrior !\n\nI hope you're ready to fight to save Aslorth.\nOur troops have been under enemy rule for many years.\n"
                 "Now is the time to put an end to this tyranny.\nYou're the only one who can save us\n\n - Take control of your spaceship,\n - Head for a planet\n"
                    " - Fight the ennemy and collect the 12 UAC's badges.\n\nBe carefull, if you kill the ennemy,\nhe'll be stronger the second time !\n\n"
                    "Take care of you, you're our only hope.\n\n\nSquadron 4's captains");
	intro.setPosition(sf::Vector2f(20,15));
	intro.setCharacterSize(45);

	continueKey.setFont(font);
	continueKey.setFillColor(sf::Color::White);
	continueKey.setString("> Press space key to continue or press T key to enter tutorial <");
	continueKey.setPosition(sf::Vector2f(820,870));
	continueKey.setCharacterSize(20);
	continueKey.setStyle(sf::Text::Bold);

	conclu.setFont(font);
	conclu.setFillColor(sf::Color::White);
	conclu.setString("Hello, again my friend !\n\nThank you for your help !\nYou've done an unbelievable work to save the universe.\n"
                  "You are the most powerful fighter that Aslorth've ever seen.\nIf you want to take the badges with you,\nyou will have to start fighting again.\n"
                  "But be careful, the ennemy is getting stronger and stronger !\n\nGood luck.\n\n\n"
                  "Squadron 4's captains");
	conclu.setPosition(sf::Vector2f(20,15));
	conclu.setCharacterSize(45);
    //ctor
}

StoryView::~StoryView()
{
    //dtor
}

StoryView::StoryView(const StoryView& other)
{
    //copy ctor
}

StoryView& StoryView::operator=(const StoryView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void StoryView::introduction(Management& man,sf::RenderWindow &window)
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

                case sf::Keyboard::T:
                    window.clear();
                    man.tuto(window);
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

		window.draw(story_sprite);
		window.draw(continueKey);
		window.draw(intro);
		window.display();
	}
}

void StoryView::conclusion(Management& man,sf::RenderWindow &window)
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
                    man.increaseStats(window);
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

        window.draw(story_sprite);
		window.draw(conclu);
		window.draw(continueKey);
		window.display();
	}
}
