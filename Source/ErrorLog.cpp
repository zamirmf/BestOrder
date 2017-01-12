#include "ErrorLog.h"
#include <fstream>

/*static*/ ErrorLog& ErrorLog::GetInstance()
{
	static ErrorLog errorLog;	
	return errorLog;
}
/*static*/ void ErrorLog::SetLogFile(char* fileName)
{
	if((fileName) && (ErrorLog::GetInstance().fileName.compare(fileName)))
	{
		ErrorLog::GetInstance().fileName = fileName;
	}
}
void ErrorLog::operator<<(const char* message)
{
	if (!message)
		return;
	std::ofstream file(this->fileName.c_str(),std::ios_base::out|std::ios_base::app);
	if (file.is_open())
	{
		file << message << std::endl;
		file.close();
	}
}
ErrorLog::ErrorLog() : fileName("ErrorLog.txt") 
{
	
}
ErrorLog::ErrorLog(const ErrorLog& obj) 
{
	
}
ErrorLog& ErrorLog::operator=(const ErrorLog& obj) 
{
	
}
