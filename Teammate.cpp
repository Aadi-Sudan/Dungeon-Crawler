#include <iostream>
#include <string>
#include "Teammate.h"

using namespace std;

/*
    Default constructor
*/
Teammate::Teammate(){
    name_ = "";
    stamina_ = -1;
}

/*
    Parameterized constructor
*/
Teammate::Teammate(string name, int stamina){
    name_ = name;
    stamina_ = stamina;
}

/*
    Getter for the name string
*/
string Teammate::getName(){
    return name_;
}

/*
    Setter for the name string
*/
void Teammate::setName(string name){
    name_ = name;
}

/*
    Getter for the stamina int
*/
int Teammate::getStamina(){
    return stamina_;
}

/*
    Setter for the stamina int, adds the parameter to the preexisting stamina
*/
void Teammate::changeStamina(int stamina){
    stamina_ += stamina;
}