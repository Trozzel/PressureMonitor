//
// Created by George Ford on 9/30/21.
//
#include <iostream>
#include <iomanip>
#include <vector>

#include "Serial.hpp"
#include "bcd.hpp"

using namespace std;

int main()
{
  const size_t BUFFER_SZ = 1024;

  Serial serial("/dev/tty.usbserial-A6031LVH");

  // USING CHAR BY CHAR
  cout << "CHAR BY CHAR" << endl;
  serial.writeString("*IDN?\n");
  char idn[BUFFER_SZ];
  serial.readString(idn, '\n', BUFFER_SZ);
  cout << idn << endl;

  // GET PRESSURE WITH CUSTOM WRITE
  cout << "Custom string write" << endl;
  serial.writeString("MEAS:PRES?\n");
  char pressureStr[BUFFER_SZ];
  serial.readString(pressureStr, '\n', BUFFER_SZ);
  cout << pressureStr << endl;

  string pstr{pressureStr};
  vector<vector<bool> > bcdNum = getBcdVector_<24>(as_const(pstr));
  cout << bcdNum;
}