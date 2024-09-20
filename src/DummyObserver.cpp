//
// Created by George Ford on 9/24/21.
//

#include "DummyObserver.hpp"

using namespace std;

DummyObserver::DummyObserver(iObservableDevice* pObservableDevice) :
  iDioObserver(pObservableDevice)
{
  // ASSIGN THE OBSERVABLE DEVICE TO FOLLOW
  if (_pObservableDevice) // assigned in call to base constructor
  {
    this->addObservable(_pObservableDevice);
    _pObservableDevice->loadObserver(this);
  }
}


void DummyObserver::update(const string& data)
{
  cout << "Data from Device:   " << data << endl;
  cout << "Data from Observer: " << count++ << endl;
}

void DummyObserver::openPorts()
{
  cout << "Opening dummy ports" << endl;
}

void DummyObserver::closePorts()
{
  cout << "Closing dummy ports" << endl;
}

