// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "mob.h"
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> 

using namespace std;
ninja battle(ninja account);
ninja calcEXP(ninja account, classMob monster);
ninja levelUp(ninja account);
pirate battle(pirate account);
pirate calcEXP(pirate account, classMob monster);
pirate levelUp(pirate account);
player battle(player account);
player calcEXP(player account, classMob monster);
player levelUp(player account);
void death();

int main()
{
    string name;
    int option1;
    int option2;
    cout << "Welcome to pirates & ninja\n";
    cout << "please enter your first name\n";
    cin >> name; //asks the user to enter their name
    cout << "Welcome " << name<< "!\n\n";
    cout << "In this game you will be venturing around openly chossing between 3 different paths as either a pirate or a ninja.\n";
    cout << "While you wander around, you will have random encounters with enemies of various levels and of different natures depending on your area.\n\n";
    cout << "As you keep progressing you will level up, increasing your health and damage\n";
    cout << "Good luck " << name << "!";

    cout << "please choose your class. press 1 for Pirate, or press 2 for Ninja\n";
        cin >> option2;
        if (option2 == 1)
        {
            //load in pirate
        }
        else
        {
            //load in ninja
        }

    string location[4] = { "in a Forest","in a Meadow","in the Mountains","in a Castle" }; //an array of the spawn locations, randomized
    player account(name, location[0], 1, 0);
    cout << "\nWelcome " << account.getName() << " You wake up " << account.getArea() << "\nand you are not sure how you ended up here\n";
    while (1) //creates the exploration loop
    {
        Sleep(500); //delays execution 500 miliseconds
        cout << "write 1 to walk straight or 2 to walk left or 3 to walk right\n";
        cin >> option1;
        if (option1 >= 1 && option1 <= 3)
        {
            Sleep(50 * (option1));
            srand(time(NULL));
            if (rand() % 3 == option1 - 1) {
                account = battle(account);
            } //randomly throws player into battle 

        }
        else {
            cout << "\n#@#Error#@# Please enter a number between 1 and 3\n\n";
            cin.clear();
            cin.ignore();
        }
    }
    return 0;

}




ninja battle( ninja account) 
{
    string option;
    string location[4] = { "in a Forest","in a Meadow","in the Mountains","in a Castle" };// string array of where the fight is taking place
    string monsters[5][3] = { {"Vulture","Rat","Snake"},{"Goblin","Ogre","Troll"},{"Dragon","Dragon","Dragon"},{"Dark Knight","The Mad King","Jason Bourne"} }; //String array of who you are fighting
    Sleep(20);
    srand(time(NULL));
    int ranM = (rand() % 3); //random monster
    int ranD = (rand() % 5) + 1; //random difficulty
    classMob monster(monsters[account.getLevel() - 1][ranM], account.getLevel(), account.getArea(), ranD);
    cout << "Suddently you're ambushed by " << monster.getName() << ", prepare for battle\n";
    Sleep(2000);
    do
    {
        cout << "\n\n\n ######################################\nHP:" << account.getHealth() << "                                         " << monster.getName() << "HP:" << monster.getHealth() << " difficulty:" << monster.getDifficulty() << "\n";
        cout << "Write A for attack, S for Special Attack or R for retreat\n";
        cin >> option;
        srand(time(NULL));
        if (option == "R" || option == "r") //retreat loop
        {
            if ((rand() % 2) == 1) {
                cout << "retreat sucessfull" << "\n";
                monster.setHealth(0);
            }
            else {
                cout << "retreat failed, the monster get a free attack and you lose 5 health\n";
                account.setHealth(account.getHealth() - 5);
                option = "A";
            }
        }
        if (option == "A" || option == "a") // attack loop
        {
            int attack = rand() % (account.getDamage());
            srand(time(NULL));
            int mobAttack = rand() % (monster.getDamage());
            monster.setHealth(monster.getHealth() - attack);
            account.setHealth(account.getHealth() - mobAttack);
            cout << "you attack the monster for " << attack << " damage\n";
            Sleep(500);
            cout << "the monster counter attacks for " << mobAttack << " damage\n";
            Sleep(500);
        }
        if (option == "S" || option == "s") // special attack loop
        {
            int Specialattack = n_damagemultiplier() % (account.getDamage());
            srand(time(NULL));
            int mobAttack = n_damagemultiplier % (monster.getDamage());
            monster.setHealth(monster.getHealth() - Specialattack);
            account.setHealth(account.getHealth() - mobAttack);
            if(pirate)
            { cout << "you attack the monster for " << Specialattack << " damage\n";}
            
            Sleep(500);
            cout << "the monster counter attacks for " << mobAttack << " damage\n";
            Sleep(500);
        }
    } 
    
    while (monster.getHealth() > 0 && account.getHealth() > 0);
    cout << "\n\n\n ######################################\nHP:" << account.getHealth() << "                                         " << monster.getName() << "HP:" << monster.getHealth() << " difficulty:" << monster.getDifficulty() << "\n"; //gets all of the mosters info
    if (account.getHealth() <= 0)
    {
        death();
        exit(0);
    }
    account = calcEXP(account, monster);
    return account;
}



void death() //death function
{
    cout << "You have died. Game Over!\n";
}

player calcEXP(player account, classMob monster)//exp calculation loop
{
    cout << "#########\ncalculating EXP\n#########\n";
    Sleep(500);
    account.setEXP(account.getEXP() + monster.getEXP());
    cout << "EXP: " << account.getEXP() << "/" << account.getEXPReq() << "\n";
    if (account.getEXP() >= account.getEXPReq())
    {
        levelUp(account);
    }
    return account;
}

player levelUp(player account) //level up loop
{
    account.setLevel(account.getLevel() + 1);
    account.setEXPReq();
    account.setMaxHealth();
    account.setHealth(account.getMaxHealth());
    cout << "Level up! you are now level: " << account.getLevel() << "!\n";
    return account;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
