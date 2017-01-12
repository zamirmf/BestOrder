#pragma once

#include <exception>

class ArrayOutOfRange : public std::exception
{
	public:
		const char* what() const throw()
		{
			return "Exception: Array Out of Range!";
		}
};
class FileOpenError : public std::exception
{
	public:		
		const char* what() const throw()
		{
			return "Exception: Error opening file!";
		}
};
class FileWrongFormat : public std::exception
{
	public:
		const char* what() const throw()
		{
			return "Exception: File has wrong format!";
		}
};


