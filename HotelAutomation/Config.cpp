#include "stdafx.h"
#include "Config.h"

/*
	An Utility class
*/

ofstream Config::outfile;
ifstream Config::infile;
bool Config::useCustomInStream = false;
bool Config::useCustomOutStream = false;

Config::Config()
{
}


Config::~Config()
{

}

ostream & Config::DefaultOutStream()
{
	if (useCustomOutStream)//For Unit testing purpose
	{
		if (outfile.is_open() == false)
		{
			outfile.open("output.txt", ios::trunc);
		}
		return outfile;
	}

	return std::cout;
}

istream & Config::DefaultInStream()
{
	if (useCustomInStream)////For Unit testing purpose
	{
		if (infile.is_open() == false)
		{
			infile.open("input.txt");
		}
		return infile;
	}
	return cin;
}

void Config::Intialize(bool customOutStream, bool customInStream)
{
	useCustomOutStream = customOutStream;
	useCustomInStream = customInStream;
}

void Config::CleanUp()
{
	if (useCustomOutStream)//To test the code
	{
		outfile.close();
	}
	if (useCustomInStream)
	{
		infile.close();
	}
}


