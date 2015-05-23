#ifndef roMeoWrapper_hpp
#define roMeoWrapper_hpp

#include "twiWrapper.hpp"
#include "movement.hpp"

class RoMeoWrapper : public TwiWrapper,public Movement{

	private:
			static const uint8_t ledState = 1;
			static const uint8_t leftEnginePWM = 4;
			static const uint8_t rightEnginePWM = 5;
			static const uint8_t leftEngineDirection = 6;
			static const uint8_t rightEngineDirection = 7;
	
			static const uint8_t forward  = 1;
			static const uint8_t backward = 0;
		RoMeoWrapper();
		
	public:
		RoMeoWrapper(char* folder,int address);
		void rightForward(uint8_t speed);
		void leftForward(uint8_t speed);
		void rightBackward(uint8_t speed);
		void leftBackward(uint8_t speed);
};

		RoMeoWrapper::RoMeoWrapper(char* folder,int address)
		:TwiWrapper(folder,address)
		{}	
		
		void RoMeoWrapper::rightForward(uint8_t speed){
			sendByteToRegister(RoMeoWrapper::rightEngineDirection,RoMeoWrapper::forward);
			sendByteToRegister(RoMeoWrapper::rightEnginePWM,speed);		
		}
		void RoMeoWrapper::leftForward(uint8_t speed){
			sendByteToRegister(RoMeoWrapper::leftEngineDirection,RoMeoWrapper::forward);
			sendByteToRegister(RoMeoWrapper::leftEnginePWM,speed);		
		}
		
		
		void RoMeoWrapper::rightBackward(uint8_t speed){
			sendByteToRegister(RoMeoWrapper::rightEngineDirection,RoMeoWrapper::backward);
			sendByteToRegister(RoMeoWrapper::rightEnginePWM,speed);		
		}
		
		void RoMeoWrapper::leftBackward(uint8_t speed){
			sendByteToRegister(RoMeoWrapper::leftEngineDirection,RoMeoWrapper::backward);
			sendByteToRegister(RoMeoWrapper::leftEnginePWM,speed);		
		}
		
#endif






