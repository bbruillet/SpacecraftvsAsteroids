#pragma once
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3
#include "Management.h"

class Menu
{
public:
	Menu();

	~Menu();

	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int getPressedItem();
	void show(Management& man,sf::RenderWindow &window);



private:
	int selectedItemIndex;
	sf::Sprite menu_sprite;
    sf::Texture menu_texture;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};
