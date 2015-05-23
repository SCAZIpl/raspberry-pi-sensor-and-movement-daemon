#ifndef application_hpp
#define application_hpp

#include "twiWrapper.hpp"
#include "roMeoWrapper.hpp"
#include "logger.hpp"
#include "applicationInterface.hpp"

#define ARDUINO_ADDRESS 0x47
#define I2C_FOLDER "/dev/i2c-1"

using namespace std;

class Application: public ApplicationInterface{
	private:
		RoMeoWrapper* romeo;
		Logger*	logger;
		
		int sid;
		
		Application();
		
		
		void sensorsActions();
		void serverActions();
		
	public:
		void init();
		void cycle();
	
		Application(int sid);
		~Application();
};
		Application::Application(int sid){
			this->sid=sid;
			init();
		}

		void Application::init(){
			romeo = new RoMeoWrapper(I2C_FOLDER,ARDUINO_ADDRESS);
			logger = new Logger("/var/log/raspberrydaemon/log");
		}
		
		void Application::cycle(){
			logger->log(this->sid);
			
			this->sensorsActions();
			
			this->serverActions();
		}

		
		void Application::sensorsActions(){}
		void Application::serverActions(){}
		
		
#endif






