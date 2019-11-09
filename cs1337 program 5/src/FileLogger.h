//============================================================================
// Name			: FileLogger.h
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

#ifndef FILELOGGER_H_
#define FILELOGGER_H_

#include "cs1337Logger.h"
#include <iostream>
#include <fstream>


class FileLogger: public cs1337Logger
{

public:
	FileLogger();
	virtual ~FileLogger();

	void displayMessage(const char *);

private:
	std::ofstream fileWriter;

};

#endif /* FILELOGGER_H_ */
