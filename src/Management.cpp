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


/*
    This is the constructor
*/
Management::Management()
{
    universe = new Universe();
    spacecraft = new Spacecraft();
    spacecraftView = new SpacecraftView();
    hero = new CharacterHero();
    biome = new BiomePlanet();
    cView = new CharacterView();
    barHero = new BarView();
    barBoss = new BarView();
    fight = new Fight();
    spv = new StatsPlayerView;
    windowGame = new sf::RenderWindow(sf::VideoMode(1600, 900), "Space Fighter : The battle of Aslorth");

    /*This is our vectors*/
    vector <Planet*> planets(6);
    vector <Planet*> unreachPlanets(3);
    vector <CharacterBoss*> boss(6);

    /*Planets are created here*/
    planets[0] = new Planet("Bleue", "Images/Planetes/Bleu.png", 2000, 750, -30, 625); //319
    planets[1] = new Planet("Orange", "Images/Planetes/Orange.png", 9000, 1250, 120, 685); //291
    planets[2] = new Planet("Mauve_Detruite", "Images/Planetes/Mauve_Detruite.png", 7000, 5500, 30, 700); //417
    planets[3] = new Planet("Anneau_Rouge", "Images/Planetes/Anneau_Rouge.png", 11000, 3000, 310, 725); //1083
    planets[4] = new Planet("Verte", "Images/Planetes/Verte.png", 5000, 3200, 390, 700); //703
    planets[5] = new Planet("Anneau_Bleu", "Images/Planetes/Anneau_Bleu.png", 1500, 5100, 180, 715); //318

    /*Planets unreachables are created here*/
    unreachPlanets[0] = new Planet("Mort", "Images/Planetes/Etoile_De_La_Mort.png", 8000, 6120, 0, 0);
    unreachPlanets[1] = new Planet("Plateforme", "Images/Planetes/Plateforme.png", 6900, 3300, 0, 0);
    unreachPlanets[2] = new Planet("Soleil", "Images/Planetes/Soleil.png", 12000, 0, 0, 0);

    /*Bosses are created here*/
    boss[0] = new CharacterBoss("Oblumandias",BLUE);
    boss[1] = new CharacterBoss("Mof Tarkin the great",ORANGE);
    boss[2] = new CharacterBoss("Denimos",PURPLE_DESTROYED);
    boss[3] = new CharacterBoss("Sanjitanas",RING_RED);
    boss[4] = new CharacterBoss("Grodzilla",GREEN);
    boss[5] = new CharacterBoss("Zanentia",RING_BLUE);

    /*Planets are added in this loop*/
    for ( size_t i = 0; i < planets.size(); i++ )
    {
        for ( size_t j = 0; j < boss.size(); j++ )
        {
            /*Bosses are associated to planets in this loop*/
            if(boss[j]->getOrigin() == i){
                planets[i]->giveBoss(*boss[j]);
            }
        }
        universe->add(planets[i]);
    }

    /*Unreachable planets are added in the universe here*/
    for ( size_t i = 0; i < unreachPlanets.size(); i++ )
    {
        universe->addUnreachable(unreachPlanets[i]);
    }
    nbStory = 1;
}

/*This is the detructor*/
Management::~Management()
{
    //dtor
    delete spacecraft;
    delete hero;
    delete barHero;
    delete barBoss;
    delete fight;
    delete spv;
    delete windowGame;
}

/*This is the getter of victory's texture --> Background*/
sf::Texture Management::getVictory_texture() const
{
    return victory_texture;
}

/*This is the getter of victory's sprite --> Background*/
sf::Sprite Management::getVictory_sprite() const
{
    return victory_sprite;
}

/*This is the setter of victory's sprite --> Background*/
void Management::setSpriteVictory()
{
        victory_sprite.setTexture(victory_texture);
        victory_sprite.setPosition(0, 0);
        victory_sprite.scale(1.0f, 1.0f);
}

/*This is the setter of loss' texture --> Background*/
void Management::setLoseTexture()
{
    if (!victory_texture.loadFromFile("Images/Backgrounds/Loss.png"))
    {
        std::cout << "Problem for loading background" << std::endl;
    }
}

/*This is the setter of victory's texture --> Background*/
void Management::setVictoryTexture()
{
    if (!victory_texture.loadFromFile("Images/Backgrounds/Victory.png"))
    {
        std::cout << "Problem for loading background" << std::endl;
    }
}

/*This is the getter of the character*/
CharacterHero& Management::getCharHero()
{
    return *hero;
}

/*This is the getter of the universe*/
Universe& Management::getUniverse()
{
    return *universe;
}

/*This is the getter of the spacecraft*/
Spacecraft& Management::getSpaceCraft()
{
    return *spacecraft;
}

/*This is the getter of the spacecraftView*/
SpacecraftView& Management::getSpaceCraftView()
{
    return *spacecraftView;
}

/*This is the getter of the biome*/
BiomePlanet& Management::getBiome()
{
    return *biome;
}

/*This is the getter of the characterView*/
CharacterView& Management::getCharacterView()
{
    return *cView;
}

/*This is the getter of nbStory*/
int Management::getNbStory()const
{
    return this->nbStory;
}

/*This is the setter of nbStory*/
void Management::setNbStory(const int nbStory)
{
    this->nbStory = nbStory;
}

/*
    This is the main window
    This is where the window is openned
*/
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

    sf::Image icon;
    if(!icon.loadFromFile("Images/Backgrounds/Icon.png"))
    {
        cout << "Failed to load icon" << endl;
    }

    /*Setting an icon to the game*/
    windowGame->setIcon(250,250,icon.getPixelsPtr());
    startScreen();
}

/*It's the first screen of the game*/
void Management::startScreen()
{
    StartScreenView start;
    start.show(*this,*windowGame);
}

/*It's the main menu of the game*/
void Management::menu()
{
	Menu menu;
	menu.show(*this,*windowGame);
}

/*It's the pause menu*/
void Management::pauseMenu()
{
	PauseMenu pause;
	pause.show(*this,*windowGame);
}

/*It's the menu where the user will choose his race*/
void Management::playerAccount()
{
    Player player;
    player.show(*this,*windowGame);
}

/*It's the menu where the user will choose his nickname*/
void Management::playerPseudo(int select)
{
    Player player;
    player.setPressedElement(select);
    player.pseudoPlayer(*this,*windowGame);
    hero->setName(player.getPseudo());
    spv->showStats(*hero);
    cView->setCharacterHero(*hero);
    story();
}

/*It's the menu where the story is writed in*/
void Management::story()
{
    StoryView sView;
    /*If this condition is at 1, introduction is showed*/
    if(nbStory == 1)
    {
        sView.introduction(*this,*windowGame);
    }
    /*If this condition is at 2, Conclusion is showed*/
    else
    {
        setNbStory(0);
        hero->setBadge(0);
        for ( int i = 0; i < universe->getSizePlanets(); i++ )
        {
            universe->getPlanet(i)->getBoss()->setBadge(2);
        }
        sView.conclusion(*this,*windowGame);
    }
}

/*It's the tutorial menu*/
void Management::tuto()
{
    TutorialView tv;
    tv.draw(*this,*windowGame);
}

/*It's the window where the user can travel int the universe*/
void Management::launch()
{
    MapSpaceView mapPlay;
    mapPlay.playMap(*this,*windowGame);
}

/*it's the menu where the user can check the map*/
void Management::mapSpace()
{
    MapSpaceView mapView;
    mapView.showMap(*this,*windowGame);
}

/*It's the menu that draw the biome of the fight and all these composants*/
void Management::drawBattle()
{
        biome->drawBiome(*windowGame);
        barHero->drawLife(*windowGame);
        barHero->drawShield(*windowGame);
        barBoss->drawLife(*windowGame);
        barBoss->drawShield(*windowGame);
        cView->drawHero(*windowGame);
        cView->drawBoss(*windowGame);
        windowGame->draw(versus_sprite);
        windowGame->draw(textHero);
        windowGame->draw(textBoss);
        windowGame->draw(textLifeHero);
        windowGame->draw(textLifeBoss);
        windowGame->draw(textShieldHero);
        windowGame->draw(textShieldBoss);
}

/*This is a function used for fighting*/
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
    //set sprite of versus
    versus_sprite.setTexture(versus_texture);
    versus_sprite.setPosition(775, -25);

    //Nicknames of hero and boss
    textHero.setFont(fontFight);
    textBoss.setFont(fontFight);

    textHero.setFillColor(sf::Color::Yellow);
    textBoss.setFillColor(sf::Color::Yellow);

    textHero.setCharacterSize(30);
    textBoss.setCharacterSize(30);

    textHero.setPosition(400, 20);
    textBoss.setPosition(1150, 20);

    textHero.setString(cView->getCharacterHero().getName());
    textBoss.setString(pla.getBoss()->getName());
    //----------------------------------------
    //give a boos to be drawn
    cView->setCharacterBoss(*pla.getBoss());
    cView->setCharacterHero(*hero);

    //Allow to draw frames of life and shield
    barHero->setMaxLife(hero->getPtsLife());
    barHero->setBarLifePosition(650,75);
    barHero->setBarShieldPosition(800,100);
    barHero->setMaxShield(hero->getShield());

    barBoss->setBarLifePosition(1400,75);
    barBoss->setMaxLife(pla.getBoss()->getPtsLife());
    barBoss->setBarShieldPosition(1250,100);
    barBoss->setMaxShield(pla.getBoss()->getShield());

    barHero->setRotation();

    barHero->updateLife(hero->getPtsLife());
    barHero->updateShield(hero->getShield());

    barBoss->updateLife(pla.getBoss()->getPtsLife());
    barBoss->updateShield(pla.getBoss()->getShield());

    //-------------------------
    //It's where the action is described
    textAttackEvent.setFont(font);
    textAttackEvent.setFillColor(sf::Color(201,67,11));
    textAttackEvent.setCharacterSize(75);
    textAttackEvent.setPosition(10,225);

    // life displayed on frame's life and shield
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
    textShieldHero.setPosition(865, 88);
    textShieldBoss.setPosition(1153, 88);

    textLifeHero.setStyle(sf::Text::Bold);
    textLifeBoss.setStyle(sf::Text::Bold);
    textShieldHero.setStyle(sf::Text::Bold);
    textShieldBoss.setStyle(sf::Text::Bold);

    textLifeHero.setString(to_string(hero->getPtsLife()));
    textLifeBoss.setString(to_string(pla.getBoss()->getPtsLife()));
    textShieldHero.setString(to_string(hero->getShield()));
    textShieldBoss.setString(to_string(pla.getBoss()->getShield()));

    /*++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    //stock the life and the shield to be able to put them back after the fight
    lifeHero = hero->getPtsLife();
    shieldHero = hero->getShield();

    //stock the life and shield of a boss to put back after combat
    lifeBoss = pla.getBoss()->getPtsLife();
    shieldBoss = pla.getBoss()->getShield();

}

/*This is the function where de fight is performed*/
void Management::fightPlanet(Planet& pla)
{
    //VIEW fight
    sf::View view(sf::FloatRect(2048, 1024, 2048, 1024));
    view.setCenter(1024, 512);
    windowGame->setView(view);

    //var
    //counter for step
    int nb = 0;
    //step to do to be near to the boss
    int step = 0;
    //it's to avoid spam of A and R
    int statut = 0;
    //Result of the fight
    int result = 0;
    //Attack type ? Dodge, special attack, ...
    int attackEvent = 0;
    //regen counter
    int nbRegen = 2;
    //Changing position of a sprite with vector 2f
    sf::Vector2f dimension(pla.getXChar(),pla.getYChar());
    sf::Vector2f dimensionBoss(pla.getBoss()->getX()-250,pla.getBoss()->getY());
    cView->positionCharacterHero(dimension.x, dimension.y);
    cView->positionAttackCharacterBoss(dimensionBoss.x, dimensionBoss.y);
    //Initialize everything
    initCombat(pla);

    //Loop for drawing
    while (windowGame->isOpen())
    {
        sf::Event event;
        while (windowGame->pollEvent(event))
        {
            //statut allow to push on A or on R to make a move for the battle
            if(statut == 0)
            {
                //Put statut at 1 to devoid spam
                statut = 1;

                //If life of hero AND Boss is > 0, the game is on
                if(hero->getPtsLife() > 0 && pla.getBoss()->getPtsLife() > 0){

                    switch (event.type){
                    case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                    //Press A to attack
                    case sf::Keyboard::A:

                        //-------------------------HERO------------------------------//
                        // attack event stack the type of the move and an hero attack a boss
                        attackEvent = fight->attack(*hero,*pla.getBoss());
                        // to show who's attacking
                        textAttackEvent.setString("Attack from " + hero->getName());
                            // this while allows us to go near the boss for the animation
                            while(dimension.x < pla.getBoss()->getX() -300)
                            {
                                //count how many time we need to go to be near the boss to fight
                                nb++;
                                // animation when hero need to walk until the boss
                                cView->forwardHero();
                                // change this var to go near the boss and set the position of the spite
                                dimension.x += 35;
                                cView->positionCharacterHero(dimension.x, dimension.y);

                                //display the scene of the battle
                                drawBattle();
                                windowGame->draw(textAttackEvent);
                                windowGame->display();
                                //sleep allow us to display our sprite every x seconds
                                sf::sleep(sf::milliseconds(5));
                            }

                            // We set the type of attack we use when whe fight the boss
                            if(attackEvent == 2)
                                textAttackEvent.setString(fight->eventAttack(attackEvent)+pla.getBoss()->getName());

                            else
                                textAttackEvent.setString(fight->eventAttack(attackEvent)+hero->getName());

                            for(size_t i(0);i<5;i++)
                            {
                                //animate when we fight the boss
                                cView->fightHero();
                                //display the scene of the battle
                                windowGame->clear();
                                drawBattle();
                                windowGame->draw(textAttackEvent);
                                windowGame->display();
                                //sleep allow us to display our sprite every x seconds
                                sf::sleep(sf::milliseconds(400));
                            }

                            //update the life and the shield of the boss after hero's attack
                            barBoss->updateLife(pla.getBoss()->getPtsLife());
                            barBoss->updateShield(pla.getBoss()->getShield());
                            textLifeBoss.setString(to_string(pla.getBoss()->getPtsLife()));
                            textShieldBoss.setString(to_string(pla.getBoss()->getShield()));

                            for(int i(0);i<nb;i++)
                            {
                                //animate the hero go back at his position
                                cView->backwardHero();
                                dimension.x -= 35;
                                cView->positionCharacterHero(dimension.x, dimension.y);
                                //display scene of the battle
                                windowGame->clear();
                                drawBattle();
                                windowGame->display();
                                //sleep allow us to display our sprite every x seconds
                                sf::sleep(sf::milliseconds(5));
                            }
                            //we set our image of hero to his first form
                            cView->setRectHero(0);

                            /*------------------------BOSSS-----------------------------*/

                            // if the boss survive after the hero's attack
                            if(pla.getBoss()->getPtsLife() != 0)
                            {
                            //boss attacks hero and we stack the move in attackevent
                            attackEvent = fight->attack(*pla.getBoss(), *hero);
                            //show boss attack
                            textAttackEvent.setString("Attack from " + pla.getBoss()->getName());

                                for(size_t i(0);i<5;i++)
                                {
                                    //animation when boss prepare is power ball to attack
                                    cView->fightBoss();
                                    //draw battle scene
                                    windowGame->clear();
                                    drawBattle();
                                    windowGame->draw(textAttackEvent);
                                    windowGame->display();
                                    //sleep allow us to display our sprite every x seconds
                                    sf::sleep(sf::milliseconds(200));
                                }
                            // to display what type of attack boss do
                            if(attackEvent == 2)
                                textAttackEvent.setString(fight->eventAttack(attackEvent)+hero->getName());

                            else
                                textAttackEvent.setString(fight->eventAttack(attackEvent)+pla.getBoss()->getName());
                            // set the boss image to his inital position
                            cView->setRectBoss(0);

                            for(int i(0);i<nb;i++)
                            {
                                //sleep allow us to display our sprite every x seconds
                                sf::sleep(sf::milliseconds(5));
                                //animation of throwing is power ball
                                cView->throwingBoss();
                                // move the sprite of the power ball
                                dimensionBoss.x -= 35;
                                cView->positionAttackCharacterBoss(dimensionBoss.x, dimensionBoss.y);
                                //draw battle scene
                                windowGame->clear();
                                drawBattle();
                                windowGame->draw(textAttackEvent);
                                //draw power ball
                                cView->drawBoss2(*windowGame);
                                windowGame->display();

                            }
                            //set the life and the shield of the hero after boss' attack
                            textLifeHero.setString(to_string(hero->getPtsLife()));
                            textShieldHero.setString(to_string(hero->getShield()));
                            barHero->updateLife(hero->getPtsLife());
                            barHero->updateShield(hero->getShield());

                            //put the ball at the good position for the next attack
                            dimensionBoss.x = pla.getBoss()->getX()-250;

                            // to know how many times we need to move to the boss to attack
                            step = nb;

                            nb = 0;
                            }
                break;

                //press R to restore LIFE
                case sf::Keyboard::R:
                    //to display that the hero regenerates his life
                    textAttackEvent.setString(hero->getName() + " regenerates his life by "+ to_string(hero->getRegeneration()) + " points");
                    // if the hero can regen
                    if(hero->getPtsLife()+hero->getRegeneration() <= lifeHero && nbRegen >0)
                    {
                        nbRegen--;
                        //regen life
                        fight->regenHero(*hero);
                        //update the life of the hero
                        barHero->updateLife(hero->getPtsLife());
                        textLifeHero.setString(to_string(hero->getPtsLife()));

                        for(size_t i(0);i<5;i++)
                        {
                            //set position of the regen
                            cView->positionRegen(pla.getXChar()-20, pla.getYChar()-30);

                            // to display the animation of regeneration
                            cView->regenCircles();

                            // draw fight scene
                            windowGame->clear();
                            drawBattle();
                            windowGame->draw(textAttackEvent);
                            cView->drawRegenCircles(*windowGame);
                            windowGame->display();
                            sf::sleep(sf::milliseconds(600));
                        }
                        //boss attacks hero and we stack the move in attackevent
                        attackEvent = fight->attack(*pla.getBoss(), *hero);
                        //show boss attack
                        textAttackEvent.setString("Attack from " + pla.getBoss()->getName());

                        for(size_t i(0);i<5;i++)
                        {
                          //animation when boss prepare is power ball to attack
                            cView->fightBoss();
                            //draw battle scene
                            windowGame->clear();
                            drawBattle();
                            windowGame->draw(textAttackEvent);
                            windowGame->display();
                            //sleep allow us to display our sprite every x seconds
                            sf::sleep(sf::milliseconds(200));
                        }

                       // to display what type of attack boss do
                        if(attackEvent == 2)
                            textAttackEvent.setString(fight->eventAttack(attackEvent)+hero->getName());

                        else
                            textAttackEvent.setString(fight->eventAttack(attackEvent)+pla.getBoss()->getName());
                        // set the boss image to his inital position
                        cView->setRectBoss(0);

                        for(int i(0);i<step;i++)
                        {
                            sf::sleep(sf::milliseconds(5));
                            //throw is power ball
                            cView->throwingBoss();
                            //power ball move
                            dimensionBoss.x -= 35;
                            //set position of power ball
                            cView->positionAttackCharacterBoss(dimensionBoss.x, dimensionBoss.y);
                            //draw window fight
                            windowGame->clear();
                            drawBattle();
                            windowGame->draw(textAttackEvent);
                            //draw the power ball of the boss
                            cView->drawBoss2(*windowGame);
                            windowGame->display();
                        }

                     //set the life and the shield of the hero after boss' attack
                    textLifeHero.setString(to_string(hero->getPtsLife()));
                    textShieldHero.setString(to_string(hero->getShield()));
                    barHero->updateLife(hero->getPtsLife());
                    barHero->updateShield(hero->getShield());

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
                hero->setPtsLife(lifeHero);
                hero->setShield(shieldHero);
                pla.getBoss()->setPtsLife(lifeBoss);
                pla.getBoss()->setShield(shieldBoss);
                //boss become stronger with resurrection
                pla.getBoss()->resurrection();
                //set counter of attck spe to 0 for next battle
                pla.getBoss()->setCounterSpe(0);

                // set counter of attck spe to 0 for next battle
                hero->setCounterSpe(0);
                //verify if boss has a badge to let
                if(pla.getBoss()->getBadge()>0){
                    // boss give his badge
                    pla.getBoss()->setBadge(pla.getBoss()->getBadge() -1);
                    //hero recover the badge
                    hero->setBadge(hero->getBadge() + 1);

                    if(hero->getBadge() == 12){
                        // if we complete the game with 12 badges, it is use to display the end screen
                        nbStory = 2;
                    }
                }
                // display screen result
                screenResult(result);
            }
            // if hero is down
            if(hero->getPtsLife() == 0)
            {
                // Lose
                result = 2;
                // we set back life and shield for hero and the boss
                hero->setPtsLife(lifeHero);
                hero->setShield(shieldHero);
                pla.getBoss()->setPtsLife(lifeBoss);
                pla.getBoss()->setShield(shieldBoss);

                //set counter of attck spe to 0 for next battle
                pla.getBoss()->setCounterSpe(0);

                // set counter of attck spe to 0 for next battle
                hero->setCounterSpe(0);

                //display result screen
                screenResult(result);
            }
        }

            if (event.type == sf::Event::Closed)
            {
            // if we close the game we get back to the space map
            windowGame->close();

            }
        }
        // draw fight scene
        windowGame->clear();
        drawBattle();
        windowGame->display();
        //ready to use a move again (Attack or regen)
        statut = 0;
    }
}

/*it's the funtion where the victory or the loss is shown*/
void Management::screenResult(int result)
{
    ScreenResultView resultV;
    resultV.showResult(*this,*windowGame,result);
}

/*It's the function where you can increase your stats after the result (ONLY AND ONLY IF THE BOSS IS BEATEN !!!!!)*/
void Management::increaseStats()
{
	IncreaseStatsMenu stats;

	while (windowGame->isOpen())
	{
		sf::Event event;
		while (windowGame->pollEvent(event))
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

                //Choice of increase
                case sf::Keyboard::Return:
                    switch(stats.getPressedItem())
                    {
                    // set Life strategy
                    case 0:
                        hero->setIncrease(new IncreaseLife);
                        break;
                    //set Attack Strategy
                    case 1:
                        hero->setIncrease(new IncreaseAttack);
                        break;
                    //set Shield Strategy
                    case 2:
                        hero->setIncrease(new IncreaseShield);

                        break;
                    // set regeneration strategy
                    case 3:
                        hero->setIncrease(new IncreaseRegeneration);

                        break;
                    default:
                        break;
                    }

                    // increase statistic which has been choosen
                    hero->executeIncrease();






                    spv->showStats(*hero);

                    windowGame->clear();
                    launch();
                    break;

                    default:
                    break;
                }
                break;
                case sf::Event::Closed:
                    windowGame->close();

                default:
                break;

			}

		}

		windowGame->clear();

		stats.draw(*windowGame);

		windowGame->display();
	}
}

/*Function where redits are shown*/
void Management::creditGame()
{
    CreditView credit;
    credit.showCredit(*this,*windowGame);
}

/*Function where you can see your stats during the game*/
void Management::showStats()
{

    while (windowGame->isOpen())
	{
		sf::Event event;
		while (windowGame->pollEvent(event))
		{
            if (event.type == sf::Event::Closed) {
            windowGame->close();
            }

		    switch (event.type)
			{
            case sf::Event::KeyReleased:
                switch(event.key.code)
                {
                case sf::Keyboard::Backspace:
                    pauseMenu();
                    break;
                    default:
                        break;
                }
                break;
                default:
                    break;
			}
		}
        windowGame->clear();
        spv->draw(*windowGame);

        cView->drawBadges(*windowGame, 850, 400);
        windowGame->display();
	}
}
