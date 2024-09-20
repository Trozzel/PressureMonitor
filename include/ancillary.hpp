#ifndef __ANCILLARY_HPP__
#define __ANCILLARY_HPP__

#include <string>
#include <memory>
#include <iostream>

#ifndef sptr
#define sptr std::shared_ptr
#endif

#ifndef DEBUG_PRINT
#define DEBUG_PRINT(arg) cout << (arg) << ": file: " << __FILE__ \
                              << " on line: "  << __LINE__<< endl;
#endif

namespace dev
{
	typedef enum
	{
		RUSKA9050_PRESSURE,
    LAUREL_ENCODER
	} ObservableDevice;

	typedef enum
	{
		MCC_DIO96H
	} DigitalIODevice;

	// GET DEVICE STRING FUNCTIONS
	std::string observableDeviceName(dev::ObservableDevice deviceType);
	std::string digitalIODeviceName(dev::DigitalIODevice deviceType);
};

#endif // __ANCILLARY_HPP__
