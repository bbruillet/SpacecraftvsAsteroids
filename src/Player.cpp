#include "Player.h"

//Constructeur
Player::Player()
{
    //On charge la police
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}

	races[0].setFont(font);
	races[0].setFillColor(sf::Color(96, 59, 99));
	races[0].setString("> Humain");
	races[0].setPosition(sf::Vector2f(100,100));

	races[1].setFont(font);
	races[1].setFillColor(sf::Color::White);
	races[1].setString("> Valdera");
	races[1].setPosition(sf::Vector2f(100,250));

	races[2].setFont(font);
	races[2].setFillColor(sf::Color::White);
	races[2].setString("> Vanduul");
	races[2].setPosition(sf::Vector2f(100,400));

	races[3].setFont(font);
	races[3].setFillColor(sf::Color::White);
	races[3].setString("> Covenante");
	races[3].setPosition(sf::Vector2f(100,550));

	races[4].setFont(font);
	races[4].setFillColor(sf::Color::White);
	races[4].setString("> Aetwi");
	races[4].setPosition(sf::Vector2f(100,700));

    //boucle permettant de définir une taille de caractères pour les éléments
	for (int i = 0; i < MAX_NUMBER_OF_RACES; i++)
	{
		races[i].setCharacterSize(150);
	}

	selectedItemIndex = 0;

	//On chrage l'image
	if (!player_texture.loadFromFile("Images/Backgrounds/0_Race.png"))
    {
            std::cout << "Problem while loading race's picture" << std::endl;
    }
        player_sprite.setTexture(player_texture);
        player_sprite.setPosition(0, 0);
        player_sprite.scale(1.0f, 1.0f);

    //On charge l'image en fonction de l'élément sélectionné
    if (!character_texture.loadFromFile("Images/Avatars/"+to_string(selectedItemIndex)+"_Heros.png"))
    {
        std::cout << "Problème d'avatar" << std::endl;
    }

    character_sprite.setTexture(character_texture);
    character_sprite.setPosition(1125, 215);


    playerText.setFont(font);
    playerText.setCharacterSize(50);
    playerText.setFillColor(sf::Color(96, 59, 99));
    playerText.setPosition(sf::Vector2f(300,400));

    names[0].setFont(font);
	names[0].setFillColor(sf::Color(96, 59, 99));
	names[0].setString("> Veuillez entrer votre pseudo :");
	names[0].setPosition(sf::Vector2f(100,250));
    names[0].setCharacterSize(75);

	names[1].setFont(font);
	names[1].setFillColor(sf::Color(115,14,14));
	names[1].setString("> Attention le pseudo ne peut pas depasser 20 caracteres !");
	names[1].setPosition(sf::Vector2f(100,50));

	names[2].setFont(font);
	names[2].setFillColor(sf::Color(115,14,14));
	names[2].setString("> Attention le pseudo doit contenir au moins 3 caracteres!");
	names[2].setPosition(sf::Vector2f(100,0));

}

Player::~Player()
{
    //dtor
}

//Recuperer l'élément sélectionné
int Player::getPressedElement()
{
    return selectedItemIndex;
}

//Dessiner les avatars des races
void Player::draw(sf::RenderWindow &window)
{
    window.draw(player_sprite);
    window.draw(character_sprite);
	for (int i = 0; i < MAX_NUMBER_OF_RACES; i++)
	{
		window.draw(races[i]);
	}
}

//Méthode permettant de choisir son pseudo
void Player::pseudoPlayer(sf::RenderWindow &window)
{
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
                    if( (event.text.unicode >= 48 && event.text.unicode <=57) ||
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
        if(counter+1 < 3){
        window.draw(names[2]);
        }
        window.draw(playerText);
        window.display();
    }


}

//Naviguer au dessus
void Player::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		races[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		races[selectedItemIndex].setFillColor(sf::Color(96, 59, 99));
		if (!player_texture.loadFromFile("Images/Backgrounds/"+to_string(selectedItemIndex)+"_Race.png"))
        {
            std::cout << "Problème d'arrière plan" << std::endl;
        }

        if (!character_texture.loadFromFile("Images/Avatars/"+to_string(selectedItemIndex)+"_Heros.png"))
        {
            std::cout << "Problème d'avatar" << std::endl;
        }



        player_sprite.setTexture(player_texture);
        player_sprite.setPosition(0, 0);
        player_sprite.scale(1.0f, 1.0f);

        character_sprite.setTexture(character_texture);
        character_sprite.setPosition(1125, 215);

	}
}

//Naviguer en dessous
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


        if (!character_texture.loadFromFile("Images/Avatars/"+to_string(selectedItemIndex)+"_Heros.png"))
        {
            std::cout << "Problème d'avatar" << std::endl;
        }
        player_sprite.setTexture(player_texture);
        player_sprite.setPosition(0, 0);
        player_sprite.scale(1.0f, 1.0f);

        character_sprite.setTexture(character_texture);
        character_sprite.setPosition(1125, 215);
	}
}

//Constructeur de copie
Player::Player(const Player& other)
{
    //copy ctor
}

//Opérateur =
Player& Player::operator=(const Player& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

//Setter de pseudo
void Player::setPseudo(const string &pseudo)
{
    this->pseudo = pseudo;
}

//Getter de pseudo
string Player::getPseudo() const
{
    return pseudo;
}