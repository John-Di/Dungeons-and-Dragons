//Part of the observer patter. 
//This is the Console Output. 
//When the Character's stats update, it will display the new stats to the console

#pragma once

#include "Console.h"
#include <iostream>

using namespace std;

Console::Console(){}

//update the console with the newly changed Character
void Console::update(ICharacter* c)
{
	ICharacter* character = c;
	cout << character -> toString();
}

