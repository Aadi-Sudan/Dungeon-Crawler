#ifndef MARKETPLACE_H
#define MARKETPLACE_H

#include <iostream>
#include "Team.h"

using namespace std;

class Marketplace
{
private:

    int currentFloor_;
    double costMultiplier_;

public:

    // constructors
    Marketplace();
    Marketplace(int currentFloor);

    // getters
    int getFloor();
    double getMultiplier();

    // other
    void buyIngredients(int ingredients, Team& team);
    void buyArmor(int armor, Team& team);
    void buyPots(int pots, Team& team);
    void buyPans(int pans, Team& team);
    void buyCauldrons(int cauldrons, Team& team);
    void buyClubs(int clubs, Team& team);
    void buySpears(int spears, Team& team);
    void buyRapiers(int rapiers, Team& team);
    void buyAxes(int axes, Team& team);
    void buySwords(int swords, Team& team);
    void sellSilver(int silver, Team& team);
    void sellRuby(int ruby, Team& team);
    void sellEmerald(int emerald, Team& team);
    void sellDiamond(int diamond, Team& team);
    void sellGoblet(int goblet, Team& team);

    string purchaseMenu;

};

#endif