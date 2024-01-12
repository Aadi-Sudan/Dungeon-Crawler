#ifndef TEAMMATE_H
#define TEAMMATE_H

#include <iostream>

using namespace std;

class Teammate
{
private:

    string name_;
    int stamina_;

public:

    // constructors
    Teammate();
    Teammate(string name, int stamina);

    // getters
    string getName();
    int getStamina();

    // setters
    void setName(string name);
    void changeStamina(int stamina);
};

#endif