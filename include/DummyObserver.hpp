//
// Created by George Ford on 9/24/21.
//

#ifndef SKERLBOX_DUMMYOBSERVER_H
#define SKERLBOX_DUMMYOBSERVER_H

#include <string>
#include <iostream>

#include "iDioObserver.hpp"

class DummyObserver : public iDioObserver
{
private:
  int count{0};
public:
  explicit DummyObserver(iObservableDevice* pObservableDevice=nullptr);

  void update(const std::string& data) override;

  void openPorts() override;
  void closePorts() override;
};


#endif //SKERLBOX_DUMMYOBSERVER_H
