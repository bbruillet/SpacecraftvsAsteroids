#include "StatsPlayerView.h"

StatsPlayerView::StatsPlayerView()
{
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
	{
		cout << "Internal error" <<endl;
	}


	for (int i = 0; i < MAX_NUMBER_OF_SHOW_STATS; i++)
	{
	    stats[i].setFont(font);
	    stats[i].setFillColor(sf::Color::White);
		stats[i].setCharacterSize(25);
		stats[i].setStyle(sf::Text::Bold);
		stats[i].setPosition(sf::Vector2f(500,i*25));
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
	for (int i = 0; i < MAX_NUMBER_OF_SHOW_STATS; i++)
	{
		window.draw(stats[i]);
	}
}

void StatsPlayerView::showStats(CharacterHero& ch)
{
    stats[0].setString("Name\t" + ch.getName());
    stats[1].setString("Attack\t" + to_string(ch.getPtsAttack()));
	stats[2].setString("Life\t" + to_string(ch.getPtsLife()));
	stats[3].setString("Special attack\t" + to_string(ch.getPtsSpecialAttack()));
	stats[4].setString("Shield\t"  + to_string(ch.getShield()));
	stats[5].setString("Chances to make a critical hit\t" + to_string((int)ch.getCriticalHit()) + "%");
	stats[6].setString("Chance to dodge\t" + to_string((int)ch.getDodge()) + "%");
	stats[7].setString("Regeneration\t" + to_string(ch.getRegeneration()));
}
