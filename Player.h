#pragma once
#include <string>
class player // players stats for while in game
{
public:
    player(std::string, std::string, int, int);
    void setName(std::string);
    void setArea(std::string);
    void setLevel(int);
    void setEXP(double);
    void setHealth(double);
    void setMaxHealth();
    void setDamage();
    std::string getName();
    std::string getArea();
    int getLevel();
    double getHealth();
    double getMaxHealth();
    int getDamage();
    int getEXP();
    void setEXP(int);
    int getEXPReq();
    void setEXPReq();
public:
    std::string playerName;
    std::string* pPlayerName = &playerName;
    std::string playerArea;
    int playerLevel;
    double playerHealth;
    double playerMaxHealth;
    int playerDamage;
    int EXP;
    int EXPReq;
    
};

class ninja : public player
{
public:
    int n_damagemultiplier;
    ninja();
    void n_SpecialAttack() const;
};

class pirate : public player
{
public:
    int p_damagemultiplier;
    pirate();
    void p_SpecialAttack() const;
};

