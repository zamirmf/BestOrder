#pragma once

#include <string>

class ErrorLog
{
	public:
		//Unique access provider of this class. Following a singleton pattern.
		static ErrorLog& GetInstance();
		//Updates the file to be used as a log
		static void SetLogFile(char* fileName);
		//Provides a simple way of sending data to be logged
		void operator<<(const char* message);	
	private:		
		//Initializes member variables
		ErrorLog();
		//Declared to keep GetInstance as exclusive point of access
		ErrorLog(const ErrorLog& obj);
		//Declared to keep GetInstance as exclusive point of access
		ErrorLog& operator=(const ErrorLog& obj);			
		//Contains the file name
		std::string fileName;
};