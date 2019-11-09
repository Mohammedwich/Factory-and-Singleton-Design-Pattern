//============================================================================
// Name			: FileLogger.cpp
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

#include "FileLogger.h"
#include <iostream>
#include <fstream>


FileLogger::FileLogger()
{
	if(!(fileWriter.is_open()) )
	{
		fileWriter.open("Log.txt", std::ofstream::out | std::ofstream::app);
	}

	if(fileWriter.is_open() )
	{
		std::cout << "file was opened successfully." << std::endl << std::endl;
	}

	if(!(fileWriter.is_open()) )
	{
		std::cout << "file was not opened successfully." << std::endl << std::endl;
		exit(-1);
	}


}

FileLogger::~FileLogger()
{
	if(fileWriter.is_open() == true)
	{
		fileWriter.close();
		std::cout << "A FileLogger object was destroyed and its file was closed." << std::endl << std::endl;
	}
}

void FileLogger::displayMessage(const char * theMessage)
{
	std::string message = theMessage;

	if(fileWriter.is_open() == true)
	{
		fileWriter << message << "\n";
		fileWriter.flush();
	}
	else
	{
		std::cout << "Cannot write log to file" << std::endl;
	}
}
