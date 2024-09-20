//
// Created by george on 9/22/21.
//

#ifndef __SKERLBOX_OBSERVER_H__
#define __SKERLBOX_OBSERVER_H__

#include <string>
#include <memory>

// Forward declare iObservableDevice to prevent include recursion
class iObservableDevice;

class Observer
{
protected:
  iObservableDevice* _pObservableDevice;
public:
  explicit Observer(iObservableDevice* pObservableDevice);
  virtual void addObservable(iObservableDevice* pObservableDevice);
  virtual void update(const std::string& data) = 0;
};

#endif //__SKERLBOX_OBSERVER_H__
