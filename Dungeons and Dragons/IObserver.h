//This is part of the Observer Pattern
//This is the Observer Interface from which observer classes will implement
//It is used to observe "Observables" or "Subject" (basically any changing model classes)

#pragma once


#include <iostream>
#include <string>
#include "ICharacter.h"


class IObserver
{
	public:		
		
		//Observers get their views updated whenever notified by a updated observable
		virtual void update(ICharacter*) = 0;	
};