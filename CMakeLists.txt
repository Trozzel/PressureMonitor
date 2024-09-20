cmake_minimum_required(VERSION 3.15)
project(SkerlBox)

# ADD BOOST FOR lexical_cast<int>
#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)
#find_package(Boost REQUIRED)

include_directories(
		include
		serialib
		/usr/local/include/skerlbox
		/usr/local/libuldaq-1.2.0/src
		/usr/local/libuldaq-1.2.0/examples
)

# GET ACCESS TO libuldaq.dylib
link_directories(/usr/local/lib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

# SANDBOX
################################################################################
#add_executable(Sandbox
#		src/ancillary.cpp
#		src/DummyDevice.cpp
#		src/DummyObserver.cpp
#		src/iDioObserver.cpp
#		src/iObservableDevice.cpp
#		src/Observer.cpp
#		src/sandbox.cpp
#		)

# SANDBOX LIBRARY
################################################################################
#add_library(sandboxLibrary SHARED
#		src/ancillary.cpp
#		src/DummyDevice.cpp
#		src/DummyObserver.cpp
#		src/iDioObserver.cpp
#		src/iObservableDevice.cpp
#		src/Observer.cpp
#		src/MccDio96H.cpp
#		src/Serial.cpp
#		serialib/serialib.cpp
#)
#target_link_libraries(sandboxLibrary
#		uldaq
#		)
#
#install(TARGETS sandboxLibrary DESTINATION /usr/local/lib)

# RUSKA_DIO LIBRARY
################################################################################
add_library(ruska_digout SHARED
		src/ancillary.cpp
		src/DummyDevice.cpp
		src/DummyObserver.cpp
		src/iDioObserver.cpp
		src/iObservableDevice.cpp
		src/Observer.cpp
		src/Ruska.cpp
		src/MccDio96H.cpp
		src/Serial.cpp
		serialib/serialib.cpp
		)
target_link_libraries(ruska_digout
		uldaq
		)

install(TARGETS ruska_digout DESTINATION /usr/local/lib)

# SERIAL TEST
################################################################################
#add_executable(serialTest
#		src/serialTest.cpp
#		src/Serial.cpp
#		src/bcd.cpp
#		serialib/serialib.cpp
#		)

# MCCDIO96HTEST
################################################################################
#add_executable(mccDio96HTest
#		src/dioTest.cpp
##		src/BcdDigOut.cpp
#		)
#
#target_link_libraries(mccDio96HTest
#		uldaq
#		)

# RUSKATEST
################################################################################
#add_executable(ruskaTest
#		src/ruskaTest.cpp
#		src/bcd.cpp
#		src/DummyDevice.cpp
#		src/DummyObserver.cpp
#		src/iDioObserver.cpp
#		src/iObservableDevice.cpp
#		src/MccDio96H.cpp
#		src/Observer.cpp
#		src/Ruska.cpp
#		src/RuskaObserver.cpp
#		src/Serial.cpp
#		serialib/serialib.cpp
#)
#
#target_link_libraries(ruskaTest
#		uldaq
#		)

# RUSKATEST
################################################################################
#add_executable(MCC96HTest
#		src/mccH96Test.cpp
#		src/DummyDevice.cpp
#		src/DummyObserver.cpp
#		src/iDioObserver.cpp
#		src/iObservableDevice.cpp
#		src/MccDio96H.cpp
#		src/Observer.cpp
#		serialib/serialib.cpp
#		)
#
#target_link_libraries(MCC96HTest
#		uldaq
#		)

# MAIN
################################################################################
add_executable(RuskaDigOut
		src/main.cpp
		src/DummyDevice.cpp
		src/DummyObserver.cpp
		src/iDioObserver.cpp
		src/iObservableDevice.cpp
		src/MccDio96H.cpp
		src/Observer.cpp
		src/Ruska.cpp
		src/Serial.cpp
		serialib/serialib.cpp
		)

target_link_libraries(RuskaDigOut
		uldaq
		)

# SERIAL COMMUNICATION LIBRARY
################################################################################
add_library(rs232 SHARED
		src/Serial.cpp
		serialib/serialib.cpp
		)

install(TARGETS rs232 DESTINATION /usr/local/lib)

# SKERLBOX VERIFY
################################################################################
add_executable(SkerlBoxVerify
		demo/SkerlBoxVerify.cpp
		)

target_link_libraries(SkerlBoxVerify
		uldaq
		)
