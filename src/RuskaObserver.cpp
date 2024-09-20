//
// Created by George Ford on 10/7/21.
//

#include "RuskaObserver.hpp"
#include "bcd.hpp"
using namespace std;

// CTOR
RuskaObserver::RuskaObserver(iObservableDevice* pObservableDevice) :
  iDioObserver(pObservableDevice)
{}

void RuskaObserver::update(const string& data)
{
  auto vecBcd24 = getBcdVector_<24>(data);
  cout << vecBcd24 << endl;
}

void RuskaObserver::openPorts()
{
  cout << "Closing ports\n";
}

void RuskaObserver::closePorts()
{
  cout << "Opening ports\n";
}
