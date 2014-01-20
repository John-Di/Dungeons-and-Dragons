//Part of the Builder Pattern
//The Creator is the class that receives a builder type and builds an object based on that builder's typing
//This is the Fighter Creator and based on it's received Builder, it will build either a Bully Fighter, a Nimble Fighter or a Tank Fighter.

#pragma once

#include "IFighterBuilder.h"


class FighterCreator
{
	private:

		IFighterBuilder* builder;

	public:
		//setter
		void setBuilder(IFighterBuilder*);

		//Returns a constructed Fighter class of the same type as the current builder. 
		//It takes a Fighter's name and level into consideration.
		Fighter* getFighter(string, int);
};

