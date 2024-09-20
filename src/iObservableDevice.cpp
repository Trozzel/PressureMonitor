//
// Created by george on 9/22/21.
//
#include "../include/iObservableDevice.hpp"

using namespace std;

// COPY CTOR
/******************************************************************************/
iObservableDevice::iObservableDevice(const iObservableDevice& src)
{
  _observers = src._observers;
}

// LOAD OBSERVER
/******************************************************************************/
void iObservableDevice::loadObserver(Observer* observer)
{
	_observers.push_back(observer);
}

// DELETE OBSERVER
/******************************************************************************/
void iObservableDevice::removeObserver(Observer* observer)
{
	_observers.erase(remove(_observers.begin(), _observers.end(),
                          observer), _observers.end());
}

// NOTIFY OBSERVERS
/******************************************************************************/
void iObservableDevice::notifyObservers(const string& data)
{	
	for (auto& observer : _observers)
		observer->update(data);
}

