#pragma once
#include "Logger.h"
class FileLogger : public Logger
{
public:
	void log(const string& msg)override {}

private:
	string filePath;
};

