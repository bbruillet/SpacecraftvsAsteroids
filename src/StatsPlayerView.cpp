#include "StatsPlayerView.h"

StatsPlayerView::StatsPlayerView()
{
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}

	stats[0].setFont(font);
	stats[0].setString("Points d'attaque : ");

	stats[1].setFont(font);
	stats[1].setString("Points de vie : ");

	stats[2].setFont(font);
	stats[2].setString("Points d'attaque speciale : ");

	stats[3].setFont(font);
	stats[3].setString("Points de bouclier : ");

	stats[4].setFont(font);
	stats[4].setString("Chance de coups critique : ");

	stats[5].setFont(font);
	stats[5].setString("Chance d'esquive : ");

	stats[6].setFont(font);
	stats[6].setString("Points de regeneration : ");


	for (int i = 0; i < MAX_NUMBER_OF_STATS; i++)
	{
	    stats[i].setFillColor(sf::Color::White);
		stats[i].setCharacterSize(25);
		stats[i].setStyle(sf::Text::Bold);
		stats[i].setPosition(sf::Vector2f(500,i*25));
		if(i>3)
        {
            stats[i].setPosition(sf::Vector2f(1000,(i%3)*25));
		}

		//0 25 50 75        --
	}
    //ctor
}

StatsPlayerView::~StatsPlayerView()
{
    //dtor
}

StatsPlayerView::StatsPlayerView(const StatsPlayerView& other)
{
    //copy ctor
}

StatsPlayerView& StatsPlayerView::operator=(const StatsPlayerView& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void StatsPlayerView::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_STATS; i++)
	{
		window.draw(stats[i]);
	}
}
