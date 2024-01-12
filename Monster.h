#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>

using namespace std;

class Monster
{
private:

    string name_;
    int level_;

public:

    // constructors
    Monster();
    Monster(string name, int level);

    // getters
    string getName();
    int getLevel();

    // setters
    void setName(string name);
    void setLevel(int level);
};

#endif