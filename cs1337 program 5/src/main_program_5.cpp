//============================================================================
// Name			: main_program_5.cpp
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
#include "LogSingleton.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;


char * messageOne();
char * messageTwo();
void messageThree();


int main()
{
	cs1337Logger * loggerObject = LogSingleton::getLogger();

	//Try to log with logging set to off
	loggerObject->logMessage(messageOne());

	//Set logging to on and then log a message.
	loggerObject->setLogging(true);
	loggerObject->logMessage(messageTwo());

	//Toggle logging back to off and try to log functionOne() again.
	loggerObject->setLogging(false);
	loggerObject->logMessage(messageOne());

	//Making two logger objects and instantiating them through the singleton class
	cs1337Logger * loggerObject2 = LogSingleton::getLogger();
	cout << "The following two objects should have the same address since they were instantiated with the singleton class." << endl;
	cout << "The address of loggerObject: " << loggerObject << endl;
	cout << "The address of loggerObject2: " << loggerObject2 << endl;

	messageThree();


	cout << endl << endl;

	//create a logger objects outside of the singleton
	ScreenLogger aScreenLogger;

	aScreenLogger.setLogging(true);
	aScreenLogger.logMessage("I, aScreenLogger, am not a singleton-made logger.");
	cout << "The address of aScreenLogger: " << &loggerObject << endl;


	return 0;
}



char * messageOne()
{
	cout << "Trying to log messageOne..." << endl;
	return (char*)"Message one was logged";
}

char * messageTwo()
{
	cout << "Trying to log messageTwo..." << endl;
	return (char*)"Message two was logged";
}

void messageThree()
{
	cs1337Logger * loggerObject = LogSingleton::getLogger();
	loggerObject->setLogging(true);
	loggerObject->logMessage("messageThree() was entered.");

	loggerObject->setLogging(false);
	loggerObject->logMessage("messageThree() was exiting.");
}



