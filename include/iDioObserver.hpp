#ifndef __IDIOOBSERVER_HPP__
#define __IDIOOBSERVER_HPP__

#include <string>

#include "ancillary.hpp"
#include "Observer.hpp"
#include "iObservableDevice.hpp" //Observable class

class iDioObserver : public Observer
{
public:
	explicit iDioObserver(iObservableDevice* pObservableDevice);
  virtual ~iDioObserver() = default;
  virtual void openPorts()  = 0;
  virtual void closePorts() = 0;
};

#endif // __IDIOOBSERVER_HPP__
