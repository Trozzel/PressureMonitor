#include <iostream>
#include <thread>

#include "Ruska.hpp"
#include "MccDio96H.hpp"

using namespace std;

int main()
{
  Ruska ruska{"/dev/tty.usbserial-A6031LVH"};
  MccDio96H digOutDevice(&ruska);

  thread t(&Ruska::run, &ruska, 10000);

  char response {};
  cout << "Enter 'q' to quit: ";
  while (response != 'q' && response != 'Q')
    cin >> response;
  ruska.stopDevice();
  t.join();
//  ruska.run(500);
}

