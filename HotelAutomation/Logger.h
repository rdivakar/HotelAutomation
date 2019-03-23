#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <time.h>
#include <stdarg.h>
#include <sstream>
using namespace std;

class Logger
{
	static Logger *logInstance;
	ofstream outfile;
	Logger();
	~Logger();
	static string GetTime();
public:
	static Logger* GetLoggerInstance();
	
	void Log(const char* message,...);
};

