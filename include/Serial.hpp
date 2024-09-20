#ifndef __SERIAL_HPP__
#define __SERIAL_HPP__

#include <string>
#include <cstdio>

#include "serialib.h"
#include "ancillary.hpp"

using uint = unsigned int;

class Serial
{
private:
  serialib    _serial;
  std::string _port;
  uint        _baudRate;
  size_t      _bufferSize = 1024;

  // NOTE:   caller is unable to copy or move a Serial object.
  // REASON: only one Serial object per port
//   Serial(const Serial& src) = default;
//   Serial& operator=(const Serial& src) = default;
//  Serial(Serial&& src) noexcept;
//  Serial& operator=(Serial&& src) noexcept;
public:
  enum PortStatus {
    SUCCESS                  =  1,
    DEVICE_NOT_FOUND         = -1,
    ERROR_OPENING_DEVICE     = -2,
    ERROR_PORT_PARAMETERS    = -3,
    BAUD_RATE_NOT_RECOGNIZED = -4,
    PORT_PARAM_WRITE_ERROR   = -5,
    TIMEOUT_WRITE_ERROR      = -6
  };
  explicit Serial(std::string  port, uint baudRate=9600);
  virtual ~Serial();

  inline bool operator==(const Serial& serial)
  {
    return (_port == serial._port && _baudRate == serial._baudRate);
  }
  inline bool operator!=(const Serial& serial)
  {
    return !(operator==(serial));
  }

  // CHAR OPERATIONS
  /**************************************************************************/
  char writeChar(char) ;
  char readChar(char *pByte, uint timeOut_ms=0);

  // STRING OPERATIONS
//  char writeString(const std::string& str);
  char writeString(const char* str) ;
  int readString(char* receivedString,
                 char finalChar,
                 uint maxNbByte,
                 uint timeOut_ms=0);


  // BYTE ARRAY OPERATIONS
  char writeBytes(const void* buffer, uint nbBytes);
  int readBytes(void* buffer, uint maxNbBytes, uint timeOut_ms=0,
                uint sleepDuration_us=100);

  // SPECIAL OPERATIONS
  // Empty the received buffer
  char flushReceiver();

  // return the number of bytes in the received buffer
  int numBytesAvailable();


  // GETTER AND SETTERS
  void setBaudRate(uint baudRate)         { _baudRate = baudRate; }
  [[nodiscard]] uint getBaudRate() const  { return _baudRate;     }

  [[nodiscard]] std::string getPort() const { return _port; }
  void setPort(const std::string& port)     { _port = port; }

  void displayStatus(PortStatus status);
};

#endif // __SERIAL_HPP__
