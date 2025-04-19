#pragma once
#include "Logger.h"
class FileLogger : public Logger
{
public:
	FileLogger(string filePath);
	void log(const string& msg)override;

private:
	string filePath;
};

