#include <iostream>
#include <list>

#include "Management.h"
#include "Character.h"
#include "CharacterBoss.h"
#include "CharacterHero.h"
#include "CharacterView.h"
#include "Fight.h"
#include "Planet.h"
#include <SFML/Audio.hpp>
#include "BarView.h"
#include "IStrategyIncrease.h"

using namespace std;


int main()
{
    Management management;
    management.mainWindow();

    return 0;
}
