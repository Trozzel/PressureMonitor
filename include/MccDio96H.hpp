#ifndef __MCCDIO96H_HPP__
#define  __MCCDIO96H_HPP__

#include <string>
#include <vector>
#include <sstream>

#include "uldaq.h"
#include "iDioObserver.hpp"
#include "iObservableDevice.hpp"

constexpr int MCC_MAX_DEV_COUNT { 10 };

/** \brief DIO96H is broken into 3 banks of 32 channels
 *
 * MCC_BANK1: FIRSTPORTA
 *            FIRSTPORTB
 *            FIRSTPORTCL  and FIRSTPORTCH
 *            SECONDPORTA
 * MCC_BANK2: SECONDPORTB
 *            SECONDPORTCL and SECONDPORTCH
 *            THIRDPORTA
 *            THIRDPORTB
 * MCC_BANK3: THIRDPORTCL  and THIRDPORTCH
 *            FOURTHPORTA
 *            FOURTHPORTB
 *            FOURTHPORTCL and FOURTHPORTCH
 */
typedef enum
{
  MCC_BANK1 = 1,
  MCC_BANK2,
  MCC_BANK3
} BankNumber;

using ULL = unsigned long long;

// CONCRETE OBSERVER
class MccDio96H : public iDioObserver
{
private:
  static unsigned int NUM_DEVICES;

  UlError _error                       = ERR_NO_ERROR;
  BankNumber          _bankNumber;
  DaqDeviceDescriptor _devDescriptors[MCC_MAX_DEV_COUNT];
  DaqDeviceInterface  _interfaceType   = USB_IFC;
  DaqDeviceHandle     _daqDeviceHandle = 0;
  DigitalPortType     _firstPort       = FIRSTPORTA;  // For MCC_BANK1
  DigitalPortType     _lastPort        = SECONDPORTA; // For MCC_BANK1

  /**
   * \brief Sets pertinent ports to output and sets _firstPort and _lastPort
   */
  void initPorts();

public:
  explicit MccDio96H(iObservableDevice* pObservableDevice = nullptr,
                     BankNumber bankNumber=BankNumber::MCC_BANK1);
  ~MccDio96H() override;

  void openPorts() override;
  void closePorts() override;

  void update(const std::string& data) override;

  static void handleError(UlError error);
};

#endif // __MCCDIO96H_HPP__
