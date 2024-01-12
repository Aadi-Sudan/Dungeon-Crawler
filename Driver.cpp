#include <iostream>
#include <vector>
#include "Monster.h"
#include "Marketplace.h"
#include "Teammate.h"
#include "Team.h"
#include "Map.h"
#include <random>
#include <fstream>

using namespace std;

/*
    splits a string into multiple parts 
    given a delineating marker
*/
int split(string input_string, char separator, string arr[], int arr_size){
    int index = 0;
    // if the string is empty, return 0
    if (input_string == ""){
        return 0;
    }
    // iterate through the input string, searching for any instances of the separator
    for (int i = 0; i < input_string.length(); i++){
        if (input_string[i] == separator){
            index ++;
            // if the number of elements in the array outweighs what the user specified, return -1
            if (index >= arr_size){
                return -1;
            }
        }
        else {
            arr[index] += input_string[i];
        }
    }
    // return the number of elements in our array, accounting for how array indexing works by adding 1 to the index value
    return index + 1;
}

/*
    marketplace UI for buying ingredients
*/
void ingredientsMenu(Marketplace& marketplace, Team& team){
    int amount = 0;
    string confirmation;
    cout << "How many kg of ingredients do you need [" << 1 * marketplace.getMultiplier() << " Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)" << endl;
    do
    {
        cin >> amount;
        if (amount == 0){
            cout << "Very well. What else may I offer you?" << endl;
            break;
        }
        else if (amount % 5 == 0){
            cout << "You want to buy " << amount << " kg of ingredients for " << amount * marketplace.getMultiplier() << " Gold? (y/n)" << endl;
            do
            {
                cin >> confirmation;
                if (confirmation != "y" && confirmation != "n"){
                    cout << "Enter y or n for yes or no." << endl;
                }
                if (confirmation == "n"){
                    break;
                }
                if (confirmation == "y"){
                    marketplace.buyIngredients(amount, team);
                    break;
                }
            } while (confirmation != "y" && confirmation != "n");
        }
        else {
            cout << "Enter a positive mulitple of 5, or 0 to cancel" << endl;
        }
    } while (amount < 0 || amount % 5 != 0);

}

/*
    marketplace UI for buying cookware
*/
void cookwareMenu(Marketplace& marketplace, Team& team){
    int choice = 0;
    int amount = 0;
    string confirmation;
    cout << "I have several types of cookware, which one would you like?" << endl;
    cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
    cout << "Choose one of the following:" << endl;
    cout << " 1. (25%) Ceramic Pot [" << 2 * marketplace.getMultiplier() << " Gold]" << endl;
    cout << " 2. (10%) Frying Pan [" << 10 * marketplace.getMultiplier() << " Gold]" << endl;
    cout << " 3. (2%) Cauldron [" << 20 * marketplace.getMultiplier() << " Gold]" << endl;
    cout << " 4. Cancel" << endl;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "How many do you want? (Enter a positive integer, or 0 to cancel)" << endl;
            do
            {
                cin >> amount;
                if (amount == 0){
                    cout << "Very well. What else may I offer you?" << endl;
                    break;
                }
                else if (amount > 0){
                    cout << "You want to buy " << amount << " Ceramic Pots for " << amount * 2 * marketplace.getMultiplier() << " Gold? (y/n)" << endl;
                    do
                    {
                        cin >> confirmation;
                        if (confirmation != "y" && confirmation != "n"){
                            cout << "Enter y or n for yes or no." << endl;
                        }
                        if (confirmation == "n"){
                            break;
                        }
                        if (confirmation == "y"){
                            marketplace.buyPots(amount, team);
                            break;
                        }
                    } while (confirmation != "y" && confirmation != "n");
                }
                else {
                    cout << "Enter a positive integer, or 0 to cancel" << endl;
                }
            } while (amount < 0);
            break;

        case 2:
            cout << "How many do you want? (Enter a positive integer, or 0 to cancel)" << endl;
            do
            {
                cin >> amount;
                if (amount == 0){
                    cout << "Very well. What else may I offer you?" << endl;
                    break;
                }
                else if (amount > 0){
                    cout << "You want to buy " << amount << " Frying Pans for " << amount * 10 * marketplace.getMultiplier() << " Gold? (y/n)" << endl;
                    do
                    {
                        cin >> confirmation;
                        if (confirmation != "y" && confirmation != "n"){
                            cout << "Enter y or n for yes or no." << endl;
                        }
                        if (confirmation == "n"){
                            break;
                        }
                        if (confirmation == "y"){
                            marketplace.buyPans(amount, team);
                            break;
                        }
                    } while (confirmation != "y" && confirmation != "n");
                }
                else {
                    cout << "Enter a positive integer, or 0 to cancel" << endl;
                }
            } while (amount < 0);
            break;

        case 3:
            cout << "How many do you want? (Enter a positive integer, or 0 to cancel)" << endl;
            do
            {
                cin >> amount;
                if (amount == 0){
                    cout << "Very well. What else may I offer you?" << endl;
                    break;
                }
                else if (amount > 0){
                    cout << "You want to buy " << amount << " Cauldrons for " << amount * 20 * marketplace.getMultiplier() << " Gold? (y/n)" << endl;
                    do
                    {
                        cin >> confirmation;
                        if (confirmation != "y" && confirmation != "n"){
                            cout << "Enter y or n for yes or no." << endl;
                        }
                        if (confirmation == "n"){
                            break;
                        }
                        if (confirmation == "y"){
                            marketplace.buyCauldrons(amount, team);
                            break;
                        }
                    } while (confirmation != "y" && confirmation != "n");
                }
                else {
                    cout << "Enter a positive integer, or 0 to cancel" << endl;
                }
            } while (amount < 0);
            break;

        case 4:
            cout << "Very well. What else may I offer you?" << endl;
            break;
        
        default:
            cout << "Please pick between 1 and 4." << endl;
            break;
        }
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
}

/*
    marketplace UI for buying weapons
*/
void weaponsMenu(Marketplace& marketplace, Team& team){
    int choice = 0;
    int amount = 0;
    string confirmation;
    cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
    cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;
    cout << "Choose one of the following:" << endl;
    cout << "1. Stone Club [" << 2 * marketplace.getMultiplier() << " Gold]" << endl;
    cout << "2. Iron Spear [" << 2 * marketplace.getMultiplier() << " Gold]" << endl;
    cout << "3. (+1) Mythril Rapier [" << 5 * marketplace.getMultiplier() << " Gold]" << endl;
    cout << "4. (+2) Flaming Battle-Axe [" << 15 * marketplace.getMultiplier() << " Gold]" << endl;
    cout << "5. (+3) Vorpal Longsword [" << 50 * marketplace.getMultiplier() << " Gold]" << endl;
    cout << "6. Cancel" << endl;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "How many do you want? (Enter a positive integer, or 0 to cancel)" << endl;
            do
            {
                cin >> amount;
                if (amount == 0){
                    cout << "Very well. What else may I offer you?" << endl;
                    break;
                }
                else if (amount > 0){
                    cout << "You want to buy " << amount << " Stone Clubs for " << amount * 2 * marketplace.getMultiplier() << " Gold? (y/n)" << endl;
                    do
                    {
                        cin >> confirmation;
                        if (confirmation != "y" && confirmation != "n"){
                            cout << "Enter y or n for yes or no." << endl;
                        }
                        if (confirmation == "n"){
                            break;
                        }
                        if (confirmation == "y"){
                            marketplace.buyClubs(amount, team);
                            break;
                        }
                    } while (confirmation != "y" && confirmation != "n");
                }
                else {
                    cout << "Enter a positive integer, or 0 to cancel" << endl;
                }
            } while (amount < 0);
            break;

        case 2:
            cout << "How many do you want? (Enter a positive integer, or 0 to cancel)" << endl;
            do
            {
                cin >> amount;
                if (amount == 0){
                    cout << "Very well. What else may I offer you?" << endl;
                    break;
                }
                else if (amount > 0){
                    cout << "You want to buy " << amount << " Iron Spears for " << amount * 2 * marketplace.getMultiplier() << " Gold? (y/n)" << endl;
                    do
                    {
                        cin >> confirmation;
                        if (confirmation != "y" && confirmation != "n"){
                            cout << "Enter y or n for yes or no." << endl;
                        }
                        if (confirmation == "n"){
                            break;
                        }
                        if (confirmation == "y"){
                            marketplace.buySpears(amount, team);
                            break;
                        }
                    } while (confirmation != "y" && confirmation != "n");
                }
                else {
                    cout << "Enter a positive integer, or 0 to cancel" << endl;
                }
            } while (amount < 0);
            break;

        case 3:
            cout << "How many do you want? (Enter a positive integer, or 0 to cancel)" << endl;
            do
            {
                cin >> amount;
                if (amount == 0){
                    cout << "Very well. What else may I offer you?" << endl;
                    break;
                }
                else if (amount > 0){
                    cout << "You want to buy " << amount << " (+1) Mythril Rapiers for " << amount * 5 * marketplace.getMultiplier() << " Gold? (y/n)" << endl;
                    do
                    {
                        cin >> confirmation;
                        if (confirmation != "y" && confirmation != "n"){
                            cout << "Enter y or n for yes or no." << endl;
                        }
                        if (confirmation == "n"){
                            break;
                        }
                        if (confirmation == "y"){
                            marketplace.buyRapiers(amount, team);
                            break;
                        }
                    } while (confirmation != "y" && confirmation != "n");
                }
                else {
                    cout << "Enter a positive integer, or 0 to cancel" << endl;
                }
            } while (amount < 0);
            break;

        case 4:
            cout << "How many do you want? (Enter a positive integer, or 0 to cancel)" << endl;
            do
            {
                cin >> amount;
                if (amount == 0){
                    cout << "Very well. What else may I offer you?" << endl;
                    break;
                }
                else if (amount > 0){
                    cout << "You want to buy " << amount << " (+2) Flaming Battle-Axes for " << amount * 15 * marketplace.getMultiplier() << " Gold? (y/n)" << endl;
                    do
                    {
                        cin >> confirmation;
                        if (confirmation != "y" && confirmation != "n"){
                            cout << "Enter y or n for yes or no." << endl;
                        }
                        if (confirmation == "n"){
                            break;
                        }
                        if (confirmation == "y"){
                            marketplace.buyAxes(amount, team);
                            break;
                        }
                    } while (confirmation != "y" && confirmation != "n");
                }
                else {
                    cout << "Enter a positive integer, or 0 to cancel" << endl;
                }
            } while (amount < 0);
            break;

        case 5:
            cout << "How many do you want? (Enter a positive integer, or 0 to cancel)" << endl;
            do
            {
                cin >> amount;
                if (amount == 0){
                    cout << "Very well. What else may I offer you?" << endl;
                    break;
                }
                else if (amount > 0){
                    cout << "You want to buy " << amount << " (+3) Vorpal Longswords for " << amount * 50 * marketplace.getMultiplier() << " Gold? (y/n)" << endl;
                    do
                    {
                        cin >> confirmation;
                        if (confirmation != "y" && confirmation != "n"){
                            cout << "Enter y or n for yes or no." << endl;
                        }
                        if (confirmation == "n"){
                            break;
                        }
                        if (confirmation == "y"){
                            marketplace.buySwords(amount, team);
                            break;
                        }
                    } while (confirmation != "y" && confirmation != "n");
                }
                else {
                    cout << "Enter a positive integer, or 0 to cancel" << endl;
                }
            } while (amount < 0);
            break;

        case 6:
            cout << "Very well. What else may I offer you?" << endl;
            break;
        
        default:
            cout << "Please pick between 1 and 6." << endl;
            break;
        }
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);
}

/*
    marketplace UI for buying armor
*/
void armorMenu(Marketplace& marketplace, Team& team){
    int amount = 0;
    string confirmation;
    cout << "How many sets of armor do you need [" << 5 * marketplace.getMultiplier() << " Gold/set]? (Enter a positive integer, or 0 to cancel)" << endl;
    do
    {
        cin >> amount;
        if (amount == 0){
            cout << "Very well. What else may I offer you?" << endl;
            break;
        }
        else if (amount > 0){
            cout << "You want to buy " << amount << " sets of armor for " << amount * 5 * marketplace.getMultiplier() << " Gold? (y/n)" << endl;
            do
            {
                cin >> confirmation;
                if (confirmation != "y" && confirmation != "n"){
                    cout << "Enter y or n for yes or no." << endl;
                }
                if (confirmation == "n"){
                    break;
                }
                if (confirmation == "y"){
                    marketplace.buyArmor(amount, team);
                    break;
                }
            } while (confirmation != "y" && confirmation != "n");
        }
        else {
            cout << "Enter a positive integer, or 0 to cancel" << endl;
        }
    } while (amount < 0);
}

/*
    marketplace UI for selling treasures
*/
void treasureMenu(Marketplace& marketplace, Team& team){
    int choice;
    int amount;
    string confirmation;
    cout << "I am always willing to take valuable trinkets off your hands! What would you like to sell?" << endl;
    cout << "Choose one of the following:" << endl;
    cout << "1. Silver Ring [10 Gold]" << endl;
    cout << "2. Ruby Necklace [20 Gold]" << endl;
    cout << "3. Emerald Bracelet [30 Gold]" << endl;
    cout << "4. Diamond Circlet [40 Gold]" << endl;
    cout << "5. Gem-Encrusted Goblet [50 Gold]" << endl;
    cout << "6. Cancel" << endl;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "How many do you want to sell? (Enter a positive integer, or 0 to cancel)" << endl;
            do
            {
                cin >> amount;
                if (amount == 0){
                    cout << "Very well. What else may I offer you?" << endl;
                    break;
                }
                else if (amount > 0){
                    cout << "You want to sell " << amount << " Silver Rings for " << amount * 10 << " Gold? (y/n)" << endl;
                    do
                    {
                        cin >> confirmation;
                        if (confirmation != "y" && confirmation != "n"){
                            cout << "Enter y or n for yes or no." << endl;
                        }
                        if (confirmation == "n"){
                            break;
                        }
                        if (confirmation == "y"){
                            marketplace.sellSilver(amount, team);
                            break;
                        }
                    } while (confirmation != "y" && confirmation != "n");
                }
                else {
                    cout << "Enter a positive integer, or 0 to cancel" << endl;
                }
            } while (amount < 0);
            break;

        case 2:
            cout << "How many do you want to sell? (Enter a positive integer, or 0 to cancel)" << endl;
            do
            {
                cin >> amount;
                if (amount == 0){
                    cout << "Very well. What else may I offer you?" << endl;
                    break;
                }
                else if (amount > 0){
                    cout << "You want to sell " << amount << " Ruby Necklaces for " << amount * 20 << " Gold? (y/n)" << endl;
                    do
                    {
                        cin >> confirmation;
                        if (confirmation != "y" && confirmation != "n"){
                            cout << "Enter y or n for yes or no." << endl;
                        }
                        if (confirmation == "n"){
                            break;
                        }
                        if (confirmation == "y"){
                            marketplace.sellRuby(amount, team);
                            break;
                        }
                    } while (confirmation != "y" && confirmation != "n");
                }
                else {
                    cout << "Enter a positive integer, or 0 to cancel" << endl;
                }
            } while (amount < 0);
            break;

        case 3:
            cout << "How many do you want to sell? (Enter a positive integer, or 0 to cancel)" << endl;
            do
            {
                cin >> amount;
                if (amount == 0){
                    cout << "Very well. What else may I offer you?" << endl;
                    break;
                }
                else if (amount > 0){
                    cout << "You want to sell " << amount << " Emerald Bracelets for " << amount * 30 << " Gold? (y/n)" << endl;
                    do
                    {
                        cin >> confirmation;
                        if (confirmation != "y" && confirmation != "n"){
                            cout << "Enter y or n for yes or no." << endl;
                        }
                        if (confirmation == "n"){
                            break;
                        }
                        if (confirmation == "y"){
                            marketplace.sellEmerald(amount, team);
                            break;
                        }
                    } while (confirmation != "y" && confirmation != "n");
                }
                else {
                    cout << "Enter a positive integer, or 0 to cancel" << endl;
                }
            } while (amount < 0);
            break;

        case 4:
            cout << "How many do you want to sell? (Enter a positive integer, or 0 to cancel)" << endl;
            do
            {
                cin >> amount;
                if (amount == 0){
                    cout << "Very well. What else may I offer you?" << endl;
                    break;
                }
                else if (amount > 0){
                    cout << "You want to sell " << amount << " Diamond Circlets for " << amount * 40 << " Gold? (y/n)" << endl;
                    do
                    {
                        cin >> confirmation;
                        if (confirmation != "y" && confirmation != "n"){
                            cout << "Enter y or n for yes or no." << endl;
                        }
                        if (confirmation == "n"){
                            break;
                        }
                        if (confirmation == "y"){
                            marketplace.sellDiamond(amount, team);
                            break;
                        }
                    } while (confirmation != "y" && confirmation != "n");
                }
                else {
                    cout << "Enter a positive integer, or 0 to cancel" << endl;
                }
            } while (amount < 0);
            break;

        case 5:
            cout << "How many do you want to sell? (Enter a positive integer, or 0 to cancel)" << endl;
            do
            {
                cin >> amount;
                if (amount == 0){
                    cout << "Very well. What else may I offer you?" << endl;
                    break;
                }
                else if (amount > 0){
                    cout << "You want to sell " << amount << " Gem-Encrusted Goblets for " << amount * 50 << " Gold? (y/n)" << endl;
                    do
                    {
                        cin >> confirmation;
                        if (confirmation != "y" && confirmation != "n"){
                            cout << "Enter y or n for yes or no." << endl;
                        }
                        if (confirmation == "n"){
                            break;
                        }
                        if (confirmation == "y"){
                            marketplace.sellGoblet(amount, team);
                            break;
                        }
                    } while (confirmation != "y" && confirmation != "n");
                }
                else {
                    cout << "Enter a positive integer, or 0 to cancel" << endl;
                }
            } while (amount < 0);
            break;

        case 6:
            cout << "Very well. What else may I offer you?" << endl;
            break;
        
        default:
            cout << "Please pick between 1 and 6." << endl;
            break;
        }
    } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);
}

/*
    marketplace UI for all transactions in the game
*/
void purchaseMenu(Marketplace& marketplace, Team& team){
    int choice = 0;
    do
    {
        cout << "+-------------+" << endl;
        cout << "| INVENTORY   |" << endl;
        cout << "+-------------+" << endl;
        cout << "| Gold        | " << team.getGold() << endl;
        cout << "| Ingredients | " << team.getIngredients() << " kg" << endl;
        cout << "| Cookware    | P: " << team.getNumPots() << " | F: " << team.getNumPans() << " | C: " << team.getNumCauldrons() << endl;
        cout << "| Weapons     | C: " << team.getNumClubs() << " | S: " << team.getNumSpears() << " | R: " << team.getNumRapiers() << " | B: " << team.getNumAxes() << " | L: " << team.getNumSwords() << endl;
        cout << "| Armor       | " << team.getArmor() << endl;
        cout << "| Treasures   | R: " << team.getNumSilver() << " | N: " << team.getNumRuby() << " | B: " << team.getNumEmerald() << " | C: " << team.getNumDiamond() << " | G: " << team.getNumGoblet() << endl;
        cout << endl;
        cout << "Choose one of the following:" << endl;
        cout << "1. Ingredients: To make food, you have to cook raw ingredients." << endl;
        cout << "2. Cookware: You will need something to cook those ingredients." << endl;
        cout << "3. Weapons: It's dangerous to go alone, take this!" << endl;
        cout << "4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
        cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
        cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            
            ingredientsMenu(marketplace, team);
            break;

        case 2:
            
            cookwareMenu(marketplace, team);
            break;

        case 3:

            weaponsMenu(marketplace, team);
            break;

        case 4:
            
            armorMenu(marketplace, team);
            break;

        case 5:
            
            treasureMenu(marketplace, team);
            break;

        case 6:
            cout << "Brilliant! Safe travels, my friends, and may fate intertwine our paths soon again!" << endl;
            break;
        
        default:
            cout << "Please pick between 1 and 6." << endl;
            break;
        }
    } while (choice != 6);
    cout << endl;
}

/*
    Status update of key game details, printed at the start of every turn
*/
void statusUpdate(Team& team, Map& map){
    cout << "+-------------+" << endl;
    cout << "| STATUS      |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Rooms Cleared: " << 5 - map.getRoomCount() << " | Keys: " << team.getKeys() << " | Anger Level: " << team.getAnger() << endl;
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << team.getGold() << endl;
    cout << "| Ingredients | " << team.getIngredients() << " kg" << endl;
    cout << "| Cookware    | P: " << team.getNumPots() << " | F: " << team.getNumPans() << " | C: " << team.getNumCauldrons() << endl;
    cout << "| Weapons     | C: " << team.getNumClubs() << " | S: " << team.getNumSpears() << " | R: " << team.getNumRapiers() << " | B: " << team.getNumAxes() << " | L: " << team.getNumSwords() << endl;
    cout << "| Armor       | " << team.getArmor() << endl;
    cout << "| Treasures   | R: " << team.getNumSilver() << " | N: " << team.getNumRuby() << " | B: " << team.getNumEmerald() << " | C: " << team.getNumDiamond() << " | G: " << team.getNumGoblet() << endl;
    cout << "+-------------+" << endl;
    cout << "| PARTY       |" << endl;
    cout << "+-------------+" << endl;
    for (int i = 0; i < team.getRemainingMembers(); i++){
        cout << "| " << team.getMemberAtIndex(i).getName() << " | Fullness: " << team.getMemberAtIndex(i).getStamina() << endl;
    }
    cout << "+-------------+" << endl;
}

/*
    function for creating a monster from the monster text file
*/
Monster createMonster(int challenge){
    ifstream inFile;
    string monster;
    string arr[2];
    string names[21];
    int level[21];
    int index = 0;
    inFile.open("monsters.txt");
    while(!inFile.eof()){
        getline(inFile, monster);
        arr[0] = "";
        arr[1] = "";
        int numSplit = split(monster, ',', arr, 2);
        names[index] = arr[0];
        level[index] = stoi(arr[1]);
        index++;
    }
    vector<string> sortedMonsters;
    for (int i = 0; i < 21; i++){
        if (level[i] == challenge){
            sortedMonsters.push_back(names[i]);
        }
    }
    int randInt = rand() % sortedMonsters.size();
    Monster m(sortedMonsters[randInt], challenge);
    cout << m.getName() << " up ahead! They look furious!" << endl;
    return m;
}

/*
    function that determines what misfortune is applied to the team
*/
void misfortunes(Team& team, bool flag){
    int randInt = rand() % 101;
    if (randInt <= 30){
        // team robbed
        cout << "OH NO! Your team was robbed by dungeon bandits!" << endl;
        int rand2 = rand() % 101;
        if (rand2 <= 25){
            int rand3 = rand() % 3;
            if (rand3 == 0){
                int pots = team.getNumPots() - 1;
                team.setNumPots(pots);
                cout << "You lost 1 pot!" << endl;
            } else if (rand3 == 1){
                int pans = team.getNumPans() - 1;
                team.setNumPans(pans);
                cout << "You lost 1 frying pan!" << endl;
            } else if (rand3 == 2){
                int cauldrons = team.getNumCauldrons() - 1;
                team.setNumCauldrons(cauldrons);
                cout << "You lost 1 cauldron!" << endl;
            }
        }
        else if (rand2 > 25 && rand2 <= 50){
            int armor = team.getArmor() - 1;
            team.setArmor(armor);
            cout << "You lost 1 armor!" << endl;
        }
        else {
            int ingredients = team.getIngredients() - 10;
            team.setIngredients(ingredients);
            cout << "You lost 10 kg of ingredients!" << endl;
        }
    } else if (randInt > 30 && randInt <= 40){
        // broken item
        int randWeapon = rand() % 5;
        if (randWeapon == 0){
            int clubs = team.getNumClubs() - 1;
            team.setNumClubs(clubs);
            cout << "You lost 1 club!" << endl;
        } else if (randWeapon == 1){
            int spears = team.getNumSpears() - 1;
            team.setNumSpears(spears);
            cout << "You lost 1 spear!" << endl;
        } else if (randWeapon == 2){
            int rapiers = team.getNumRapiers() - 1;
            team.setNumRapiers(rapiers);
            cout << "You lost 1 rapier!" << endl;
        } else if (randWeapon == 3){
            int axes = team.getNumAxes() - 1;
            team.setNumAxes(axes);
            cout << "You lost 1 axe!" << endl;
        } else if (randWeapon == 4){
            int swords = team.getNumSwords() - 1;
            team.setNumSwords(swords);
            cout << "You lost 1 longsword!" << endl;
        }
    } else if (randInt > 40 && randInt <= 70){
        // food poisoning
        int randMember = rand() % team.getRemainingMembers();
        cout << "OH NO! Your teammate " << team.getMemberAtIndex(randMember).getName() << " has caught a bad case of severe food poisoning!" << endl;
        team.getMemberAtIndex(randMember).changeStamina(-10);
    } else {
        // locked in room
        if (flag == false){
            return;
        } else {
            int unluckyMember = 1 + (rand() % (team.getRemainingMembers() - 1));
            cout << "OH NO! Your teammate " << team.getMemberAtIndex(unluckyMember).getName() << " is trapped in the previous room and is unable to get through. You must continue without them." << endl;
            team.eliminateMember(unluckyMember); 
            cout << "Your party size has reduced to " << team.getRemainingMembers() << " members." << endl;
        }
    }
}

/*
    function that determines whether misfortunes will be applied
*/
void misfortuneDeterminant(Team& team, bool flag, int probability){
    int randInt = rand() % 101;
    if (randInt <= probability){
        misfortunes(team, flag);
    } else {
        return;
    }
}

/*
    Return false if the puzzle was failed, true if succeeded
*/
bool doorPuzzle(Team& team){
    cout << "The door is guarded by a mystic barrier! In order to bypass it, you must choose the correct spell!" << endl;
    cout << "Fire melts ice, ice freezes water, and water extinguishes fire. Be wary, as you only have 3 tries before the magic of the door will overwhelm your team!" << endl;
    int failCounter = 0;
    bool correct = false;
    string response;
    do
    {
        int randInt = rand() % 3;
        cout << "Choose a spell: fire, water, or ice." << endl;
        cin >> response;
        if (randInt == 0){
            if (response == "fire"){
                correct = true;
            }
            else {
                failCounter++;
                cout << "You chose the wrong spell! Try again, but remember that the door's barrier changes elements with each try!" << endl;
            }
        } else if (randInt == 1){
            if (response == "water"){
                correct = true;
            }
            else {
                failCounter++;
                cout << "You chose the wrong spell! Try again, but remember that the door's barrier changes elements with each try!" << endl;
            }
        } else if (randInt == 2){
            if (response == "ice"){
                correct = true;
            }
            else {
                failCounter++;
                cout << "You chose the wrong spell! Try again, but remember that the door's barrier changes elements with each try!" << endl;
            }
        }
    } while (failCounter < 3 && correct == false);
    if (failCounter >= 3){
        int randMember = 1 + (rand() % (team.getRemainingMembers() - 1));
        cout << "You failed the door challenge! The magic of the door has eliminated " << team.getMemberAtIndex(randMember).getName() << "!" << endl;
        team.eliminateMember(randMember);
        cout << "Your party size has reduced to " << team.getRemainingMembers() << " members." << endl;
        return false;
    } else {
        cout << "Success! You managed to beat the door puzzle!" << endl;
        return true;
    }
}


/*
    UI and outcomes for interacting with NPCs
*/
void NPCInteraction(Team& team, int floor){
    cout << "Hello weary travelers! Answer my riddle correctly, and I promise to make it worth your while!" << endl;
    ifstream inFile;
    inFile.open("riddles.txt");
    string answer;
    string riddle;
    string arr[2];
    string riddles[20];
    string answers[20];
    int index = 0;
    while (!inFile.eof()){
        getline(inFile, riddle);
        arr[0] = "";
        arr[1] = "";
        int numSplit = split(riddle, '~', arr, 2);
        riddles[index] = arr[0];
        answers[index] = arr[1];
        index++;
    }
    int randInt = rand() % 20;
    cout << riddles[randInt] << endl;
    cin >> answer;
    if (answer == answers[randInt]){
        cout << "You're smarter than you look. Perhaps I can interest you in my business endeavors?" << endl;
        Marketplace marketplace(floor);
        purchaseMenu(marketplace, team);

    } else {
        cout << "Wrong! If I cannot challenge your minds, perhaps I can challenge your muscles!" << endl;
        Monster m = createMonster(floor);
        team.fightMonster(m);
    }
}

/*
    Run at the end of every action, check the conditions for whether the game is over
*/
bool deathCheck(Team& team){
    for (int i = 0; i < team.getRemainingMembers(); i++){
        if (team.getMemberAtIndex(i).getStamina() <= 0){
            if (i == 0){
                cout << "Oh no! " << team.getMemberAtIndex(i).getName() << " has died! Your team can't hope to survive without it's leader!" << endl;
                return true;
            } else{
                cout << "Oh no! Your teammate " << team.getMemberAtIndex(i).getName() << " has died of hunger!" << endl;
                team.eliminateMember(i);
                cout << "Your party size has reduced to " << team.getRemainingMembers() << " members." << endl;
            }
        }
    }
    if (team.getRemainingMembers() < 2){
        cout << "You do not have enough teammates to finish the game!" << endl;
        return true;
    }
    if (team.getAnger() >= 100){
        cout << "Oh no! The Sorcerer's power has grown too vast! His dark magic has wiped out your team!" << endl;
        return true;
    }
    return false;
}

/*
    UI for cooking and eating
*/
void cookingTerminal(Team& team, int portions){
    string utensil;
    bool passed = false;
    cout << "What cookware would you like to use? Enter p for pots, f for pans, and c for cauldrons." << endl;
    do
    {
        cin >> utensil;
        if (utensil != "p" && utensil != "f" && utensil != "c"){
            cout << "Please select one of the cookwares listed above!" << endl;
        } else if (utensil == "p"){
            if (team.getNumPots() <= 0){
                cout << "You don't have any pots to use!" << endl;
                break;
            } else {
                team.cookAndEat(utensil, portions);
                passed = true;
            }
        } else if (utensil == "f"){
            if (team.getNumPans() <= 0){
                cout << "You don't have any frying pans to use!" << endl;
                break;
            } else {
                team.cookAndEat(utensil, portions);
                passed = true;
            }
        } else if (utensil == "c"){
            if (team.getNumCauldrons() <= 0){
                cout << "You don't have any cauldrons to use!" << endl;
                break;
            } else {
                team.cookAndEat(utensil, portions);
                passed = true;
            }
        }
    } while (passed == false);
}

/*
    generates random locations on the map, used at the start of the game to determine room and NPC locations
*/
void generateCoordinates(int& row, int& col){
    int randRow = rand() % 12;
    int randCol = rand() % 12;
    row = randRow;
    col = randCol;
}

/*
    The game driver
*/
int main(){
    // initializing the death check and seeding our random numbers
    bool gameOver = false;
    srand(time(0));
    
    // creating the team object
    string name1, name2, name3, name4, name5;
    int startingGold = 100;
    int startingIngredients = 0;
    cout << "Welcome to the dungeon! Please enter your team leader's name!" << endl;
    cin >> name1;
    Teammate member1(name1, 50);
    cout << "Please enter your 4 teammate names, separating each with a space." << endl;
    cin >> name2 >> name3 >> name4 >> name5;
    Teammate member2(name2, 50);
    Teammate member3(name3, 50);
    Teammate member4(name4, 50);
    Teammate member5(name5, 50);
    vector<Teammate> members = {member1, member2, member3, member4, member5};
    int cookware[3] = {0, 0, 0};
    int weapons[5] = {0, 0, 0, 0, 0};
    int treasures[5] = {0, 0, 0, 0, 0};
    int keys = 0;
    Team team(members, startingGold, startingIngredients, cookware, weapons, treasures, keys);

    // executing the initial marketplace visit and creating the map class, randomly generating 5 NPCs and 5 rooms
    Marketplace startingVendor(0);
    purchaseMenu(startingVendor, team);

    Map grid;
    int row;
    int col;
    for (int i = 0; i < 5; i++){
        bool created = false;
        while (created == false){
            generateCoordinates(row, col);
            if (grid.isFreeSpace(row, col)){
                grid.addNPC(row, col);
                created = true;
            }
        }
    }
    for (int i = 0; i < 5; i++){
        bool created = false;
        while (created == false){
            generateCoordinates(row, col);
            if (grid.isFreeSpace(row, col)){
                grid.addRoom(row, col);
                created = true;
            }
        }
    }
    
    // entering a continual loop for the duration of the game
    int choice;
    int choice2;
    string confirmation;
    char direction;
    bool moved;
    bool result;
    Monster m;
    int playerRow;
    int playerCol;
    do
    {
        grid.displayMap();
        statusUpdate(team, grid);
        playerRow = grid.getPlayerRow();
        playerCol = grid.getPlayerCol();
        if (grid.isNPCLocation(playerRow, playerCol)){
            cout << "Select one:" << endl;
            cout << "  1. Move" << endl;
            cout << "  2. Speak to NPC" << endl;
            cout << "  3. Give up" << endl;
            do {
                cin >> choice;
                switch (choice)
                {
                    case 1:

                        cout << "What direction would you like to move in? Enter w for up, s for down, a for left, and d for right." << endl;
                        cin >> direction;
                        moved = grid.move(direction);
                        if (moved == false){
                            cout << "You can't move that way!" << endl;
                        }
                        break;

                    case 2:

                        NPCInteraction(team, grid.getRoomCount());
                        grid.removeNPC(playerRow, playerCol);
                        misfortuneDeterminant(team, false, 40);
                        team.angerUp();
                        break;

                    case 3:

                        cout << "Game over! Your team failed to escape the dungeon, and you have surrendered to the Sorcerer's forces!" << endl;
                        gameOver = true;
                        break;

                    default:

                        cout << "Please select one of the options above! Enter a number between 1 and 3." << endl;
                        break;
                }

            } while (choice != 1 && choice != 2 && choice != 3);
            
        }
        else if (grid.isRoomLocation(playerRow, playerCol)){
            cout << "Select one:" << endl;
            cout << "  1. Move" << endl;
            cout << "  2. Open the door" << endl;
            cout << "  3. Give up" << endl;
            do {
                cin >> choice;
                switch (choice)
                {
                    case 1:

                        cout << "What direction would you like to move in? Enter w for up, s for down, a for left, and d for right." << endl;
                        cin >> direction;
                        moved = grid.move(direction);
                        if (moved == false){
                            cout << "You can't move that way!" << endl;
                        }
                        break;

                    case 2:

                        if (team.getKeys() > 0){
                            cout << "Would you like to use one of your " << team.getKeys() << " keys to open the door? Enter y or n for yes or no." << endl;
                            do
                            {
                                cin >> confirmation;
                                if (confirmation != "y" && confirmation != "n"){
                                    cout << "Enter y or n for yes or no." << endl;
                                }
                                if (confirmation == "n"){
                                    cout << "Very well." << endl;
                                    break;
                                }
                                if (confirmation == "y"){
                                    team.setKeys(team.getKeys() - 1);
                                    cout << "You now have " << team.getKeys() << " keys." << endl;
                                    m = createMonster((5 - grid.getRoomCount()) + 2);
                                        bool outcome = team.fightMonster(m);
                                        if (outcome == true){
                                            grid.removeRoom(playerRow, playerCol);
                                            cout << "You have cleared a room! Only " << grid.getRoomCount() << " remain!" << endl;
                                            misfortuneDeterminant(team, false, 60);
                                        } else{
                                            cout << "The door remains locked!" << endl;
                                            misfortuneDeterminant(team, false, 40);
                                        }
                                }
                            } while (confirmation != "y" && confirmation != "n");
                        } else{
                            cout << "You don't have any keys! You can attempt to force the door open with magic, but it will be risky!" << endl;
                            cout << "Would you like to proceed?" << endl;
                            do
                            {
                                cin >> confirmation;
                                if (confirmation != "y" && confirmation != "n"){
                                    cout << "Enter y or n for yes or no." << endl;
                                }
                                if (confirmation == "n"){
                                    cout << "Wise choice." << endl;
                                    break;
                                }
                                if (confirmation == "y"){
                                    result = doorPuzzle(team);
                                    if (result == true){
                                        Monster m = createMonster((5 - grid.getRoomCount()) + 2);
                                        bool outcome = team.fightMonster(m);
                                        if (outcome == true){
                                            grid.removeRoom(playerRow, playerCol);
                                            cout << "You have cleared a room! Only " << grid.getRoomCount() << " remain!" << endl;
                                            misfortuneDeterminant(team, true, 60);
                                        } else{
                                            cout << "The door remains locked!" << endl;
                                            misfortuneDeterminant(team, true, 40);
                                        }
                                    } else {
                                        cout << "You failed the door challenge and lost a teammate!" << endl;
                                        misfortuneDeterminant(team, true, 40);
                                    }
                                }
                            } while (confirmation != "y" && confirmation != "n");
                        }
                        team.angerUp();
                        break;

                    case 3:

                        cout << "Game over! Your team failed to escape the dungeon, and you have surrendered to the Sorcerer's forces!" << endl;
                        gameOver = true;
                        break;

                    default:

                        cout << "Please select one of the options above! Enter a number between 1 and 3." << endl;
                        break;
                }
            } while (choice != 1 && choice != 2 && choice != 3);
        }
        else if (grid.isDungeonExit(playerRow, playerCol)){
            if (grid.getRoomCount() == 5){
                cout << "Congratulations! You have defeated the Sorcerer and escaped the dungeon! You should be proud of yourselves; your names will forever be etched into the halls of legend!" << endl;
                gameOver = true;
            } else{
                cout << "You can't exit the dungeon until you defeat the Sorcerer! He's hiding in one of the " << grid.getRoomCount() << " remaining rooms!" << endl; 
                cout << "Select one:" << endl;
                cout << "  1. Move" << endl;
                cout << "  2. Investigate" << endl;
                cout << "  3. Pick a Fight" << endl;
                cout << "  4. Cook and Eat" << endl;
                cout << "  5. Give up" << endl;
                do {
                    cin >> choice2;
                    switch (choice2)
                    {
                        case 1:

                            cout << "What direction would you like to move in? Enter w for up, s for down, a for left, and d for right." << endl;
                            cin >> direction;
                            moved = grid.move(direction);
                            if (moved == false){
                                cout << "You can't move that way!" << endl;
                            }
                            break;

                        case 2:

                            if (grid.isExplored(playerRow, playerCol)){
                                cout << "You have already explored this location!" << endl;
                                break;
                            } else {
                                grid.exploreSpace(playerRow, playerCol);
                                int randSpace = rand() % 101;
                                if (randSpace <= 10){
                                    team.setKeys(team.getKeys() + 1);
                                    cout << "You found a key!" << endl;
                                    for (int i = 0; i < team.getRemainingMembers(); i++){
                                        int probability = rand() % 101;
                                        if (probability >= 50){
                                            team.getMemberAtIndex(i).changeStamina(-10);
                                            cout << team.getMemberAtIndex(i).getName() << " lost 10 stamina!" << endl;
                                        }
                                    }
                                    misfortuneDeterminant(team, false, 40);
                                    team.angerUp();
                                } else if (randSpace > 10 && randSpace <= 30){
                                    cout << "You found a treasure!" << endl;
                                    int roomsCleared = 5 - grid.getRoomCount();
                                    if (roomsCleared == 0){
                                        team.setNumSilver(team.getNumSilver() + 1);
                                        cout << "You now have " << team.getNumSilver() << " silver rings!" << endl;
                                    } else if (roomsCleared == 1){
                                        team.setNumRuby(team.getNumRuby() + 1);
                                        cout << "You now have " << team.getNumRuby() << " ruby necklaces!" << endl;
                                    } else if (roomsCleared == 2){
                                        team.setNumEmerald(team.getNumEmerald() + 1);
                                        cout << "You now have " << team.getNumEmerald() << " emerald bracelets!" << endl;
                                    } else if (roomsCleared == 3){
                                        team.setNumDiamond(team.getNumDiamond() + 1);
                                        cout << "You now have " << team.getNumDiamond() << " diamond circlets!" << endl;
                                    } else if (roomsCleared == 4){
                                        team.setNumGoblet(team.getNumGoblet() + 1);
                                        cout << "You now have " << team.getNumGoblet() << " gem-encrusted goblets!" << endl;
                                    }
                                    for (int i = 0; i < team.getRemainingMembers(); i++){
                                        int probability = rand() % 101;
                                        if (probability >= 50){
                                            team.getMemberAtIndex(i).changeStamina(-10);
                                            cout << team.getMemberAtIndex(i).getName() << " lost 10 stamina!" << endl;
                                        }
                                    }
                                    misfortuneDeterminant(team, false, 40);
                                    team.angerUp();
                                } else if (randSpace > 30 && randSpace <= 50){
                                    m = createMonster(6 - grid.getRoomCount());
                                    team.fightMonster(m);
                                    misfortuneDeterminant(team, false, 40);
                                    team.angerUp();
                                }
                            }
                            break;

                        case 3:

                            m = createMonster(6 - grid.getRoomCount());
                            team.fightMonster(m);
                            misfortuneDeterminant(team, false, 40);
                            team.angerUp();
                            break;

                        case 4:

                            int portions;
                            cout << "How many portions would you like to make? 1 portion costs 5 kg of ingredients and rejuvenates 1 stamina for each team member." << endl;
                            do
                            {
                                cin >> portions;
                                if (portions <= 0){
                                    cout << "Please enter a positive quantity." << endl;
                                } 
                                if (team.getIngredients() - (portions * 5) < 0){
                                    cout << "You don't have enough ingredients for that!" << endl;
                                    break;
                                }
                                else {
                                    cookingTerminal(team, portions);
                                    misfortuneDeterminant(team, false, 40);
                                    team.angerUp();
                                    break;
                                }
                            } while (portions <= 0 || team.getIngredients() - (portions * 5) < 0);
                            break;

                        case 5:

                            cout << "Game over! Your team failed to escape the dungeon, and you have surrendered to the Sorcerer's forces!" << endl;
                            gameOver = true;
                            break;

                        default:
                    
                            cout << "Please select one of the options above! Enter a number between 1 and 6." << endl;
                            break;
                    }
                } while (choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 4 && choice2 != 5);
            }
        } else {
            cout << "Select one:" << endl;
            cout << "  1. Move" << endl;
            cout << "  2. Investigate" << endl;
            cout << "  3. Pick a Fight" << endl;
            cout << "  4. Cook and Eat" << endl;
            cout << "  5. Give up" << endl;
            do {
                cin >> choice;
                switch (choice)
                {
                    case 1:

                        cout << "What direction would you like to move in? Enter w for up, s for down, a for left, and d for right." << endl;
                        cin >> direction;
                        moved = grid.move(direction);
                        if (moved == false){
                            cout << "You can't move that way!" << endl;
                        }
                        break;

                    case 2:

                        if (grid.isExplored(playerRow, playerCol)){
                            cout << "You have already explored this location!" << endl;
                            break;
                        } else {
                            grid.exploreSpace(playerRow, playerCol);
                            int randSpace = rand() % 101;
                            if (randSpace <= 10){
                                team.setKeys(team.getKeys() + 1);
                                cout << "You found a key!" << endl;
                                for (int i = 0; i < team.getRemainingMembers(); i++){
                                    int probability = rand() % 101;
                                    if (probability >= 50){
                                        team.getMemberAtIndex(i).changeStamina(-10);
                                        cout << team.getMemberAtIndex(i).getName() << " lost 10 stamina!" << endl;
                                    }
                                }
                                misfortuneDeterminant(team, false, 40);
                                team.angerUp();
                            } else if (randSpace > 10 && randSpace <= 30){
                                cout << "You found a treasure!" << endl;
                                int roomsCleared = 5 - grid.getRoomCount();
                                if (roomsCleared == 0){
                                    team.setNumSilver(team.getNumSilver() + 1);
                                    cout << "You now have " << team.getNumSilver() << " silver rings!" << endl;
                                } else if (roomsCleared == 1){
                                    team.setNumRuby(team.getNumRuby() + 1);
                                    cout << "You now have " << team.getNumRuby() << " ruby necklaces!" << endl;
                                } else if (roomsCleared == 2){
                                    team.setNumEmerald(team.getNumEmerald() + 1);
                                    cout << "You now have " << team.getNumEmerald() << " emerald bracelets!" << endl;
                                } else if (roomsCleared == 3){
                                    team.setNumDiamond(team.getNumDiamond() + 1);
                                    cout << "You now have " << team.getNumDiamond() << " diamond circlets!" << endl;
                                } else if (roomsCleared == 4){
                                    team.setNumGoblet(team.getNumGoblet() + 1);
                                    cout << "You now have " << team.getNumGoblet() << " gem-encrusted goblets!" << endl;
                                }
                                for (int i = 0; i < team.getRemainingMembers(); i++){
                                    int probability = rand() % 101;
                                    if (probability >= 50){
                                        team.getMemberAtIndex(i).changeStamina(-10);
                                        cout << team.getMemberAtIndex(i).getName() << " lost 10 stamina!" << endl;
                                    }
                                }
                                misfortuneDeterminant(team, false, 40);
                                team.angerUp();
                            } else if (randSpace > 30 && randSpace <= 50){
                                m = createMonster(6 - grid.getRoomCount());
                                team.fightMonster(m);
                                misfortuneDeterminant(team, false, 40);
                                team.angerUp();
                            }
                            else {
                                cout << "Your team investigated and found nothing at this location!" << endl;
                                misfortuneDeterminant(team, false, 40);
                                team.angerUp();
                            }
                        }
                        break;

                    case 3:

                        m = createMonster(6 - grid.getRoomCount());
                        team.fightMonster(m);
                        misfortuneDeterminant(team, false, 40);
                        team.angerUp();
                        break;

                    case 4:

                        int portions;
                        cout << "How many portions would you like to make? 1 portion costs 5 kg of ingredients and rejuvenates 1 stamina for each team member." << endl;
                        do
                        {
                            cin >> portions;
                            if (portions <= 0){
                                cout << "Please enter a positive quantity." << endl;
                            } 
                            if (team.getIngredients() - (portions * 5) < 0){
                                cout << "You don't have enough ingredients for that!" << endl;
                                break;
                            }
                            else {
                                cookingTerminal(team, portions);
                                misfortuneDeterminant(team, false, 40);
                                team.angerUp();
                                break;
                            }
                        } while (portions <= 0 || team.getIngredients() - (portions * 5) < 0);
                        break;

                    case 5:

                        cout << "Game over! Your team failed to escape the dungeon, and you have surrendered to the Sorcerer's forces!" << endl;
                        gameOver = true;
                        break;

                    default:

                        cout << "Please select one of the options above! Enter a number between 1 and 6." << endl;
                        break;
                }
            } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);
        }
        if (deathCheck(team) == true){
            gameOver = true;
        }
    } while (gameOver == false);

    // saving the results of the game to our output file and noting key statistics

    ofstream file("results.txt");
    file << "Game over!" << endl;
    file << endl;
    file << "Surviving teammates:" << endl;
    for (int i = 0; i < team.getRemainingMembers(); i++){
        file << team.getMemberAtIndex(i).getName() << endl;
    }
    file << endl;
    file << "Remaining gold: " << team.getGold() << endl;
    file << "Remaining ingredients: " << team.getIngredients() << endl;
    file << "Remaining armor: " << team.getArmor() << endl;
    file << "Remaining keys: " << team.getKeys() << endl;
    file << "Remaining cookware:" << endl;
    file << "   Pots: " << team.getNumPots() << endl;
    file << "   Frying Pans: " << team.getNumPans() << endl;
    file << "   Cauldrons: " << team.getNumCauldrons() << endl;
    file << "Remaining weapons:" << endl;
    file << "   Clubs: " << team.getNumClubs() << endl;
    file << "   Spears: " << team.getNumSpears() << endl;
    file << "   Rapiers: " << team.getNumRapiers() << endl;
    file << "   Axes: " << team.getNumAxes() << endl;
    file << "   Longswords: " << team.getNumSwords() << endl;
    file << "Remaining treasures:" << endl;
    file << "   Silver Rings: " << team.getNumSilver() << endl;
    file << "   Ruby Necklaces: " << team.getNumRuby() << endl;
    file << "   Emerald Bracelets: " << team.getNumEmerald() << endl;
    file << "   Diamond Circlets: " << team.getNumDiamond() << endl;
    file << "   Gem-Encrusted Goblets: " << team.getNumGoblet() << endl;
    file << endl;
    file << "Rooms cleared: " << 5 - grid.getRoomCount() << "/5" << endl;
    file << "NPCs interacted with: " << 5 - grid.getNPCCount() << "/5" << endl;
    file.close();
}