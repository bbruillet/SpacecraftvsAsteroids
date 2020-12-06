#include "ScreenResultView.h"

/*
    This is the copy constructor
*/
ScreenResultView::ScreenResultView()
{
    //ctor
}

/*This is the destructor*/
ScreenResultView::~ScreenResultView()
{
    //dtor
}

/*
    This function is used to write something in Management. Instead of coding in management,
    we used to code here to have classes with the same amount of lines
*/
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

            if (event.type == sf::Event::Closed) {
            window.close();
            }


            switch (event.type)
			{
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Space:
                    if(result == 1)
                    {
                        if(man.getNbStory() == 2)
                            man.story();
                        else
                            man.increaseStats();
                    }
                    else
                    {
                        man.launch();
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

        window.clear();

        /*These 2 conditions are used to show to the user if he won or he loss the game !*/
        if(result == 1)
        {
            man.setVictoryTexture();
            textEvent.setFillColor(sf::Color(244,130,83));
            textEvent.setString("Victory");
            textInstruction.setFillColor(sf::Color(241, 159, 10));
            textInstruction.setString("> Press space key for entering laboratory <");
            textInstruction.setPosition(150, 25);
        }

        if(result == 2)
        {
            man.setLoseTexture();
            textEvent.setFillColor(sf::Color::Red);
            textEvent.setString("Wasted");
            textInstruction.setFillColor(sf::Color(241, 159, 10));
            textInstruction.setString("> Press space key to get back to your spaceship <");
            textInstruction.setPosition(120, 25);
        }

        man.setSpriteVictory();

        textEvent.setPosition(575, 150);


        window.clear();
        window.draw(man.getVictory_sprite());
        window.draw(textEvent);
        window.draw(textInstruction);

        man.getCharacterView().drawBadges(window, 10, 425);

        window.display();
	}

}
