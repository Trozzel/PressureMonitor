#include "../include/iDioObserver.hpp"

using namespace std;

// CTOR
/******************************************************************************/
iDioObserver::iDioObserver(iObservableDevice* pObservableDevice) :
  Observer(pObservableDevice)
{
  this->_pObservableDevice = pObservableDevice;
}

