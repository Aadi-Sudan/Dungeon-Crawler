#include <iostream>
#include <string>
#include "Monster.h"

using namespace std;

/*
    Default constructor
*/
Monster::Monster(){
    name_ = "";
    level_ = -1;
}

/*
    Parameterized constructor
*/
Monster::Monster(string name, int level){
    name_ = name;
    level_ = level;
}

/*
    Getter for the name string
*/
string Monster::getName(){
    return name_;
}

/*
    Setter for the name string
*/
void Monster::setName(string name){
    name_ = name;
}

/*
    Getter for the level int
*/
int Monster::getLevel(){
    return level_;
}

/*
    Setter for the level int
*/
void Monster::setLevel(int level){
    level_ = level;
}