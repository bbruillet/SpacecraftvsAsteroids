#include "ScreenResultView.h"

ScreenResultView::ScreenResultView()
{
    //ctor
}

ScreenResultView::~ScreenResultView()
{
    //dtor
}

void ScreenResultView::showResult(Management& man,sf::RenderWindow& window,int result)
{

    sf::View view;
    view.setSize(1600,900);
    view.setCenter(800,450);
    window.setView(view);


    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
    {
        cout << "Internal error" <<endl;
    }

    sf::Text textEvent;
    sf::Text textInstruction;
    textEvent.setFont(font);
    textInstruction.setFont(font);
    textEvent.setCharacterSize(100);
    textInstruction.setCharacterSize(50);
    textEvent.setStyle(sf::Text::Bold);
    textInstruction.setStyle(sf::Text::Bold);

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
                    if(result == 1)
                    {
                        if(man.getNbStory() == 2)
                            man.story(window);
                        else
                            man.increaseStats(window);
                    }
                    else
                    {
                        man.launch(window);
                    }

                    break;
                default:
                    break;
                }
                break;
                default:
                    break;
            }
		}

        //afficher Victoire ou défaite condition
        window.clear();
        if(result == 1)
        {
            man.setVictoryTexture();
            textEvent.setFillColor(sf::Color(244,130,83));
            textEvent.setString("Victory");
            textInstruction.setFillColor(sf::Color(241, 159, 10));
            textInstruction.setString("> Press space key for entering laboratory <");

        }
        if(result == 2)
        {
            man.setLoseTexture();
            textEvent.setFillColor(sf::Color::Red);
            textEvent.setString("Wasted");
            textInstruction.setFillColor(sf::Color(241, 159, 10));
            textInstruction.setString("> Press space key to go back to your spaceship <");
        }

        man.setSpriteVictory();


        textEvent.setPosition(575, 150);
        textInstruction.setPosition(150, 25);

        window.clear();
        window.draw(man.getVictory_sprite());
        window.draw(textEvent);
        window.draw(textInstruction);

        man.getCharacterView().drawBadges(window, 10, 425);

        window.display();
	}

}
