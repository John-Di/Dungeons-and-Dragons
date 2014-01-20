//This is part of the Observer Pattern
//Any class that inherits from the Observable Interface has a list of observers (views)
//Whenever an Observable changes certain fields, it will notify all the views
//In turn, the views will update themselves and display the newest Observables (model classes)

#include "IObservable.h"
#include "IObserver.h"


IObservable::~IObservable()
{
	observers.clear();
}

//Notfify ALL Observers that a Character has changed
void IObservable::notify(ICharacter& c)
{
	list<IObserver*>::iterator it = observers.begin();

	ICharacter* ch = &c;

	for(IObserver* ob: observers)
	{
		ob -> update(ch);
	}
}

//Add an Observer to the list
void IObservable::attach(IObserver* obs)
{
	observers.push_back(obs);
}

//Remove an Observer from the list
void IObservable::detach(IObserver* obs)
{
	observers.remove(obs);
}
