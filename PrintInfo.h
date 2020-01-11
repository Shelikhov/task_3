#pragma once
#include <iostream>
#include <string>
#include <ctime>

class PrintInfo{
public:
	void printMeta(std::string &name, const char* action, size_t size);//to output metadata
	char* currTime();//to output current time
private:
	std::time_t time;
};
