#pragma once

#include <iostream>
#include <ostream>
#include <istream>

using namespace std;

class Config
{
	static ofstream outfile;
	static ifstream infile;
	static bool useCustomOutStream;
	static bool useCustomInStream;
public:
	Config();
	~Config();
	
	static ostream&  DefaultOutStream();
	static istream&  DefaultInStream();
	static void Intialize(bool customOutStream, bool customInStream);
	static void CleanUp();

};

