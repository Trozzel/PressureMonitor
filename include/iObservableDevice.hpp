//
// Created by george on 9/22/21.

#ifndef __IOBSERVABLEDEVICE_HPP__
#define __IOBSERVABLEDEVICE_HPP__

#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>

#include "Observer.hpp"
#include "ancillary.hpp"

// IOBSERVABLEDEVICE
/* Devices like Ruska, Laurel panel meter, and any other device that interacts
 * directly with hardware that produces data is an observable device.
 * The _observers represent hardware (or anything) that is updated upon the
 * observable device receiving data
 */
class iObservableDevice
{
protected:
  std::vector<Observer*> _observers;
  bool _stopDevice = false;
public:
  explicit iObservableDevice() = default;
  virtual ~iObservableDevice() = default;

  iObservableDevice(const iObservableDevice& src);

  virtual void loadObserver(Observer* observer);
	virtual void removeObserver(Observer* observer);
	virtual void notifyObservers(const std::string& data);
  virtual std::string getData() = 0;
  virtual void run(int time_ms) = 0;
  inline void stopDevice() { _stopDevice = true; } // Allows observer to stop device
};

#endif //  __IOBSERVABLEDEVICE_HPP__
