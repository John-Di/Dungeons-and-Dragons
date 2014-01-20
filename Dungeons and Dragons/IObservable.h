//This is part of the Observer Pattern
//Any class that inherits from the Observable Interface has a list of observers (views)
//Whenever an Observable changes certain fields, it will notify all the views
//In turn, the views will update themselves and display the newest Observables (model classes)

#pragma once


#include <list>
#include <iostream>
#include <string>

using namespace std;

class IObserver;
class ICharacter;

class IObservable
{
	private:
		
		//List of Observers that follow this particular Observable
		list<IObserver*> observers;

	public:
		
		virtual ~IObservable();

		//Add an Observer to the list
		void attach(IObserver*);

		//Remove an Observer from the list
		void detach(IObserver*);
		
		//Notfify ALL Observers that a Character has changed
		void notify(ICharacter&);
};