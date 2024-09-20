//
// Created by George Ford on 10/7/21.
//

#include "Ruska.hpp"
#include "RuskaObserver.hpp"

using namespace std;

int main()
{
  Ruska ruska{"/dev/tty.usbserial-A6031LVH"};
  RuskaObserver observer {&ruska};

  ruska.run(500);
}
