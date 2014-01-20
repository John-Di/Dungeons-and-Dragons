//Part of the observer patter. 
//This is the Console Output. 
//When the Character's stats update, it will display the new stats to the console

#pragma once


#include <iostream>
#include <string>
#include "IObserver.h"

using namespace std;


class Console : public IObserver
{
	public:
		
		Console();

		//update the console with the newly changed Character
		void IObserver::update(ICharacter*);
};
