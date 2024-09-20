#ifndef __RUSKA_HPP__
#define __RUSKA_HPP__

#include <string>
#include <vector>
#include <memory>

#include "Serial.hpp"
#include "iObservableDevice.hpp"
#include "bcd.hpp"
#include "ancillary.hpp"

using uint = unsigned;

#ifndef MAX_BYTES
#define MAX_BYTES 1024
#endif

// iObservableDevice provide loadObserver
class Ruska : public iObservableDevice
{ 
private:
  Serial _serial;
	uint   _baudRate;
////  // NOTE: Caller is unable to copy or move a Ruska object
//  Ruska(const Ruska& src) = default;
//  Ruska& operator=(const Ruska& src) ;

public:
  explicit Ruska(const string& port, uint baudRate= 9600);
  ~Ruska() override = default;

  inline bool operator==(const Ruska& src);
  inline bool operator!=(const Ruska& src);

  std::string getPort();
  void setPort(std::string& port);

  std::string getIDN();
  std::string getData() override; // GET PRESSURE

  void run(int time_ms) override;
};

#endif // __RUSKA_HPP__
