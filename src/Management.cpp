#include "Management.h"

#include <SFML/Graphics.hpp>

#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>
#include <cmath>

#include "StartScreenView.h"
#include "Menu.h"
#include "PauseMenu.h"
#include "Player.h"
#include "IncreaseStatsMenu.h"
#include "StoryView.h"
#include "TutorialView.h"
#include "MapSpaceView.h"
#include "CreditView.h"
#include "ScreenResultView.h"

Management::Management()
{

    this->universe = universe;
    this->spacecraft = spacecraft;
    vector <Planet*> planets(6);
    vector <Planet*> unreachPlanets(3);
    vector <CharacterBoss*> boss(6);
    planets[0] = new Planet("Bleue", "Images/Planetes/Bleu.png", 2000, 750, -30, 625); //319
    planets[1] = new Planet("Orange", "Images/Planetes/Orange.png", 9000, 1250, 120, 685); //291
    planets[2] = new Planet("Mauve_Detruite", "Images/Planetes/Mauve_Detruite.png", 7000, 5500, 30, 700); //417
    planets[3] = new Planet("Anneau_Rouge", "Images/Planetes/Anneau_Rouge.png", 11000, 3000, 310, 725); //1083
    planets[4] = new Planet("Verte", "Images/Planetes/Verte.png", 5000, 3200, 390, 700); //703
    planets[5] = new Planet("Anneau_Bleu", "Images/Planetes/Anneau_Bleu.png", 1500, 5100, 180, 715); //318

    unreachPlanets[0] = new Planet("Mort", "Images/Planetes/Etoile_De_La_Mort.png", 8000, 6120, 0, 0);
    unreachPlanets[1] = new Planet("Plateforme", "Images/Planetes/Plateforme.png", 6900, 3300, 0, 0);
    unreachPlanets[2] = new Planet("Soleil", "Images/Planetes/Soleil.png", 12000, 0, 0, 0);

    boss[0] = new CharacterBoss("Oblumandias",BLUE);
    boss[1] = new CharacterBoss("Mof Tarkin the great",ORANGE);
    boss[2] = new CharacterBoss("Denimos",PURPLE_DESTROYED);
    boss[3] = new CharacterBoss("Sanjitanas",RING_RED);
    boss[4] = new CharacterBoss("Grodzilla",GREEN);
    boss[5] = new CharacterBoss("Zanentia",RING_BLUE);

    for ( size_t i = 0; i < planets.size(); i++ )
    {
        for ( size_t j = 0; j < boss.size(); j++ )
        {
            if(boss[j]->getOrigin() == i){
                planets[i]->giveBoss(*boss[j]);
            }
        }
        universe.add(planets[i]);
    }

    for ( size_t i = 0; i < unreachPlanets.size(); i++ )
    {
        universe.addUnreachable(unreachPlanets[i]);
    }
    nbStory = 1;
}

Management::~Management()
{
    //dtor
}

sf::Texture Management::getVictory_texture() const
{
    return victory_texture;
}

sf::Sprite Management::getVictory_sprite() const
{
    return victory_sprite;
}

CharacterHero& Management::getCharHero()
{
    return this->hero;
}

Universe& Management::getUniverse()
{
    return this->universe;
}

Spacecraft& Management::getSpaceCraft()
{
    return this->spacecraft;
}

SpacecraftView& Management::getSpaceCraftView()
{
    return this->spacecraftView;
}

BiomePlanet& Management::getBiome()
{
    return this->biome;
}

CharacterView& Management::getCharacterView()
{
    return this->cView;
}

int Management::getNbStory()const
{
    return this->nbStory;
}

void Management::setNbStory(const int nbStory)
{
    this->nbStory = nbStory;
}

void Management::mainWindow()
{
    /*MUSIQUE*/
    sf::SoundBuffer Buffer;
    if (!Buffer.loadFromFile("Musiques/Musique_Menu.wav"))
    {
        cout << "Problem while loading the sound" <<endl;
    }
    sf::Sound sound;
    sound.setBuffer(Buffer);
    sound.setLoop(true);
    sound.play();

    sf::RenderWindow windowJeu(sf::VideoMode(1600, 900), "Space Fighter : The battle of Aslorth");

    sf::Image icon;
    if(!icon.loadFromFile("Images/Backgrounds/Icon.png"))
    {
        cout << "Failed to load icon" << endl;
    }

    windowJeu.setIcon(250,250,icon.getPixelsPtr());
    startScreen(windowJeu);
}

void Management::startScreen(sf::RenderWindow& windowJeu)
{
    StartScreenView start;
    start.show(*this,windowJeu);
}

void Management::menu(sf::RenderWindow & windowJeu)
{
	Menu menu;
	menu.show(*this,windowJeu);
}

void Management::pauseMenu(sf::RenderWindow & windowJeu)
{
	PauseMenu pause;
	pause.show(*this,windowJeu);
}

void Management::playerAccount(sf::RenderWindow & windowJeu)
{
    Player player;
    player.show(*this,windowJeu);
}

void Management::playerPseudo(sf::RenderWindow & windowJeu,int select)
{
    Player player;
    player.setPressedElement(select);
    player.pseudoPlayer(*this,windowJeu);
    hero.setName(player.getPseudo());
    spv.showStats(hero);
    cView.setCharacterHero(hero);
    story(windowJeu);
}

void Management::story(sf::RenderWindow & windowJeu)
{
    StoryView sView;
    if(nbStory == 1)
    {
        sView.introduction(*this, windowJeu);
    }
    else
    {
        setNbStory(0);
        hero.setBadge(0);
        for ( size_t i = 0; i < universe.planets.size(); i++ )
        {
                universe.planets[i]->getBoss()->setBadge(2);
        }
        sView.conclusion(*this, windowJeu);
    }
}

void Management::tuto(sf::RenderWindow & windowJeu)
{
    TutorialView tv;
    tv.draw(*this, windowJeu);
}

void Management::launch(sf::RenderWindow & windowJeu)
{
    MapSpaceView mapPlay;
    mapPlay.playMap(*this,windowJeu);
}

void Management::mapSpace(sf::RenderWindow & windowJeu)
{
    MapSpaceView mapView;
    mapView.showMap(*this,windowJeu);
}

void Management::drawBattle(sf::RenderWindow& windowJeu)
{

        biome.drawBiome(windowJeu);
        barHero.drawLife(windowJeu);
        barHero.drawShield(windowJeu);
        barBoss.drawLife(windowJeu);
        barBoss.drawShield(windowJeu);
        cView.drawHero(windowJeu);
        cView.drawBoss(windowJeu);
        windowJeu.draw(versus_sprite);
        windowJeu.draw(textHero);
        windowJeu.draw(textBoss);
        windowJeu.draw(textLifeHero);
        windowJeu.draw(textLifeBoss);
        windowJeu.draw(textShieldHero);
        windowJeu.draw(textShieldBoss);

}

void Management::initCombat(Planet &pla)
{
    //fonts
    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
    {
        cout << "Internal error" <<endl;
    }

    if (!fontFight.loadFromFile("Polices/SpaceCapitain.otf"))
    {
        cout << "Internal error" <<endl;
    }

    if (!versus_texture.loadFromFile("Images/Backgrounds/versus.png"))
    {
        std::cout << "Problème d'image du 'versus'" << std::endl;
    }
    //set sprite du versus
    versus_sprite.setTexture(versus_texture);
    versus_sprite.setPosition(775, -25);

    //Nom affiché pour
    textHero.setFont(fontFight);
    textBoss.setFont(fontFight);

    textHero.setFillColor(sf::Color::Yellow);
    textBoss.setFillColor(sf::Color::Yellow);

    textHero.setCharacterSize(30);
    textBoss.setCharacterSize(30);

    textHero.setPosition(400, 20);
    textBoss.setPosition(1150, 20);

    textHero.setString(cView.getCharacterHero().getName());
    textBoss.setString(pla.getBoss()->getName());
    //----------------------------------------
    //Attribue un personnageheros et boss pour les dessiner
    cView.setCharacterBoss(*pla.getBoss());
    cView.setCharacterHero(hero);

    //Permet de dessiner les barres de vie et de shield
    barHero.setMaxLife(hero.getPtsLife());
    barHero.setBarLifePosition(650,75);
    barHero.setBarShieldPosition(800,100);
    barHero.setMaxShield(hero.getShield());

    barBoss.setBarLifePosition(1400,75);
    barBoss.setMaxLife(pla.getBoss()->getPtsLife());
    barBoss.setBarShieldPosition(1250,100);
    barBoss.setMaxShield(pla.getBoss()->getShield());

    barHero.setRotation();

    barHero.updateLife(hero.getPtsLife());
    barHero.updateShield(hero.getShield());

    barBoss.updateLife(pla.getBoss()->getPtsLife());
    barBoss.updateShield(pla.getBoss()->getShield());

    //-------------------------
    //ecriture du move réalisé

    textAttackEvent.setFont(font);
    textAttackEvent.setFillColor(sf::Color(201,67,11));
    textAttackEvent.setCharacterSize(75);
    textAttackEvent.setPosition(10,225);

    // vie affichée sur les barres de vie et de shield

    textLifeHero.setFont(font);
    textLifeBoss.setFont(font);
    textShieldHero.setFont(font);
    textShieldBoss.setFont(font);

    textLifeHero.setFillColor(sf::Color(105, 0, 0));
    textLifeBoss.setFillColor(sf::Color(105, 0, 0));
    textShieldHero.setFillColor(sf::Color(0, 51, 102));
    textShieldBoss.setFillColor(sf::Color(0, 51, 102));

    textLifeHero.setCharacterSize(30);
    textLifeBoss.setCharacterSize(30);
    textShieldHero.setCharacterSize(17);
    textShieldBoss.setCharacterSize(17);

    textLifeHero.setPosition(837, 55);
    textLifeBoss.setPosition(1153, 55);
    textShieldHero.setPosition(860, 88);
    textShieldBoss.setPosition(1153, 88);

    textLifeHero.setStyle(sf::Text::Bold);
    textLifeBoss.setStyle(sf::Text::Bold);
    textShieldHero.setStyle(sf::Text::Bold);
    textShieldBoss.setStyle(sf::Text::Bold);

    textLifeHero.setString(to_string(hero.getPtsLife()));
    textLifeBoss.setString(to_string(pla.getBoss()->getPtsLife()));
    textShieldHero.setString(to_string(hero.getShield()));
    textShieldBoss.setString(to_string(pla.getBoss()->getShield()));

    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    //stock la vie et le shield pour pouvoir les remettre après le combat
    lifeHero = hero.getPtsLife();
    shieldHero = hero.getShield();

    //stock la vie et le shield d'un boss pour remettre après combat
    lifeBoss = pla.getBoss()->getPtsLife();
    shieldBoss = pla.getBoss()->getShield();

}

void Management::fightPlanet(sf::RenderWindow & windowJeu,Planet& pla)
{
    //VIEW fight
    sf::View view(sf::FloatRect(2048, 1024, 2048, 1024));
    view.setCenter(1024, 512);
    windowJeu.setView(view);

    //var
    //compteur pour step
    int nb = 0;
    //pas a faire pour arriver assez porche pour attaquer
    int step;
     //statut pour éviter de spam
    int statut = 0;
    //resutat du combat
    int result = 0;
    //type d'attaque
    int attackEvent = 0;
    //regen
    int nbRegen = 2;
    //pour changer les positionnement d'un sprite à l'aide d'un vector2f
    sf::Vector2f dimension(pla.getXChar(),pla.getYChar());
    sf::Vector2f dimensionBoss(pla.getBoss()->getX()-250,pla.getBoss()->getY());
    cView.positionCharacterHero(dimension.x, dimension.y);
    cView.positionAttackCharacterBoss(dimensionBoss.x, dimensionBoss.y);
    //initalise les barres de vie,de shield charge les images,..
    initCombat(pla);

    //Boucle du dessin
    while (windowJeu.isOpen())
    {
        sf::Event event;
        while (windowJeu.pollEvent(event))
        {
            //statut allow to push on A or on R to make a move for the battle
            if(statut == 0)
            {   //met le statut a 1 pour ne pas attaquer avant la fin du tour
                statut = 1;

                //si la vie des deux personnages est supérieure à 0 alors on peut jouer
                if(hero.getPtsLife() > 0 && pla.getBoss()->getPtsLife() > 0){

                    switch (event.type){
                    case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                        // A pour attaquer
                    case sf::Keyboard::A:

                        //-------------------------HEROS------------------------------//
                        // attack event stack the type of the move and an hero attack a boss
                        attackEvent = fight.attack(hero,*pla.getBoss());
                        // to show who's attacking
                        textAttackEvent.setString("Attack from " + hero.getName());
                            // this while allows us to go near the boss for the animation
                            while(dimension.x < pla.getBoss()->getX() -300)
                            {
                                //count how many time we need to go to be near the boss to fight
                                nb++;
                                // animation when hero need to walk until the boss
                                cView.forwardHero();
                                // change this var to go near the boss and set the position of the spite
                                dimension.x += 22;
                                cView.positionCharacterHero(dimension.x, dimension.y);

                                //display the scene of the battle
                                drawBattle(windowJeu);
                                windowJeu.draw(textAttackEvent);
                                windowJeu.display();
                                //sleep allow us to display our sprite every x seconds
                                sf::sleep(sf::milliseconds(5));
                            }

                            // We set the type of attack we use when whe fight the boss
                            if(attackEvent == 2)
                                textAttackEvent.setString(fight.eventAttack(attackEvent)+pla.getBoss()->getName());

                            else
                                textAttackEvent.setString(fight.eventAttack(attackEvent)+hero.getName());

                            for(size_t i(0);i<5;i++)
                            {
                                //animation when we fight the boss
                                cView.fightHero();
                                //display the scene of the battle
                                windowJeu.clear();
                                drawBattle(windowJeu);
                                windowJeu.draw(textAttackEvent);
                                windowJeu.display();
                                //sleep allow us to display our sprite every x seconds
                                sf::sleep(sf::milliseconds(600));
                            }

                            //update the life and the shield of the boss after hero's attack
                            barBoss.updateLife(pla.getBoss()->getPtsLife());
                            barBoss.updateShield(pla.getBoss()->getShield());
                            textLifeBoss.setString(to_string(pla.getBoss()->getPtsLife()));
                            textShieldBoss.setString(to_string(pla.getBoss()->getShield()));

                            for(int i(0);i<nb;i++)
                            {   //animation the hero go back at his position
                                cView.backwardHero();
                                dimension.x -= 22;
                                cView.positionCharacterHero(dimension.x, dimension.y);
                                //display scene of the battle
                                windowJeu.clear();
                                drawBattle(windowJeu);
                                windowJeu.display();
                                //sleep allow us to display our sprite every x seconds
                                sf::sleep(sf::milliseconds(5));
                            }
                            //we set our image of hero to his first form
                            cView.setRectHero(0);

                            /*------------------------BOSSS-----------------------------*/

                            // if the boss survive after the hero's attack
                            if(pla.getBoss()->getPtsLife() != 0)
                            {
                            //boss attacks hero and we stack the move in attackevent
                            attackEvent = fight.attack(*pla.getBoss(), hero);
                            //show boss attack
                            textAttackEvent.setString("Attack from " + pla.getBoss()->getName());

                                for(size_t i(0);i<5;i++)
                                {
                                    //animation when boss prepare is power ball to attack
                                    cView.fightBoss();
                                    //draw battle scene
                                    windowJeu.clear();
                                    drawBattle(windowJeu);
                                    windowJeu.draw(textAttackEvent);
                                    windowJeu.display();
                                    //sleep allow us to display our sprite every x seconds
                                    sf::sleep(sf::milliseconds(200));
                                }
                            // to display what type of attack boss do
                            if(attackEvent == 2)
                                textAttackEvent.setString(fight.eventAttack(attackEvent)+hero.getName());

                            else
                                textAttackEvent.setString(fight.eventAttack(attackEvent)+pla.getBoss()->getName());
                            // set the boss image to his inital position
                            cView.setRectBoss(0);

                            for(int i(0);i<nb;i++)
                            {
                                //sleep allow us to display our sprite every x seconds
                                sf::sleep(sf::milliseconds(5));
                                //animation of throwing is power ball
                                cView.throwingBoss();
                                // move the sprite of the power ball
                                dimensionBoss.x -= 22;
                                cView.positionAttackCharacterBoss(dimensionBoss.x, dimensionBoss.y);
                                //draw battle scene
                                windowJeu.clear();
                                drawBattle(windowJeu);
                                windowJeu.draw(textAttackEvent);
                                //draw power ball
                                cView.drawBoss2(windowJeu);
                                windowJeu.display();

                            }
                            //set the life and the shield of the hero after boss' attack
                            textLifeHero.setString(to_string(hero.getPtsLife()));
                            textShieldHero.setString(to_string(hero.getShield()));
                            barHero.updateLife(hero.getPtsLife());
                            barHero.updateShield(hero.getShield());

                            //put the ball at the good position for the next attack
                            dimensionBoss.x = pla.getBoss()->getX()-250;

                            // to know how many times we need to move to the boss to attack
                            step = nb;

                            nb = 0;
                            }
                break;

                //R to restaure LIFE
                case sf::Keyboard::R:
                    //to display that the hero regenerates his life
                    textAttackEvent.setString(hero.getName() + " regenerates his life by "+ to_string(hero.getRegeneration()) + " points");
                    // if the hero can regen
                    if(hero.getPtsLife()+hero.getRegeneration() <= lifeHero && nbRegen >0)
                    {
                        nbRegen--;
                        //regen life
                        fight.regenHero(hero, *pla.getBoss());
                        //update the life of the hero
                        barHero.updateLife(hero.getPtsLife());
                        textLifeHero.setString(to_string(hero.getPtsLife()));

                        for(size_t i(0);i<5;i++)
                        {
                            //set position of the regen
                            cView.positionRegen(pla.getXChar()-20, pla.getYChar()-30);

                            // to display the animation of regeneration
                            cView.regenCircles();

                            // draw fight scene
                            windowJeu.clear();
                            drawBattle(windowJeu);
                            windowJeu.draw(textAttackEvent);
                            cView.drawRegenCircles(windowJeu);
                            windowJeu.display();
                            sf::sleep(sf::milliseconds(600));
                        }
                        //boss attacks hero and we stack the move in attackevent
                        attackEvent = fight.attack(*pla.getBoss(), hero);
                        //show boss attack
                        textAttackEvent.setString("Attack from " + pla.getBoss()->getName());

                        for(size_t i(0);i<5;i++)
                        {
                          //animation when boss prepare is power ball to attack
                            cView.fightBoss();
                            //draw battle scene
                            windowJeu.clear();
                            drawBattle(windowJeu);
                            windowJeu.draw(textAttackEvent);
                            windowJeu.display();
                            //sleep allow us to display our sprite every x seconds
                            sf::sleep(sf::milliseconds(200));
                        }

                       // to display what type of attack boss do
                        if(attackEvent == 2)
                            textAttackEvent.setString(fight.eventAttack(attackEvent)+hero.getName());

                        else
                            textAttackEvent.setString(fight.eventAttack(attackEvent)+pla.getBoss()->getName());
                        // set the boss image to his inital position
                        cView.setRectBoss(0);

                        for(int i(0);i<step;i++)
                        {
                            sf::sleep(sf::milliseconds(5));
                            //throw is power ball
                            cView.throwingBoss();
                            //power ball move
                            dimensionBoss.x -= 22;
                            //set position of power ball
                            cView.positionAttackCharacterBoss(dimensionBoss.x, dimensionBoss.y);
                            //draw window fight
                            windowJeu.clear();
                            drawBattle(windowJeu);
                            windowJeu.draw(textAttackEvent);
                            //draw the power ball of the boss
                            cView.drawBoss2(windowJeu);
                            windowJeu.display();
                        }

                     //set the life and the shield of the hero after boss' attack
                    textLifeHero.setString(to_string(hero.getPtsLife()));
                    textShieldHero.setString(to_string(hero.getShield()));
                    barHero.updateLife(hero.getPtsLife());
                    barHero.updateShield(hero.getShield());

                    //put the ball at the good position for the next attack
                    dimensionBoss.x = pla.getBoss()->getX()-250;

                    //to know how many times we need to move to the boss to attack
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
        }
        else
        {   //if boss is down
            if(pla.getBoss()->getPtsLife() == 0){
                // victory
                result = 1;
                // we set back life and shield for hero and the boss
                hero.setPtsLife(lifeHero);
                hero.setShield(shieldHero);
                pla.getBoss()->setPtsLife(lifeBoss);
                pla.getBoss()->setShield(shieldBoss);
                //boss become stronger with resurrection
                pla.getBoss()->resurrection();
                //set counter of attck spe to 0 for next battle
                pla.getBoss()->setCounterSpe(0);
                //set number of regen to 2 after a battle
                fight.setNbRegen(2);
                // set counter of attck spe to 0 for next battle
                hero.setCounterSpe(0);
                //verify if boss has a badge to let
                if(pla.getBoss()->getBadge()>0){
                    // boss give his badge
                    pla.getBoss()->setBadge(pla.getBoss()->getBadge() -1);
                    //hero recover the badge
                    hero.setBadge(hero.getBadge() + 1);

                    if(hero.getBadge() == 12){
                        // if we complete the game with 12 badges, it is use to display the end screen
                        nbStory = 2;
                    }
                }
                // display screen result
                screenResult(result, windowJeu);
            }
            // if hero is down
            if(hero.getPtsLife() == 0)
            {
                // Lose
                result = 2;
                // we set back life and shield for hero and the boss
                hero.setPtsLife(lifeHero);
                hero.setShield(shieldHero);
                pla.getBoss()->setPtsLife(lifeBoss);
                pla.getBoss()->setShield(shieldBoss);

                //set counter of attck spe to 0 for next battle
                pla.getBoss()->setCounterSpe(0);
                //set number of regen to 2 after a battle
                fight.setNbRegen(2);
                // set counter of attck spe to 0 for next battle
                hero.setCounterSpe(0);

                //display result screen
                screenResult(result, windowJeu);
            }
        }

            if (event.type == sf::Event::Closed)
            {
            // if we close the game we get back to the space map
            launch(windowJeu);
            }
        }
        // draw fight scene
        windowJeu.clear();
        drawBattle(windowJeu);
        windowJeu.display();
        //ready to use a move again (Attack or regen)
        statut = 0;
    }
}

void Management::screenResult(int result, sf::RenderWindow& windowJeu)
{
    ScreenResultView resultV;
    resultV.showResult(*this,windowJeu,result);
}

void Management::increaseStats(sf::RenderWindow & windowJeu)
{
	IncreaseStatsMenu stats;

	while (windowJeu.isOpen())
	{
		sf::Event event;
		while (windowJeu.pollEvent(event))
		{
			switch (event.type)
			{
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Up:
                    stats.moveUp();
                    break;

                case sf::Keyboard::Down:
                    stats.moveDown();
                    break;

                case sf::Keyboard::Return:
                    switch(stats.getPressedItem())
                    {
                    case 0:
                        hero.setIncrease(new IncreaseLife);
                        break;

                    case 1:
                        hero.setIncrease(new IncreaseAttack);
                        break;

                    case 2:
                        hero.setIncrease(new IncreaseShield);

                        break;

                    case 3:
                        hero.setIncrease(new IncreaseRegeneration);

                        break;
                    default:
                        break;
                    }


                    hero.executeIncrease();
                    spv.showStats(hero);

                    cout << hero.str() << endl;
                    windowJeu.clear();
                    launch(windowJeu);
                    break;

                    default:
                    break;
                }
                break;
                case sf::Event::Closed:
                    windowJeu.close();

                default:
                break;

			}

		}

		windowJeu.clear();

		stats.draw(windowJeu);

		windowJeu.display();
	}
}


void Management::creditGame(sf::RenderWindow &window)
{
    CreditView credit;
    credit.showCredit(*this,window);
}

void Management::showStats(sf::RenderWindow &windowJeu)
{

    while (windowJeu.isOpen())
	{
		sf::Event event;
		while (windowJeu.pollEvent(event))
		{
		    switch (event.type)
			{
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Backspace:
                    pauseMenu(windowJeu);
                    break;
                    default:
                        break;
                }
                break;
                default:
                    break;
			}
		}
        windowJeu.clear();
        spv.draw(windowJeu);

        cView.drawBadges(windowJeu, 850, 400);
        windowJeu.display();
	}
}
