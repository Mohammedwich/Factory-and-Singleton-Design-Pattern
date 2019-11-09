//============================================================================
// Name			: cs1337Logger.cpp
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

#include "cs1337Logger.h"
#include "ScreenLogger.h"
#include "FileLogger.h"
#include <iostream>

cs1337Logger::cs1337Logger() : loggingEnabled(false)
{
	// TODO Auto-generated constructor stub

}

cs1337Logger::~cs1337Logger()
{
	// TODO Auto-generated destructor stub
}

void cs1337Logger::setLogging(bool theBool)
{
	loggingEnabled = theBool;

	if (loggingEnabled == true)
	{
		std::cout << "Logging was toggled on." << std::endl << std::endl;
	}

	if (loggingEnabled == false)
		{
			std::cout << std::endl << "Logging was toggled off." << std::endl << std::endl;
		}
}

void cs1337Logger::logMessage(const char * message)
{
	if(loggingEnabled == true)
	{
		displayMessage(message);
	}
	else
	{
		std::cout << "Logging is off. The message was not logged." << std::endl << std::endl;
	}
}

cs1337Logger * cs1337Logger::createLogger(int loggerType)
{
	if(loggerType == 1)
	{
		return new ScreenLogger();
	}
	else if(loggerType == 2)
	{
		return new FileLogger();
	}
	else
	{
		std::cout << "Failed to create logger. Returned NULL." << std::endl;
		return NULL;
	}
}


