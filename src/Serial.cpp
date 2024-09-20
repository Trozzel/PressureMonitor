#include "../include/Serial.hpp"

#include <utility>

using namespace std;
// CTOR
/******************************************************************************/
Serial::Serial(std::string port, const uint baudRate) :
        _port(std::move(port)), _baudRate(baudRate)
{
  char status = _serial.openDevice(_port.c_str(), _baudRate);
  displayStatus(PortStatus(status));
}

// DTOR
/******************************************************************************/
Serial::~Serial()
{
    // RAII - close resource in DTOR
    if (_serial.available())
        _serial.flushReceiver();
    _serial.closeDevice();
}

// COMPARISON OPERATORS

// WRITE CHAR
/******************************************************************************/
char Serial::writeChar(char c)
{
    return _serial.writeChar(c);
}

// READ CHAR
/******************************************************************************/
char Serial::readChar(char *pByte, const uint timeOut_ms)
{
    return _serial.readChar(pByte, timeOut_ms);
}

// WRITE STRING
/******************************************************************************/
char Serial::writeString(const char* str)
{
  assert(strlen(str) <= _bufferSize);
  while(*str != '\0')
    writeChar(*str++);
  return 0;
}

// READ STRING
/******************************************************************************/
int Serial::readString(char *receivedString, char finalChar, uint maxNbBytes,
                       const uint timeOut_ms)
{
  return _serial.readString(receivedString, finalChar, maxNbBytes, timeOut_ms);
}
// WRITE BYTES
/******************************************************************************/
char Serial::writeBytes(const void *buffer, const uint nbBytes)
{
    return _serial.writeBytes(buffer, nbBytes);
}
// READ BYTES
/******************************************************************************/
int Serial::readBytes(void *buffer, uint maxNbBytes, const uint timeOut_ms,
                      uint sleepDuration_us)
{
  return _serial.readBytes(buffer, maxNbBytes, timeOut_ms, sleepDuration_us);
}

// FLUSH RECEIVER
/******************************************************************************/
char Serial::flushReceiver()
{
    return _serial.flushReceiver();
}

// NUMBER OF BYTES AVAILABLE
/******************************************************************************/
int Serial::numBytesAvailable()
{
    return _serial.available();
}

void Serial::displayStatus(Serial::PortStatus status)
{
  switch (status)
  {
  case SUCCESS:
    cout << "Success opening port: ";
    break;
  case DEVICE_NOT_FOUND:
    cout << "Device not found: ";
    break;
  case ERROR_OPENING_DEVICE:
    cout << "Error opening device: ";
    break;
  case ERROR_PORT_PARAMETERS:
    cout << "Error with port parameters: ";
    break;
  case BAUD_RATE_NOT_RECOGNIZED:
    cout << "Baud rate not recognized: ";
    break;
  case PORT_PARAM_WRITE_ERROR:
    cout << "Port parameters write error: ";
    break;
  case TIMEOUT_WRITE_ERROR:
    cout << "Timeout write error: ";
    break;
  default:
    cout << "Invalid port ";
    break;
  }
  cout << _port << endl;
}






