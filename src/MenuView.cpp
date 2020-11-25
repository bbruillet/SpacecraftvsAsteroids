#include "MenuView.h"

#include <iostream>
using std::cout;
using std::endl;


MenuView::MenuView()
{
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}

	if (!menu_texture.loadFromFile("Images/Backgrounds/Menu_Background.jpg"))
    {
        std::cout << "Problème" << std::endl;
    }
    menu_sprite.setTexture(menu_texture);
    menu_sprite.setPosition(0, 0);
    menu_sprite.scale(1.0f, 1.0f);



}

MenuView::~MenuView()
{
    //dtor
}
