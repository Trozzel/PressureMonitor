//
// Created by George Ford on 9/24/21.
//

#ifndef SKERLBOX_DUMMYDEVICE_H
#define SKERLBOX_DUMMYDEVICE_H

#include <string>

#include "iObservableDevice.hpp"

class DummyDevice : public iObservableDevice
{
public:
  void run(int time_ms) override;

  std::string getData() override;
};


#endif //SKERLBOX_DUMMYDEVICE_H
