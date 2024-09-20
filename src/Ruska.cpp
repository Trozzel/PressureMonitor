#include "../include/Ruska.hpp"

using namespace std;

// CTOR
/******************************************************************************/
Ruska::Ruska(const string& port, uint baudRate) :
  iObservableDevice(),
  _baudRate(baudRate),
  _serial(Serial(port, baudRate))
{
  // Instantiate the Serial object
}

// DTOR - delete _serial
/******************************************************************************/
//Ruska::~Ruska()
//{
//}
//
//// COPY CTOR
///******************************************************************************/
//Ruska::Ruska(const Ruska& src) :
//  iObservableDevice(src)
// {
//  if (this != &src)
//  {
//    _serial  = src._serial;
//    _baudRate = src._baudRate;
//  }
//}
//
//// COPY ASSIGNMENT
///******************************************************************************/
//Ruska& Ruska::operator=(const Ruska& src)
//{
//  iObservableDevice::operator=(src);
//  // DO NOT CREATE ANOTHER Serial* ON THE HEAP
//  // Ruska object will share it access to the Serial device
//  if (this != &src)
//  {
//    if (*this == src)
//    {
//      _serial = src._serial;
//      _baudRate = src._baudRate;
//    }
//  }
//  return *this;
//}
//
//// MOVE CTOR
///******************************************************************************/
//Ruska::Ruska(Ruska&& src) noexcept
//{
//  iObservableDevice::operator=(src);
//  if (this != &src)
//  {
//    _serial = nullptr;
//    _serial.swap(src._serial);
//    _baudRate = src._baudRate;
//  }
//}
//
//// MOVE ASSIGNMENT
///******************************************************************************/
//Ruska& Ruska::operator=(Ruska&& src) noexcept
//{
//  iObservableDevice::operator=(src);
//  if (this != &src)
//  {
//    _serial = nullptr;
//    _serial.swap(src._serial);
//    _baudRate = src._baudRate;
//  }
//  return *this;
//}

// COMPARISON OPERATORS
/******************************************************************************/
bool Ruska::operator==(const Ruska& src)
{
  return (_serial == src._serial && _baudRate == src._baudRate);
}

bool Ruska::operator!=(const Ruska& src)
{
  return !(operator==(src));
}

// SET SERIAL PORT
/******************************************************************************/
void Ruska::setPort(std::string& port)
{
  _serial.setPort(port);
}

// GET SERIAL PORT
/******************************************************************************/
std::string Ruska::getPort()
{
  return _serial.getPort();
}

// GET IDN
/******************************************************************************/
std::string Ruska::getIDN()
{
  _serial.writeString("*IDN?\n");
  char data[MAX_BYTES];
  char finalChar {'\n'};
  _serial.readString(data, finalChar, MAX_BYTES);
  return data; // implicit conversion to std::string
}

// GET PRESSURE STRING
/******************************************************************************/
std::string Ruska::getData()
{
  _serial.writeString("MEAS:PRES?\n");
  char data[MAX_BYTES];
  char finalChar {'\n'};
  _serial.readString(data, finalChar, MAX_BYTES);

  // Notify observers automatically
  notifyObservers(data); // implicit conversion to std::string
  return data;                // implicit conversion to std::string
}

void Ruska::run(int time_ms)
{
  while(!_stopDevice)
  {
    getData();
    this_thread::sleep_for(chrono::milliseconds(time_ms));
  }
}



