#include "Compte.h"

//Constructeur
Compte::Compte()
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
	if (!compte_texture.loadFromFile("Images/Backgrounds/0_Race.png"))
    {
            std::cout << "Problème" << std::endl;
    }
        compte_sprite.setTexture(compte_texture);
        compte_sprite.setPosition(0, 0);
        compte_sprite.scale(1.0f, 1.0f);

    //On charge l'image en fonction de l'élément sélectionné
    if (!personnage_texture.loadFromFile("Images/Avatars/"+to_string(selectedItemIndex)+"_Heros.png"))
    {
        std::cout << "Problème d'avatar" << std::endl;
    }

    personnage_sprite.setTexture(personnage_texture);
    personnage_sprite.setPosition(1125, 215);


    playerText.setFont(font);
    playerText.setCharacterSize(50);
    playerText.setFillColor(sf::Color(96, 59, 99));
    playerText.setPosition(sf::Vector2f(300,400));

    noms[0].setFont(font);
	noms[0].setFillColor(sf::Color(96, 59, 99));
	noms[0].setString("> Veuillez entrer votre pseudo :");
	noms[0].setPosition(sf::Vector2f(100,250));
    noms[0].setCharacterSize(75);

	noms[1].setFont(font);
	noms[1].setFillColor(sf::Color(115,14,14));
	noms[1].setString("> Attention le pseudo ne peut pas depasser 20 caracteres !");
	noms[1].setPosition(sf::Vector2f(100,50));

	noms[2].setFont(font);
	noms[2].setFillColor(sf::Color(115,14,14));
	noms[2].setString("> Attention le pseudo doit contenir au moins 3 caracteres!");
	noms[2].setPosition(sf::Vector2f(100,0));

}

Compte::~Compte()
{
    //dtor
}

//Recuperer l'élément sélectionné
int Compte::getElementPresse()
{
    return selectedItemIndex;
}

//Dessiner les avatars des races
void Compte::dessiner(sf::RenderWindow &window)
{
    window.draw(compte_sprite);
    window.draw(personnage_sprite);
	for (int i = 0; i < MAX_NUMBER_OF_RACES; i++)
	{
		window.draw(races[i]);
	}
}

//Méthode permettant de choisir son pseudo
void Compte::PseudoUtilisateur(sf::RenderWindow &window)
{
    int compteur = -1;
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
//                    cout << to_string(compteur) << endl;
                    if(compteur+1 < 3){
                        window.draw(noms[2]);
                        cout << "non " << endl;

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
                    if(compteur >= 0){
                    playerInput.erase(compteur,1);
                    compteur--;
                    }
                }

                else if (compteur <= 20)
                {
                    if( (event.text.unicode >= 48 && event.text.unicode <=57) ||
                       (event.text.unicode >= 65 && event.text.unicode <=90) ||
                       (event.text.unicode >= 97 && event.text.unicode <=122) )
                    {
                    playerInput += event.text.unicode;
                    compteur++;
                    }


                }
                playerText.setString(playerInput);


            }
        }
        window.clear();
        window.draw(compte_sprite);
        window.draw(noms[0]);
        window.draw(noms[1]);
        if(compteur+1 < 3){
        window.draw(noms[2]);
        }
        window.draw(playerText);
        window.display();
    }


}

//Naviguer au dessus
void Compte::haut()
{
	if (selectedItemIndex - 1 >= 0)
	{
		races[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		races[selectedItemIndex].setFillColor(sf::Color(96, 59, 99));
		if (!compte_texture.loadFromFile("Images/Backgrounds/"+to_string(selectedItemIndex)+"_Race.png"))
        {
            std::cout << "Problème d'arrière plan" << std::endl;
        }

        if (!personnage_texture.loadFromFile("Images/Avatars/"+to_string(selectedItemIndex)+"_Heros.png"))
        {
            std::cout << "Problème d'avatar" << std::endl;
        }



        compte_sprite.setTexture(compte_texture);
        compte_sprite.setPosition(0, 0);
        compte_sprite.scale(1.0f, 1.0f);

        personnage_sprite.setTexture(personnage_texture);
        personnage_sprite.setPosition(1125, 215);

	}
}

//Naviguer en dessous
void Compte::bas()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_RACES)
	{
		races[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		races[selectedItemIndex].setFillColor(sf::Color(96, 59, 99));
		if (!compte_texture.loadFromFile("Images/Backgrounds/"+to_string(selectedItemIndex)+"_Race.png"))
        {
            std::cout << "Problème" << std::endl;
        }


        if (!personnage_texture.loadFromFile("Images/Avatars/"+to_string(selectedItemIndex)+"_Heros.png"))
        {
            std::cout << "Problème d'avatar" << std::endl;
        }
        compte_sprite.setTexture(compte_texture);
        compte_sprite.setPosition(0, 0);
        compte_sprite.scale(1.0f, 1.0f);

        personnage_sprite.setTexture(personnage_texture);
        personnage_sprite.setPosition(1125, 215);
	}
}

//Constructeur de copie
Compte::Compte(const Compte& other)
{
    //copy ctor
}

//Opérateur =
Compte& Compte::operator=(const Compte& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

//Setter de pseudo
void Compte::setPseudo(const string &pseudo)
{
    this->pseudo = pseudo;
}

//Getter de pseudo
string Compte::getPseudo() const
{
    return pseudo;
}
