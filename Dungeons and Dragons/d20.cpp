//This class contains utility used for Dungeons and Dragons
//It currently contains dice rolling and the ability modifier equation

#pragma once

#include "d20.h"

using namespace d20;

//Generates a random number between 1 and size 
int Dice::roll(int size) 
{
	delay(200);							//A time delay of 150ms is required to make the random values not the same

	srand (time(NULL));					//Generates a random based on the current time in ms
	int random =  rand() % size  + 1 ;	//The random generated is between 1 and the size of the die
	return random;
}

//Rolls four 6-sided dice and returns the sum of the 3 highest values (used for ability scores)
int Dice::roll4D6()
{
	int rolls [4] = {roll(6), roll(6), roll(6), roll(6)};
	std::sort(std::begin(rolls), std::end(rolls));

	return rolls [1] + rolls [2] + rolls [3];
}

//Ability modifiers used when calculating ability scores
int Modifier::ability(int ability)
{
	return 	(ability - 10) / 2;		//By definition, this is how an ability modifier is calculated. May occasionally cause for a negative stat.
}