#include "PrintInfo.h"

char* PrintInfo::currTime(){
        time = std::time(nullptr);
        return std::asctime(std::localtime(&time));
}

void PrintInfo::printMeta(std::string &name, const char* action, size_t size){
	std::cout << name << " " << action << " " << size << " bytes." << " " << currTime() << std::endl;
}
