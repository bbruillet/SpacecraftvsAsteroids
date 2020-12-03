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
    boss[2] = new CharacterBoss("BossMauve",PURPLE_DESTROYED);
    boss[3] = new CharacterBoss("BossRouge",RING_RED);
    boss[4] = new CharacterBoss("BossVert",GREEN);
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


CharacterHero& Management::getCharHero()
{
    return this->hero;
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

    sf::RenderWindow windowJeu(sf::VideoMode(1600, 900), "Space Fighter : The battle of Aslorth"/*, sf::Style::Fullscreen*/);

    sf::Image icon;

    if(!icon.loadFromFile("Images/Backgrounds/Icon.png"))
    {

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

void Management::playerPseudo(sf::RenderWindow & windowJeu)
{
    Player player;
    player.pseudoPlayer(windowJeu);
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

        nbStory = 0;
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
    sf::Font font;

    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
    {
        cout << "Internal error" <<endl;
    }

    sf::View view(sf::FloatRect(2000, 2000, 3450, 1800));
    view.setCenter(spacecraft.getX(), spacecraft.getY());

    Planet planetInProgress;

    int display = 0;

    int x = spacecraft.getX();
    int y = spacecraft.getY();

    int a,b;

    while (windowJeu.isOpen())
        {
            sf::Event event;
            while (windowJeu.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                    windowJeu.close();
                }

                switch (event.type)
                {
                    case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                    case sf::Keyboard::Escape:

                        windowJeu.clear();
                        view.reset(sf::FloatRect(2048, 1024, 1500, 900));
                        view.setCenter(750, 450);
                        windowJeu.setView(view);

                        pauseMenu(windowJeu);
                        break;
                        default:
                        break;
                    }
                    default:
                        break;
                }
                for (size_t i (0); i< universe.planets.size();i++){
                    if((spacecraft.getX() >= universe.planets[i]->getX()+200 && spacecraft.getX() <= universe.planets[i]->getX()+800)
                       && (spacecraft.getY() >= universe.planets[i]->getY()+200 && spacecraft.getY() <= universe.planets[i]->getY() + 800))
                    {
                        display = 1;
                        planetInProgress = *universe.planets[i];

                            switch (event.type)
                            {
                                case sf::Event::KeyReleased:
                                switch(event.key.code)
                                {
                                    case sf::Keyboard::Return:

                                        biome.setBackground("Images/Backgrounds/"+planetInProgress.getName()+"_Background.png");
                                        fightPlanet(windowJeu,planetInProgress);


                                    break;
                                    default:
                                        break;
                                }
                                default:
                                    break;
                            }


                    }
                    else
                    {
                        if(*universe.planets[i] == planetInProgress){
                            display = 0;
                        }
                    }

            }

                if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::M)
                {
                    windowJeu.clear();
                    mapSpace(windowJeu);
                }
            }


                if(event.type == sf::Event::EventType::KeyPressed)
                {
                    a = x;
                    b = y;


                    x = spacecraftView.moveOnX(event, x);
                    y = spacecraftView.moveOnY(event, y);

                    a = x-a;
                    b = y-b;
                    view.move(a,b);

                    spacecraft.setX(x);
                    spacecraft.setY(y);
                    spacecraftView.spacecraft_sprite.setPosition(x,y);
                }
            }

            sf::Text text;
            text.setFont(font);
            text.setString("> Press enter key to land <");
            text.setCharacterSize(100);
            text.setPosition(sf::Vector2f(planetInProgress.getX()-200, planetInProgress.getY()-100));


            windowJeu.clear();
            windowJeu.setView(view);
            windowJeu.draw(universe.universe_sprite);

            for(size_t i(0);i<universe.planets.size();i++)
            {
                windowJeu.draw(*universe.planets[i]);
            }

            for(size_t i(0); i < universe.unreachablePlanets.size(); i++)
            {
                windowJeu.draw(*universe.unreachablePlanets[i]);
            }

            if(display == 1)
            {
                windowJeu.draw(text);
            }

            spacecraftView.setSpacecraft(spacecraft);
            spacecraftView.drawSpacecraft(windowJeu);
            windowJeu.display();



        }
}

void Management::mapSpace(sf::RenderWindow & windowJeu)
{
    sf::View view(sf::FloatRect(0, 0, 16000, 8642));
    //4000 2160.5
    view.setCenter(7130, 3150);

    windowJeu.setView(view);

    while (windowJeu.isOpen())
    {

        sf::Event event;

        while (windowJeu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                view.reset(sf::FloatRect(2048, 1024, 1500, 900));
                view.setCenter(750, 450);
                windowJeu.setView(view);
                menu(windowJeu);
            }

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::M)
                {
                    windowJeu.clear();

                    launch(windowJeu);
                }
            }
        }

        sf::Font font;

        if (!font.loadFromFile("Polices/SpaceFont.ttf"))
        {
            cout << "Internal error" <<endl;
        }

        sf::Text text;
        text.setFont(font);
        text.setString("> Appuyez sur la touche 'm' pour revenir sur le jeu <");
        text.setCharacterSize(500);
        text.setPosition(200, -600);

        windowJeu.clear();

        windowJeu.setView(view);
        windowJeu.draw(universe.universe_sprite);

        for(size_t i(0);i<universe.planets.size();i++)
        {
            windowJeu.draw(*universe.planets[i]);
        }

        for(size_t i(0); i < universe.unreachablePlanets.size(); i++)
        {
            windowJeu.draw(*universe.unreachablePlanets[i]);
        }

        windowJeu.draw(text);
        windowJeu.display();

    }
}

void Management::drawBattle(sf::RenderWindow& windowJeu)
{

        windowJeu.clear();
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
        windowJeu.draw(textAttackEvent);
        windowJeu.draw(textLifeHero);
        windowJeu.draw(textLifeBoss);
        windowJeu.draw(textShieldHero);
        windowJeu.draw(textShieldBoss);
        windowJeu.display();
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

    //pour changer les positionnement d'un sprite à l'aide d'un vector2f
    sf::Vector2f dimension(pla.getXChar(),pla.getYChar());
    sf::Vector2f dimensionBoss(pla.getBoss()->getX()-250,pla.getBoss()->getY());
    cView.character_hero_sprite.setPosition(dimension.x, dimension.y);
    cView.attack_boss_sprite.setPosition(dimensionBoss.x,dimensionBoss.y);

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
                                cView.character_hero_sprite.setPosition(dimension.x, dimension.y);
                                //display the scene of the battle
                                drawBattle(windowJeu);
                                //sleep allow us to display our sprite every x seconds
                                sf::sleep(sf::milliseconds(5));
                            }

                            // We set the type of attack we use when whe fight the boss
                            textAttackEvent.setString(fight.eventAttack(attackEvent)+hero.getName());

                            for(size_t i(0);i<5;i++)
                            {
                                //animation when we fight the boss
                                cView.fightHero();
                                //display the scene of the battle
                                drawBattle(windowJeu);
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
                                cView.character_hero_sprite.setPosition(dimension.x, dimension.y);
                                //display scene of the battle
                                drawBattle(windowJeu);
                                //sleep allow us to display our sprite every x seconds
                                sf::sleep(sf::milliseconds(5));
                            }
                            //we set our image of hero to his first form
                            cView.rectHero.left = 0;

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
                                    drawBattle(windowJeu);
                                    //sleep allow us to display our sprite every x seconds
                                    sf::sleep(sf::milliseconds(200));
                                }
                            // to display what type of attack boss do
                            textAttackEvent.setString(fight.eventAttack(attackEvent)+pla.getBoss()->getName());
                            // set the boss image to his inital position
                            cView.rectBoss.left = 0;

                            for(int i(0);i<nb;i++)
                            {
                                //sleep allow us to display our sprite every x seconds
                                sf::sleep(sf::milliseconds(5));
                                //animation of throwing is power ball
                                cView.throwingBoss();
                                // move the sprite of the power ball
                                dimensionBoss.x -= 22;
                                cView.attack_boss_sprite.setPosition(dimensionBoss.x, dimensionBoss.y);
                                //draw battle scene
                                drawBattle(windowJeu);
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
                    if(hero.getPtsLife()+hero.getRegeneration() <= lifeHero)
                    {
                        //regen life
                        fight.regenHero(hero, *pla.getBoss());
                        //update the life of the hero
                        barHero.updateLife(hero.getPtsLife());
                        textLifeHero.setString(to_string(hero.getPtsLife()));

                        for(size_t i(0);i<5;i++)
                        {
                            //set position of the regen
                            cView.regen_sprite.setPosition(pla.getXChar()-20, pla.getYChar()-30);

                            // to display the animation of regeneration
                            cView.regenCircles();
                            cView.drawRegenCircles(windowJeu);
                            // draw fight scene
                            drawBattle(windowJeu);
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
                            drawBattle(windowJeu);
                            //sleep allow us to display our sprite every x seconds
                            sf::sleep(sf::milliseconds(200));
                        }

                       // to display what type of attack boss do
                        textAttackEvent.setString(fight.eventAttack(attackEvent)+pla.getBoss()->getName());
                        // set the boss image to his inital position
                        cView.rectBoss.left = 0;

                        for(int i(0);i<step;i++)
                        {
                            sf::sleep(sf::milliseconds(5));
                            //throw is power ball
                            cView.throwingBoss();
                            //power ball move
                            dimensionBoss.x -= 22;
                            //set position of power ball
                            cView.attack_boss_sprite.setPosition(dimensionBoss.x, dimensionBoss.y);
                            //draw window fight
                            drawBattle(windowJeu);
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
        drawBattle(windowJeu);
        //ready to use a move again (Attack or regen)
        statut = 0;
    }
}

void Management::screenResult(int result, sf::RenderWindow& windowJeu)
{
    sf::View view;
    view.setSize(1600,900);
    view.setCenter(800,450);
    windowJeu.setView(view);


    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
    {
        cout << "Internal error" <<endl;
    }
    windowJeu.clear();
    sf::Text textEvent;
    sf::Text textInstruction;
    textEvent.setFont(font);
    textInstruction.setFont(font);
    textEvent.setCharacterSize(100);
    textInstruction.setCharacterSize(50);
    textEvent.setStyle(sf::Text::Bold);
    textInstruction.setStyle(sf::Text::Bold);




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
                case sf::Keyboard::Space:
                    if(result == 1)
                    {
                        if(nbStory == 2)
                            story(windowJeu);
                        else
                            increaseStats(windowJeu);
                    }
                    else
                    {
                        launch(windowJeu);
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

        //afficher Victoire ou défaite condition
        windowJeu.clear();
        if(result == 1)
        {
            if (!victory_texture.loadFromFile("Images/Backgrounds/Victory.png"))
            {
                std::cout << "Problem for loading background" << std::endl;
            }


            textEvent.setFillColor(sf::Color(244,130,83));
            textEvent.setString("Victory");
            textInstruction.setFillColor(sf::Color(241, 159, 10));
            textInstruction.setString("> Press space key for entering laboratory <");

        }
        if(result == 2)
        {
            if (!victory_texture.loadFromFile("Images/Backgrounds/Loss.png"))
            {
                std::cout << "Problem while loading background" << std::endl;
            }

            textEvent.setFillColor(sf::Color::Red);
            textEvent.setString("Wasted");

            textInstruction.setFillColor(sf::Color(241, 159, 10));
            textInstruction.setString("> Press space key for entering laboratory <");
        }

        victory_sprite.setTexture(victory_texture);
        victory_sprite.setPosition(0, 0);
        victory_sprite.scale(1.0f, 1.0f);

        windowJeu.draw(victory_sprite);
        textEvent.setPosition(575, 150);
        textInstruction.setPosition(150, 25);


        windowJeu.draw(textEvent);
        windowJeu.draw(textInstruction);

        cView.drawBadges(windowJeu, 10, 425);

        windowJeu.display();
	}

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

    if (!font.loadFromFile("Polices/SpaceFont.ttf"))
    {
        cout << "Internal error" <<endl;
    }


	credit[0].setFont(font);
	credit[0].setFillColor(sf::Color::White);
	credit[0].setString("> Bruillet Baptiste ");
	credit[0].setPosition(sf::Vector2f(500,200));

	credit[1].setFont(font);
	credit[1].setFillColor(sf::Color::White);
	credit[1].setString("> Cornut Sylvain ");
	credit[1].setPosition(sf::Vector2f(500,350));

	credit[2].setFont(font);
	credit[2].setFillColor(sf::Color::White);
	credit[2].setString("> Danese Loris " );
	credit[2].setPosition(sf::Vector2f(500,500));

	credit[3].setFont(font);
	credit[3].setFillColor(sf::Color::White);
	credit[3].setString("> Smet Antoine " );
	credit[3].setPosition(sf::Vector2f(500,650));

	for (int i = 0; i < MAX_NUMBER_OF_STUDENTS; i++)
	{
		credit[i].setCharacterSize(66);
	}


   while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
		    // case revenir menu
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                window.clear();
                menu(window);
            }
		}
		window.clear();
		 for (int i = 0; i < MAX_NUMBER_OF_STUDENTS; i++)
            {
                window.draw(credit[i]);
            }
		window.display();
	}
}

void Management::showStats(sf::RenderWindow &windowJeu)
{

    while (windowJeu.isOpen())
	{
		sf::Event event;
		while (windowJeu.pollEvent(event))
		{
		    // case revenir menu
		    if (event.type == sf::Event::Closed)
            {
                launch(windowJeu);
            }
		}
        windowJeu.clear();
        spv.draw(windowJeu);

        cView.drawBadges(windowJeu, 850, 400);
        windowJeu.display();
	}
}
