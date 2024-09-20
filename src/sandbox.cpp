#include <thread>
#include <iostream>

#include "DummyDevice.hpp"
#include "DummyObserver.hpp"

using namespace std;

int main()
{
  DummyDevice device;
  DummyObserver observer {&device};

  thread t(&DummyDevice::run, &device, 500);
//  device.run(500);
  for(int i = 0; i < 25; ++i)
  {
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Printing from main thread: " << this_thread::get_id() << ": " << i
         << endl;
  }
  cout << "Stopping device..." << endl;
  device.stopDevice();

  t.join();
}