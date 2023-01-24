#include <string>
#include "Player.h"
#include <windows.h> 
#include <iostream>

player::player(std::string name, std::string area, int level = 1, int EXP = 0)
{
    setName(name);
    setArea(area);
    setLevel(level);
    setEXP(EXP);
    setMaxHealth();
    setHealth(playerMaxHealth);
    setDamage();
    setEXPReq();
}

void player::setName(std::string name) //function for remembering players name in class
{
    *pPlayerName = name;
}
void player::setArea(std::string area) //Sets the area the player spawns in
{
    playerArea = area;
}
void player::setLevel(int level) // sets the players current level and allows for increments as exp is gained
{
    playerLevel = level;
}
void player::setHealth(double health) // Players current health
{
    playerHealth = health;
}
void player::setMaxHealth() // the max amount of health possible
{
    playerMaxHealth = (100 * getLevel()); //max health is whatever level player is x 100
}
void player::setDamage() // base damge is 30 with it going up with special attacks
{
    playerDamage = (30);
}

std::string player::getName() 
{
    return playerName;
}

std::string player::getArea()
{
    return playerArea;
}

int player::getLevel()
{
    return playerLevel;
}
double player::getHealth()
{
    return playerHealth;
}
double player::getMaxHealth()
{
    return playerMaxHealth;
}
int player::getDamage()
{
    return playerDamage;
}

int player::getEXP()
{
    return EXP;
}
void player::setEXP(int _EXP)
{
    EXP = _EXP;
}
int player::getEXPReq()
{
    return EXPReq;
}
void player::setEXPReq()
{
    EXPReq = 70 + ((getLevel() * getLevel()) * 35);
}


 ninja::ninja() :
    n_damagemultiplier(2)
{}
void ninja::n_SpecialAttack()const
{
    /*cout << "Smoke Bomb Slash!" <<*/ (n_damagemultiplier * playerDamage);
    
};

pirate::pirate() :
    p_damagemultiplier(2.5)

{}

void pirate::p_SpecialAttack()const
{
    /*cout << "ARRR, Flintlock pistol shot!" <<*/ (p_damagemultiplier * playerDamage);
}
