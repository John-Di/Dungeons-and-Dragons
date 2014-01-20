//This class contains utility used for Dungeons and Dragons
//It currently contains dice rolling and the ability modifier equation


#pragma once
#ifndef DICE_H
#define DICE_H


#include <stdlib.h> 
#include <algorithm>
#include <iostream>
#include <time.h> 
#include "SystemTimeDelay.h"

using namespace std;

namespace d20
{
	class Dice		//Used to generate random values for dice rolls
	{
		public:
			//Roll a dice between 1 and size
			static int roll(int);

			//Roll four 6-sided dice and return the sum of the 3 biggest values
			static int roll4D6();
	};

	class Modifier
	{
		public:

			//Ability score modifier equation
			static int ability(int);
	};

}

#endif