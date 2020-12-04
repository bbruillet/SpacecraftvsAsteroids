#include "Player.h"

/*
    This is the constructor
*/
Player::Player()
{
    /*
        The font is loaded here
    */
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}

	/*
        These lines are used to store a color and some string in some text.
        It will be displayed in the window with 'draw()' function
    */
	races[0].setFillColor(sf::Color(96, 59, 99));
	races[0].setString("> Human");
	races[0].setPosition(sf::Vector2f(100,100));
	races[1].setFillColor(sf::Color::White);
	races[1].setString("> Valdera");
	races[1].setPosition(sf::Vector2f(100,250));
	races[2].setFillColor(sf::Color::White);
	races[2].setString("> Vanduul");
	races[2].setPosition(sf::Vector2f(100,400));
	races[3].setFillColor(sf::Color::White);
	races[3].setString("> Covenante");
	races[3].setPosition(sf::Vector2f(100,550));
	races[4].setFillColor(sf::Color::White);
	races[4].setString("> Aetwi");
	races[4].setPosition(sf::Vector2f(100,700));

	for (int i = 0; i < MAX_NUMBER_OF_RACES; i++)
	{
		races[i].setCharacterSize(150);
		races[i].setFont(font);
	}

	selectedItemIndex = 0;

	/*This is where background pictures of heroes are loaded*/
	if (!player_texture.loadFromFile("Images/Backgrounds/0_Race.png"))
    {
            std::cout << "Problem while loading race's picture" << std::endl;
    }
    player_sprite.setTexture(player_texture);
    player_sprite.setPosition(0, 0);
    player_sprite.scale(1.0f, 1.0f);

    /*This is where pictures of heroes (avatars) are loaded*/
    if (!character_texture.loadFromFile("Images/Avatars/"+to_string(selectedItemIndex)+"_Race.png"))
    {
        std::cout << "Problem while loading character" << std::endl;
    }

    character_sprite.setTexture(character_texture);
    character_sprite.setPosition(1000, 215);

    playerText.setFont(font);
    playerText.setCharacterSize(50);
    playerText.setFillColor(sf::Color(0, 0, 0));
    playerText.setPosition(sf::Vector2f(300,400));

    /*
        These lines are used to store a color and some string in some text.
        It will be displayed in the window with 'draw()' function
    */
    names[0].setFont(font);
	names[0].setFillColor(sf::Color(0, 0, 0));
	names[0].setString("> Veuillez entrer votre pseudo <");
	names[0].setPosition(sf::Vector2f(150,250));
    names[0].setCharacterSize(75);

	names[1].setFont(font);
	names[1].setFillColor(sf::Color(204,145,0));
	names[1].setString("> Attention le pseudo ne peut pas depasser 20 caracteres !");
	names[1].setPosition(sf::Vector2f(100,50));

	names[2].setFont(font);
	names[2].setFillColor(sf::Color(204,145,0));
	names[2].setString("> Attention le pseudo doit contenir au moins 3 caracteres !");
	names[2].setPosition(sf::Vector2f(100,0));

	/*----------------------------------------------*/
	/*
        These lines are used to store a color and some string in some text.
        It will be displayed in the window with 'draw()' function
    */
	stats[0].setString("Points d'attaque : ");
	stats[1].setString("Points de vie : ");
	stats[2].setString("Points d'attaque speciale : ");
	stats[3].setString("Points de bouclier : ");
	stats[4].setString("Chance de coups critique : ");
	stats[5].setString("Chance d'esquive : ");
	stats[6].setString("Points de regeneration : ");


	for (int i = 0; i < MAX_NUMBER_OF_STATS; i++)
	{
	    stats[i].setFillColor(sf::Color::White);
		stats[i].setCharacterSize(25);
		stats[i].setStyle(sf::Text::Bold);
		stats[i].setPosition(sf::Vector2f(500,i*25));
		stats[i].setFont(font);
		if(i>3)
        {
            stats[i].setPosition(sf::Vector2f(1000,(i%3)*25));
		}
	}
}

/*This is the destructor*/
Player::~Player()
{
    //dtor
}

/*This is where the pressed element will be recovered*/
int Player::getPressedElement()
{
    return selectedItemIndex;
}

void Player::setPressedElement(int selectedItemIndex)
{
    this->selectedItemIndex = selectedItemIndex;
}

/*This is where the sprite and text will be drawed*/
void Player::draw(sf::RenderWindow &window)
{
    window.draw(player_sprite);
    window.draw(character_sprite);
	for (int i = 0; i < MAX_NUMBER_OF_RACES; i++)
	{
		window.draw(races[i]);
	}

	for (int i = 0; i < MAX_NUMBER_OF_STATS; i++)
	{
		window.draw(stats[i]);
	}
}

//Méthode permettant de choisir son pseudo
void Player::pseudoPlayer(Management& man,sf::RenderWindow &window)
{
    if (!player_texture.loadFromFile("Images/Backgrounds/"+to_string(selectedItemIndex)+"_Race.png"))
        {
            std::cout << "Problem while loading background" << std::endl;
        }
        player_sprite.setTexture(player_texture);
        player_sprite.setPosition(0, 0);
        player_sprite.scale(1.0f, 1.0f);


    int counter = -1;
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
                case sf::Keyboard::Escape:
                    window.clear();
                    man.playerAccount(window);
                    break;
                case sf::Keyboard::Return:
                    setPseudo(playerInput);
                    if(counter+1 < 3){
                        window.draw(names[2]);

                    }
                    else{
                         return;
                    }

                break;
                default:
                    break;
                }
                break;
                default:
                    break;
			}

            if (event.type == sf::Event::TextEntered)
            {
                if(event.text.unicode == '\b'){
                    if(counter >= 0){
                    playerInput.erase(counter,1);
                    counter--;
                    }
                }

                else if (counter <= 20)
                {
                    if((event.text.unicode >= 48 && event.text.unicode <=57) ||
                       (event.text.unicode >= 65 && event.text.unicode <=90) ||
                       (event.text.unicode >= 97 && event.text.unicode <=122) )
                    {
                    playerInput += event.text.unicode;
                    counter++;
                    }


                }
                playerText.setString(playerInput);


            }
        }
        window.clear();
        window.draw(player_sprite);
        window.draw(names[0]);
        window.draw(names[1]);
        if(counter+1 < 3)
        {
            window.draw(names[2]);
        }
        window.draw(playerText);
        window.display();
    }


}

/*
    This is where the user will be allowed to move up in the menu
    The color of the text will be changed according to the choice
*/
void Player::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		races[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		races[selectedItemIndex].setFillColor(sf::Color(96, 59, 99));
		if (!player_texture.loadFromFile("Images/Backgrounds/"+to_string(selectedItemIndex)+"_Race.png"))
        {
            std::cout << "Problem while loading background" << std::endl;
        }

        if (!character_texture.loadFromFile("Images/Avatars/"+to_string(selectedItemIndex)+"_Race.png"))
        {
            std::cout << "Problem while loading character" << std::endl;
        }



        player_sprite.setTexture(player_texture);
        player_sprite.setPosition(0, 0);
        player_sprite.scale(1.0f, 1.0f);

        character_sprite.setTexture(character_texture);
        character_sprite.setPosition(1000, 215);

	}
}

/*
    This is where the user will be allowed to move down in the menu
    The color of the text will be changed according to the choice
*/
void Player::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_RACES)
	{
		races[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		races[selectedItemIndex].setFillColor(sf::Color(96, 59, 99));
		if (!player_texture.loadFromFile("Images/Backgrounds/"+to_string(selectedItemIndex)+"_Race.png"))
        {
            std::cout << "Problème" << std::endl;
        }


        if (!character_texture.loadFromFile("Images/Avatars/"+to_string(selectedItemIndex)+"_Race.png"))
        {
            std::cout << "Problème d'avatar" << std::endl;
        }
        player_sprite.setTexture(player_texture);
        player_sprite.setPosition(0, 0);
        player_sprite.scale(1.0f, 1.0f);

        character_sprite.setTexture(character_texture);
        character_sprite.setPosition(1000, 215);
	}
}

/*This is where a hero is associated to a user*/
void Player::getStats(CharacterHero& her)
{
    if(selectedItemIndex == 0)
        her.setRace(HUMAN);

    if(selectedItemIndex == 1)
        her.setRace(VALDERA);

    if(selectedItemIndex == 2)
        her.setRace(VANDUUL);

    if(selectedItemIndex == 3)
        her.setRace(COVENANTE);

    if(selectedItemIndex == 4)
    {
        her.setRace(AETWI);
    }

    /*You can see your stats when you choose your hero*/
	stats[0].setString("Points d'attaque : "+to_string(her.getPtsAttack()));
	stats[1].setString("Points de vie : "+to_string(her.getPtsLife()));
	stats[2].setString("Points d'attaque speciale : "+to_string(her.getPtsSpecialAttack()));
	stats[3].setString("Points de bouclier : "+to_string(her.getShield()));
	stats[4].setString("Chance de coups critique : "+to_string(her.getCriticalHit()));
	stats[5].setString("Chance d'esquive : "+to_string(her.getDodge()));
	stats[6].setString("Points de regen : "+to_string(her.getRegeneration()));
}


/*This is the copy constructor*/
Player::Player(const Player& other)
{
    //copy ctor
}

/*This is operator='s function*/
Player& Player::operator=(const Player& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/*This is the setter of the pseudo*/
void Player::setPseudo(const string &pseudo)
{
    this->pseudo = pseudo;
}

/*This is the getter of the pseudo*/
string Player::getPseudo() const
{
    return pseudo;
}

/*
    This function is used to navigate in the menu with (key up and key down). Management class is used in !
*/
void Player::show(Management& man,sf::RenderWindow& window)
{
    getStats(man.getCharHero());
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                window.clear();
                man.menu(window);

            }
			switch (event.type)
			{
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    moveUp();
                    getStats(man.getCharHero());
                    break;

                case sf::Keyboard::Down:
                    moveDown();
                    getStats(man.getCharHero());
                    break;

                case sf::Keyboard::Return:
                    switch(getPressedElement())
                    {
                    case 0:
                        man.getCharHero().setRace(HUMAN);

                        break;

                    case 1:
                        man.getCharHero().setRace(VALDERA);
                        break;

                    case 2:
                        man.getCharHero().setRace(VANDUUL);
                       break;

                    case 3:
                        man.getCharHero().setRace(COVENANTE);
                       break;

                    case 4:
                        man.getCharHero().setRace(AETWI);
                        break;
                        default:
                        break;
                    }


                    man.playerPseudo(window,getPressedElement());

                    break;

                    window.clear();
                    default:
                    break;
                }
                break;
                case sf::Event::Closed:

                    window.close();


                default:
                break;

			}

		}

		window.clear();

		draw(window);

		window.display();
	}
}
