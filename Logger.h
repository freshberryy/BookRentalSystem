#pragma once
#include<iostream>
#include<string>
using namespace std;

class Logger
{
public:
	virtual void log(const string& msg) = 0;
	virtual ~Logger() = default;
};

