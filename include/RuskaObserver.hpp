//
// Created by George Ford on 10/7/21.
//

#ifndef SKERLBOX_RUSKAOBSERVER_H
#define SKERLBOX_RUSKAOBSERVER_H


#include <string>
#include <iostream>

#include "iDioObserver.hpp"

class RuskaObserver : public iDioObserver
{
private:
  int count{0};
public:
  explicit RuskaObserver(iObservableDevice* pObservableDevice);

  void update(const std::string& data) override;

  void openPorts() override;
  void closePorts() override;
};


#endif //SKERLBOX_RUSKAOBSERVER_H
