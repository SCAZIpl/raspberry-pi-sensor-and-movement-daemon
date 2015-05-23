#ifndef logger_hpp
#define logger_hpp

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Logger{
	private:
		ofstream logfile;
		Logger();
		string currentDateTime();
	public:
		Logger(string name);
		void log(string content);
		void log(int content);
		~Logger(); 
};

string Logger::currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    return buf;
}


Logger::Logger(string name){
	logfile.open (name.c_str());
}

void Logger::log(string content){
	logfile << currentDateTime() << "::" << content << endl;
}

void Logger::log(int content){
	logfile << currentDateTime() << "::" << content << endl;
}


Logger::~Logger(){
	logfile.close ();
}
		
#endif






