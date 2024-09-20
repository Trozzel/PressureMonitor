//
// Created by George Ford on 10/22/21.
//
#include <thread>

#include "MccDio96H.hpp"
#include "DummyDevice.hpp"

int main()
{
  DummyDevice device;
  MccDio96H digObserver(&device);
  std::thread t(&DummyDevice::run, &device, 500);
  std::this_thread::sleep_for(std::chrono::seconds(10));
  device.stopDevice();
}