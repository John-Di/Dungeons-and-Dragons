//Part of the Builder pattern
//This is the Fighter builder Interface
//This interface allows us to build multiple types of Fighters without having to know which type until runtime using polymorphism

#include "IFighterBuilder.h"


//Sorts generated stats for the Fighter in descending order
void IFighterBuilder::sortStats(int roll1, int roll2, int roll3, int roll4, int roll5, int roll6)
{

	//By the rules of d20, we set the fighter stats based on:
	//2 + the intelligence modifier 
	//that sum times 4 if this is the Fighter's first level (ie level = 1)
	//plus the sum of the 3 highest values of 4 d6 dice rolls
	
	stats[0]= roll1;
	stats[1]= roll2;
	stats[2]= roll3;
	stats[3]= roll4;
	stats[4]= roll5;
	stats[5]= roll6;
		

	std::sort(std::begin(stats), std::end(stats));			//Sort the array of stats in ascending order
	std::reverse(std::begin(stats), std::end(stats));		//Reverses array to make it sorted by descending order

}