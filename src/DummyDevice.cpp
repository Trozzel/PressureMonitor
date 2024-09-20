//
// Created by George Ford on 9/24/21.
//
#include <random>

#include "DummyDevice.hpp"

using namespace std;

// GET DATA - override
/******************************************************************************/
std::string DummyDevice::getData()
{
  static std::default_random_engine e;
  static std::uniform_real_distribution<> dis(0, 1); // rage 0 - 1

  string data { std::to_string(dis(e)) };
  notifyObservers(data);
  return data;
}

// RUN TIMED LOOP
/******************************************************************************/
void DummyDevice::run(int time_ms)
{
  while(!_stopDevice)
  {
    getData();
    this_thread::sleep_for(chrono::milliseconds(time_ms));
  }
}
