#include "StatsPlayerView.h"

/*
    This is the constructor
*/
StatsPlayerView::StatsPlayerView()
{
    /*The font is loaded here*/
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}

    /*The title of the view is "created" here*/
	title.setFont(font);
	title.setFillColor(sf::Color::White);
    title.setCharacterSize(75);
    title.setString("Statistics");
    title.setStyle(sf::Text::Bold);
    title.setPosition(sf::Vector2f(550,25));

    /*The back sentence of the view is "created" here*/
	backKey.setFont(font);
	backKey.setFillColor(sf::Color::White);
    backKey.setCharacterSize(20);
    backKey.setString("< Press backspace key to get bak to pause menu >");
    backKey.setStyle(sf::Text::Bold);
    backKey.setPosition(sf::Vector2f(500,870));


	for (int i = 0; i < MAX_NUMBER_OF_SHOW_STATS; i++)
	{
	    stats[i].setFont(font);
	    stats[i].setFillColor(sf::Color::White);
		stats[i].setCharacterSize(35);
		stats[i].setStyle(sf::Text::Bold);
		stats[i].setPosition(sf::Vector2f(50,200+i*60));
	}
}

/*
    This is the destructor
*/
StatsPlayerView::~StatsPlayerView()
{
    //dtor
}

/*
    This is the copy constructor
*/
StatsPlayerView::StatsPlayerView(const StatsPlayerView& other)
{
    //copy ctor
}

/*
    This is operator='s function
*/
StatsPlayerView& StatsPlayerView::operator=(const StatsPlayerView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

/*This is where sprites and texts will be drawed*/
void StatsPlayerView::draw(sf::RenderWindow &window)
{
    window.draw(player_sprite);
    window.draw(character_sprite);
    window.draw(title);
    window.draw(backKey);
	for (int i = 0; i < MAX_NUMBER_OF_SHOW_STATS; i++)
	{
		window.draw(stats[i]);
	}
}

/*
    This function is used to show background, characters, badges to the user
*/
void StatsPlayerView::showStats(CharacterHero& ch)
{
    if (!player_texture.loadFromFile("Images/Backgrounds/"+to_string(ch.getRace())+"_Race.png"))
    {
            std::cout << "Problème" << std::endl;
    }

    player_sprite.setTexture(player_texture);
    player_sprite.setPosition(0, 0);
    //player_sprite.scale(1.0f, 1.0f);

    if (!character_texture.loadFromFile("Images/Avatars/"+to_string(ch.getRace())+"_Race.png"))
    {
            std::cout << "Problème d'avatar" << std::endl;
    }

    character_sprite.setTexture(character_texture);
    character_sprite.setPosition(1000, 50);

    stats[0].setString("Name :\t" + ch.getName());
    stats[1].setString("Attack:\t" + to_string(ch.getPtsAttack()));
	stats[2].setString("Life :\t" + to_string(ch.getPtsLife()));
	stats[3].setString("Special attack :\t" + to_string(ch.getPtsSpecialAttack()));
	stats[4].setString("Shield :\t"  + to_string(ch.getShield()));
	stats[5].setString("Chances to make a critical hit :\t" + to_string((int)ch.getCriticalHit()) + "%");
	stats[6].setString("Chance to dodge :\t" + to_string((int)ch.getDodge()) + "%");
	stats[7].setString("Regeneration :\t" + to_string(ch.getRegeneration()));
}
