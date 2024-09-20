#include <iostream>
#include <utility>

#include "MccDio96H.hpp"

using namespace std;

// INITIALIZE STATIC VALUES
unsigned int MccDio96H::NUM_DEVICES = MCC_MAX_DEV_COUNT;

// CTOR
/******************************************************************************/
MccDio96H::MccDio96H(iObservableDevice* pObservableDevice,
                     BankNumber bankNumber) :
iDioObserver(pObservableDevice), _bankNumber(bankNumber)
{
  // 1. SET UP THE MCC DIO96 DEVICE COMMUNICATION
  _error = ulGetDaqDeviceInventory(_interfaceType, _devDescriptors,
                                   &NUM_DEVICES);
  handleError(_error); // throws error if there is an error

  // NOTE: This assumes that the DIO 96H is the only Measurement Computing
  // device
  _daqDeviceHandle = ulCreateDaqDevice(_devDescriptors[0]);

  if (_daqDeviceHandle == 0)
    throw runtime_error("Unable to create a handle to the specified DAQ device");

  // 3. CONNECT TO DIO 96H
  _error = ulConnectDaqDevice(_daqDeviceHandle);
  handleError(_error); // throws error if there is an error

  // 4. SET ALL PORTS TO OUTPUT AND ASSIGN _firstPort and _lastPort
  initPorts();

  // 5. LOAD POINTER TO THIS OBJECT IN AN OBSERVABLE (Ruska, Encoder, etc)
  if (_pObservableDevice)
    _pObservableDevice->loadObserver(this);
}

// DTOR
/******************************************************************************/
MccDio96H::~MccDio96H()
{
  // SET ALL OUTPUTS TO 0
  ULL portVals[] = {0,0,0,0, 0,0,0,0, 0,0,0,0};
  _error = ulDOutArray(_daqDeviceHandle, FIRSTPORTA, FOURTHPORTCH,
                       portVals);

  _pObservableDevice->removeObserver(this);
  ulDisconnectDaqDevice(_daqDeviceHandle);
  ulReleaseDaqDevice(_daqDeviceHandle);
}

// OPEN PORTS
/******************************************************************************/
void MccDio96H::openPorts()
{
	cout << "Opening ports..." << endl;
}

// CLOSE PORTS -
/******************************************************************************/
void MccDio96H::closePorts()
{
	cout << "Closing ports..." << endl;
}

// UPDATE - Obersever override
/******************************************************************************/
void MccDio96H::update(const std::string& data)
{
  static int ITERATION = 0;

  // TODO: Provide helper function to provide vector<long long> (6)
  stringstream ss;
  string numstr = data.substr(0,8); // include decimal
  ULL digVals[6] = {0,0,0, 0,0,0};
  int i = 0;
  bool isPositive = true;
  for(char dig : numstr)
  {
    if(dig == '.')
      continue;
    if (dig == '-')
    {
      isPositive = false;
      continue;
    }
    if (dig == '+')
      continue;

    ss << dig;
    ss >> digVals[i++];
    ss.str(string());
    ss.clear();
  }

  // Values sent to ports.
  // NOTE: portVals[5] only used for MCC_BANK3
  ULL portVals[6] = {0,0,0,0,0,0};

  switch (_bankNumber)
  {
  case MCC_BANK1:
    portVals[0] = digVals[0] | (digVals[1] << 4);
    portVals[1] = digVals[2] | (digVals[3] << 4);
    portVals[2] = digVals[4];
    portVals[3] = digVals[5];
    portVals[4] = (isPositive) ? 0 : 1; //  0b0000 0001
    break;
  case MCC_BANK2:
    portVals[0] = digVals[0] | (digVals[1] << 4);
    portVals[1] = digVals[2];
    portVals[2] = digVals[3];
    portVals[3] = digVals[4] | (digVals[5] << 4);
    portVals[4] = (isPositive) ? 0 : 1; //  0b0000 0001
    break;
  case MCC_BANK3:
    portVals[0] = digVals[0];
    portVals[1] = digVals[1];
    portVals[2] = digVals[2] | (digVals[3] << 4);
    portVals[3] = digVals[4] | (digVals[5] << 4);
    portVals[4] = (isPositive) ? 0 : 1; //  0b0000 0001
    portVals[5] = 0;
    break;
  }
  _error = ulDOutArray(_daqDeviceHandle, _firstPort, _lastPort, portVals);
  handleError(_error);
}

// INITIATE PORTs
/******************************************************************************/
void MccDio96H::initPorts()
{
  vector<DigitalPortType> ports;
  switch (_bankNumber)
  {
  case MCC_BANK1:
    _firstPort = FIRSTPORTA;
    _lastPort  = SECONDPORTA;
    ports.emplace_back(FIRSTPORTA);
    ports.emplace_back(FIRSTPORTB);
    ports.emplace_back(FIRSTPORTCL);
    ports.emplace_back(FIRSTPORTCH);
    ports.emplace_back(SECONDPORTA);
    break;
  case MCC_BANK2:
    _firstPort = SECONDPORTB;
    _lastPort  = THIRDPORTB;
    ports.emplace_back(SECONDPORTB);
    ports.emplace_back(SECONDPORTCL);
    ports.emplace_back(SECONDPORTCH);
    ports.emplace_back(THIRDPORTA);
    ports.emplace_back(THIRDPORTB);
    break;
  case MCC_BANK3:
    _firstPort = THIRDPORTCL;
    _lastPort  = FOURTHPORTCH;
    ports.emplace_back(THIRDPORTCL);
    ports.emplace_back(THIRDPORTCH);
    ports.emplace_back(FOURTHPORTA);
    ports.emplace_back(FOURTHPORTB);
    ports.emplace_back(FOURTHPORTCL);
    ports.emplace_back(FOURTHPORTCH);
    break;
  default:
    cerr << "__FILE__" << ": " << __LINE__ << endl;
    throw runtime_error("Invalid Bank Number");
  }
  for(auto port : ports)
  {
    _error = ulDConfigPort(_daqDeviceHandle, port, DD_OUTPUT);
    handleError(_error);
  }
}

// HANDLE ERROR
/******************************************************************************/
void MccDio96H::handleError(UlError error)
{
  if (error)
  {
    char errMsg[ERR_MSG_LEN];
    ulGetErrMsg(error, errMsg);
    cerr << "Measurement Computing Error Code: " << error << endl;
    throw runtime_error(errMsg);
  }
}
