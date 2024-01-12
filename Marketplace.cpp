#include <iostream>
#include <string>
#include "Marketplace.h"

using namespace std;

/*
    Default constructor
*/
Marketplace::Marketplace(){
    currentFloor_ = -1;
    costMultiplier_ = 0;
}

/*
    Parameterized constructor
*/
Marketplace::Marketplace(int currentFloor){
    currentFloor_ = currentFloor;
    costMultiplier_ = 1 + (currentFloor * 0.25);
}

/*
    Getter for the floor int
*/
int Marketplace::getFloor(){
    return currentFloor_;
}

/*
    Getter for the cost multiplier
*/
double Marketplace::getMultiplier(){
    return costMultiplier_;
}

/*
    Buying ingredients for 1 gold each
*/
void Marketplace::buyIngredients(int ingredients, Team& team){
    int currentIngredients = team.getIngredients();
    int currentGold = team.getGold();
    if (currentGold < (ingredients * costMultiplier_)){
        cout << "You don't have enough gold for that!" << endl;
        return;
    } else{
        team.setIngredients(currentIngredients + ingredients);
        team.setGold(currentGold - (ingredients * costMultiplier_));
        cout << "You now have " << team.getIngredients() << " ingredients and " << team.getGold() << " gold." << endl;
        return;
    }
}

/*
    Buying armor for 5 gold each
*/
void Marketplace::buyArmor(int armor, Team& team){
    int currentArmor = team.getArmor();
    int currentGold = team.getGold();
    if (currentArmor >= team.getRemainingMembers() || currentArmor + armor > team.getRemainingMembers()){
        cout << "You can't have more than " << team.getRemainingMembers() << " sets of armor!" << endl;
    }
    if (currentGold < 5 * armor * costMultiplier_){
        cout << "You don't have enough gold for that!" << endl;
        return;
    } else{
        team.setGold(currentGold - (armor * 5 * costMultiplier_));
        team.setArmor(currentArmor + armor);
        cout << "You now have " << currentArmor + armor << " sets of armor and " << team.getGold() << " gold." << endl;
        return;
    }
    
}

/*
    Buying pots for 2 gold each
*/
void Marketplace::buyPots(int pots, Team& team){
    int currentPots = team.getNumPots();
    int currentGold = team.getGold();
    if (currentGold < 2 * pots * costMultiplier_){
        cout << "You don't have enough gold for that!" << endl;
        return;
    } else{
        team.setNumPots(currentPots + pots);
        team.setGold(currentGold - (2 * pots * costMultiplier_));
        cout << "You now have " << team.getNumPots() << " ceramic pots and " << team.getGold() << " gold." << endl;
        return;
    }
}

/*
    Buying pans for 10 gold each
*/
void Marketplace::buyPans(int pans, Team& team){
    int currentPans = team.getNumPans();
    int currentGold = team.getGold();
    if (currentGold < 10 * pans * costMultiplier_){
        cout << "You don't have enough gold for that!" << endl;
        return;
    } else{
        team.setNumPans(currentPans + pans);
        team.setGold(currentGold - (10 * pans * costMultiplier_));
        cout << "You now have " << team.getNumPans() << " frying pans and " << team.getGold() << " gold." << endl;
        return;
    }
}

/*
    Buying cauldrons for 20 gold each
*/
void Marketplace::buyCauldrons(int cauldrons, Team& team){
    int currentCauldrons = team.getNumPans();
    int currentGold = team.getGold();
    if (currentGold < 20 * cauldrons * costMultiplier_){
        cout << "You don't have enough gold for that!" << endl;
        return;
    } else{
        team.setNumCauldrons(currentCauldrons + cauldrons);
        team.setGold(currentGold - (20 * cauldrons * costMultiplier_));
        cout << "You now have " << team.getNumCauldrons() << " cauldrons and " << team.getGold() << " gold." << endl;
        return;
    }
}

/*
    Buying clubs for 2 gold each
*/
void Marketplace::buyClubs(int clubs, Team& team){
    if (team.getNumSwords() + team.getNumAxes() + team.getNumSpears() + team.getNumRapiers() + team.getNumClubs() > 5){
        cout << "You've already reached the max capacity for weapons!" << endl;
        return;
    }
    if (team.getNumSwords() + team.getNumAxes() + team.getNumSpears() + team.getNumRapiers() + team.getNumClubs() + clubs > 5){
        cout << "You can't carry more than 5 weapons at a time!" << endl;
        return;
    }
    int currentClubs = team.getNumClubs();
    int currentGold = team.getGold();
    if (currentGold < 2 * clubs * costMultiplier_){
        cout << "You don't have enough gold for that!" << endl;
        return;
    } else{
        team.setNumClubs(currentClubs + clubs);
        team.setGold(currentGold - (2 * clubs * costMultiplier_));
        cout << "You now have " << team.getNumClubs() << " Stone Clubs and " << team.getGold() << " gold." << endl;
        return;
    }
}

/*
    Buying spears for 2 gold each
*/
void Marketplace::buySpears(int spears, Team& team){
    if (team.getNumSwords() + team.getNumAxes() + team.getNumSpears() + team.getNumRapiers() + team.getNumClubs() >= 5){
        cout << "You've already reached the max capacity for weapons!" << endl;
        return;
    }
    int currentSpears = team.getNumSpears();
    int currentGold = team.getGold();
    if (currentGold < 2 * spears * costMultiplier_){
        cout << "You don't have enough gold for that!" << endl;
        return;
    }
    if (team.getNumSwords() + team.getNumAxes() + team.getNumSpears() + team.getNumRapiers() + team.getNumClubs() + spears > 5){
        cout << "You can't carry more than 5 weapons at a time!" << endl;
        return;
    }
    team.setNumSpears(currentSpears + spears);
    team.setGold(currentGold - (2 * spears * costMultiplier_));
    cout << "You now have " << team.getNumSpears() << " Iron Spears and " << team.getGold() << " gold." << endl;
    return;
}

/*
    Buying rapiers for 5 gold each
*/
void Marketplace::buyRapiers(int rapiers, Team& team){
    if (team.getNumSwords() + team.getNumAxes() + team.getNumSpears() + team.getNumRapiers() + team.getNumClubs() >= 5){
        cout << "You've already reached the max capacity for weapons!" << endl;
        return;
    }
    int currentRapiers = team.getNumRapiers();
    int currentGold = team.getGold();
    if (currentGold < 5 * rapiers * costMultiplier_){
        cout << "You don't have enough gold for that!" << endl;
        return;
    }
    if (team.getNumSwords() + team.getNumAxes() + team.getNumSpears() + team.getNumRapiers() + team.getNumClubs() + rapiers > 5){
        cout << "You can't carry more than 5 weapons at a time!" << endl;
        return;
    }
    team.setNumRapiers(currentRapiers + rapiers);
    team.setGold(currentGold - (5 * rapiers * costMultiplier_));
    cout << "You now have " << team.getNumRapiers() << " (+1) Mythril Rapiers and " << team.getGold() << " gold." << endl;
    return;
}

/*
    Buying axes for 15 gold each
*/
void Marketplace::buyAxes(int axes, Team& team){
    if (team.getNumSwords() + team.getNumAxes() + team.getNumSpears() + team.getNumRapiers() + team.getNumClubs() > 5){
        cout << "You've already reached the max capacity for weapons!" << endl;
        return;
    }
    int currentAxes = team.getNumAxes();
    int currentGold = team.getGold();
    if (currentGold < 15 * axes * costMultiplier_){
        cout << "You don't have enough gold for that!" << endl;
        return;
    }
    if (team.getNumSwords() + team.getNumAxes() + team.getNumSpears() + team.getNumRapiers() + team.getNumClubs() + axes > 5){
        cout << "You can't carry more than 5 weapons at a time!" << endl;
        return;
    }
    team.setNumAxes(currentAxes + axes);
    team.setGold(currentGold - (15 * axes * costMultiplier_));
    cout << "You now have " << team.getNumAxes() << " (+2) Flaming Battle-Axes and " << team.getGold() << " gold." << endl;
    return;
}

/*
    Buying swords for 50 gold each
*/
void Marketplace::buySwords(int swords, Team& team){
    if (team.getNumSwords() + team.getNumAxes() + team.getNumSpears() + team.getNumRapiers() + team.getNumClubs() > 5){
        cout << "You've already reached the max capacity for weapons!" << endl;
        return;
    }
    int currentSwords = team.getNumSwords();
    int currentGold = team.getGold();
    if (currentGold < 50 * swords * costMultiplier_){
        cout << "You don't have enough gold for that!" << endl;
        return;
    }
    if (team.getNumSwords() + team.getNumAxes() + team.getNumSpears() + team.getNumRapiers() + team.getNumClubs() + swords > 5){
        cout << "You can't carry more than 5 weapons at a time!" << endl;
        return;
    }
    team.setNumSwords(currentSwords + swords);
    team.setGold(currentGold - (50 * swords * costMultiplier_));
    cout << "You now have " << team.getNumSwords() << " (+3) Vorpal Longswords and " << team.getGold() << " gold." << endl;
    return;
}

/*
    Selling silver rings for 10 gold each
*/
void Marketplace::sellSilver(int silver, Team& team){
    int currentSilver = team.getNumSilver();
    int currentGold = team.getGold();
    if (currentSilver < silver){
        cout << "You can't sell more than you have!" << endl;
        return;
    }
    team.setNumSilver(currentSilver - silver);
    team.setGold(currentGold + (10 * silver));
    cout << "You now have " << team.getNumSilver() << " silver rings and " << team.getGold() << " gold." << endl;
    return;
}

/*
    Selling ruby necklaces for 20 gold each
*/
void Marketplace::sellRuby(int ruby, Team& team){
    int currentRuby = team.getNumRuby();
    int currentGold = team.getGold();
    if (currentRuby < ruby){
        cout << "You can't sell more than you have!" << endl;
        return;
    }
    team.setNumRuby(currentRuby - ruby);
    team.setGold(currentGold + (20 * ruby));
    cout << "You now have " << team.getNumRuby() << " ruby necklaces and " << team.getGold() << " gold." << endl;
    return;
}

/*
    Selling emerald bracelets for 30 gold each
*/
void Marketplace::sellEmerald(int emerald, Team& team){
    int currentEmerald = team.getNumEmerald();
    int currentGold = team.getGold();
    if (currentEmerald < emerald){
        cout << "You can't sell more than you have!" << endl;
        return;
    }
    team.setNumEmerald(currentEmerald - emerald);
    team.setGold(currentGold + (30 * emerald));
    cout << "You now have " << team.getNumEmerald() << " emerald bracelets and " << team.getGold() << " gold." << endl;
    return;
}

/*
    Selling diamond circlets for 40 gold each
*/
void Marketplace::sellDiamond(int diamond, Team& team){
    int currentDiamond = team.getNumDiamond();
    int currentGold = team.getGold();
    if (currentDiamond < diamond){
        cout << "You can't sell more than you have!" << endl;
        return;
    }
    team.setNumDiamond(currentDiamond - diamond);
    team.setGold(currentGold + (40 * diamond));
    cout << "You now have " << team.getNumDiamond() << " diamond circlets and " << team.getGold() << " gold." << endl;
    return;
}

/*
    Selling gem-encrusted goblets for 50 gold each
*/
void Marketplace::sellGoblet(int goblet, Team& team){
    int currentGoblet = team.getNumGoblet();
    int currentGold = team.getGold();
    if (currentGoblet < goblet){
        cout << "You can't sell more than you have!" << endl;
        return;
    }
    team.setNumGoblet(currentGoblet - goblet);
    team.setGold(currentGold + (50 * goblet));
    cout << "You now have " << team.getNumGoblet() << " gem-encrusted goblets and " << team.getGold() << " gold." << endl;
    return;
}