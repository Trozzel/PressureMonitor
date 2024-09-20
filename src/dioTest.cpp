//
// Created by George Ford on 10/13/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "uldaq.h"

#define MAX_DEV_COUNT  100
#define MAX_STR_LENGTH 64

using namespace std;
using ULL = unsigned long long;

int main()
{
  UlError error {};

  DaqDeviceDescriptor descriptors[MAX_DEV_COUNT];
  DaqDeviceInterface  interface = USB_IFC;
  DaqDeviceHandle     handle = 0;
  vector<DigitalPortType> ports = {FIRSTPORTA,  FIRSTPORTB,
                                   FIRSTPORTCL, FIRSTPORTCH};
  DigitalPortIoType portIoType = DPIOT_IO;
  uint numDevs = MAX_DEV_COUNT;

  // GET DESCRIPTORS AND HANDLE TO DEVICE
  error = ulGetDaqDeviceInventory(interface, descriptors, &numDevs);
  cout << "Currently using: " << descriptors[0].productName << endl;
  handle = ulCreateDaqDevice(descriptors[0]);
  cout << "Device handle number: " << handle << endl;

  // ESTABLISH THE CONNECTION
  error = ulConnectDaqDevice(handle);
  if (error)
    cerr << "Received error on connection: " << error << endl;

  long long numPorts {};
  error = ulDIOGetInfo(handle, DIO_INFO_NUM_PORTS, 0, &numPorts);
  if (error)
    cerr << "ERROR getting number of ports: ERROR CODE: " << error << endl;
  else
    cout << "Total number of ports: " << numPorts << endl;

  // WRITE DATA TO PORTS
  int val = 0;
  for(auto port : ports)
  {
    error = ulDConfigPort(handle, port, DD_OUTPUT);
    if (error)
      cerr << "Error, " << error << ", on " << port << endl;

    val = (port == FIRSTPORTCL) ? 1 : 0;
    error = ulDOut(handle, port, val);
    if (error)
    {
      cerr << "Error on port " << port << endl;
      break;
    }
  }

  ULL array[4] = {
    3 | (3<<4),
    7 | (7<<4),
    15,
    15
  };

  error = ulDOutArray(handle, ports[0], ports[3], array);
  if (error)
    cerr << "Error writing array: " << error << endl;

  ulDisconnectDaqDevice(handle);
  ulReleaseDaqDevice(handle);
}