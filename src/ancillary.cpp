#include "../include/ancillary.hpp"

using namespace std;

// GET OBSERVABLE DEVICE NAME
/******************************************************************************/
string dev::observableDeviceName(dev::ObservableDevice deviceType)
{
	string deviceName{};
	switch (deviceType)
	{
		case dev::RUSKA9050_PRESSURE:
			deviceName = "Ruska 9050";
			break;
		case LAUREL_ENCODER:
			deviceName = "Laurel Encoder";
			break;
		default:
			deviceName = "Invalid device!!!";
			break;
	}
	return deviceName;
}

// GET DIGITAL IO DEVICE NAME
/******************************************************************************/
string digitalIODeviceName(dev::DigitalIODevice deviceType)
{
	string deviceName{};
	switch (deviceType)
	{
		case dev::MCC_DIO96H:
			deviceName = "Measurement Computing DIO96H";
			break;
		default:
			deviceName = "Invalid device!!!";
			break;
	}
	return deviceName;
}
