//
// Created by George Ford on 9/24/21.
//
#include "../include/Observer.hpp"

using namespace std;

// CTOR
/******************************************************************************/
Observer::Observer(iObservableDevice* pObservableDevice) :
  _pObservableDevice(pObservableDevice)
{}

// ADD OBSERVABLE
/******************************************************************************/
void Observer::addObservable(iObservableDevice* pObservableDevice)
{
  _pObservableDevice = pObservableDevice;
}

