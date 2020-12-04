#include "TutorialView.h"

/*
    This is the copy constructor
*/
TutorialView::TutorialView()
{
	/*
        it is a function to load the font
    */
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}
	/*
        it is a function to load the background
    */
	if (!tuto_texture.loadFromFile("Images/Backgrounds/Tutorial.png"))
    {
        std::cout << "Problem while loading background" << std::endl;
    }

	/*
        Allows to give a texture and position
    */
    tuto_sprite.setTexture(tuto_texture);
    tuto_sprite.setPosition(0, 0);
    tuto_sprite.scale(1.0f, 1.0f);
    /*
        Tis is used to write text in the tutorial
    */
	tuto[0].setString("You're now in the universe.\n"
                   "It's where you can land on a planet and explore the world.\n\n"
                   " - You can steer your ship by pressing\nthe directional arrows.\n\n"
                   " - If you are ready to land you can press return key.\n\n"
                   " - Press M to show universe's map\n\n\n"
                   "It is not good to stay too much in front of the dashboard\nso if you want to take a break press escape !\n"
                   "As you will see, there's interesting stuff in there.");
	tuto[0].setPosition(sf::Vector2f(815,5));

	tuto[1].setString("Here you are on a planet in the Aslorth system!\n"
                        "It is time to face the boss in front of you!\n\n"
                        "Destroy him with attacks by pressing A\n\n"
                        "Sometimes it is also essential to regenerate your life\n"
                        "in order to take back the fight by pressing R\n\n"
                        "Beat the different bosses to collect the badges\n"
                        "scattered throughout the universe and save Aslorth\n\n\n"
                        "Ready?");
	tuto[1].setPosition(sf::Vector2f(20,470));
	/*
        Allows to give a texture and position
    */
	continueKey.setFont(font);
	continueKey.setFillColor(sf::Color::Yellow);
	continueKey.setString("> Press space key to enter the universe <");
	continueKey.setPosition(sf::Vector2f(500,870));
	continueKey.setCharacterSize(20);
	continueKey.setStyle(sf::Text::Bold);
	/*
        This is used to define the font of the tutorial
	*/
	for(int i =0; i< 2; i++)
    {
        tuto[i].setFont(font);
        tuto[i].setCharacterSize(25);
        tuto[i].setFillColor(sf::Color::White);
    }
    //ctor
}
/*
    This is the destructor
*/
TutorialView::~TutorialView()
{
    //dtor
}
/*
    This is a function that draw the window
*/
void TutorialView::draw(Management& man,sf::RenderWindow &window)
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

		/*
            This for loop is used to draw the text in the window
		*/
		for(int i =0; i< 2; i++)
        {
            window.draw(tuto[i]);
        }

		window.display();
	}
}
