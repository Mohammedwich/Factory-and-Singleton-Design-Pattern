//============================================================================
// Name			: ScreenLogger.cpp
// Author		: Mohammed Ahmed
// Course		: UTDallas CS 1337.502 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :	cs1337Logger is an abstract factory-design class for FileLogger which logs messages to a file called Log.txt and for ScreenLogger which writes
//			the log messages to the console. The FileLogger's ofstream object opens the Log.txt file in append mode so multiple instances would write
//			to the same log file.
//
//	LogSingleton implements the singleton design method so we can use a single Logger. Whether it creates a ScreenLogger or a FileLogger depends on a
//	hard-coded integer 1 or 2 in the initialization of its static member.
//
//
//============================================================================

#include "ScreenLogger.h"
#include <iostream>

ScreenLogger::ScreenLogger()
{
	// TODO Auto-generated constructor stub

}

ScreenLogger::~ScreenLogger()
{
	// TODO Auto-generated destructor stub
}

void ScreenLogger::displayMessage(const char * theMessage)
{
	std::string message = theMessage;

	std::cout << message << std::endl;
}
