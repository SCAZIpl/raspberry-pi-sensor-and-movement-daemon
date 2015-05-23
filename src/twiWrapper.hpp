#ifndef twiWrapper_hpp
#define twiWrapper_hpp


#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>

class TwiWrapper {

  private:
    TwiWrapper();
	
	int file;
	
	char filename[20];
	
	int address; 
		
  public:
	TwiWrapper(char* folder,int address);
	
	int initializeConnection();	
	
	void closeConnection();
	
	int sendByteToRegister(uint8_t reg,uint8_t data){
		return i2c_smbus_write_byte_data(this->file,reg,data);
	}
	
};

	TwiWrapper::TwiWrapper(char* folder,int address){
		this->address = address;
		sprintf(this->filename,folder);
	}


	void TwiWrapper::closeConnection(){
		close(this->file);
	}
	
	int TwiWrapper::initializeConnection(){
		if ((this->file = open(this->filename,O_RDWR)) < 0) {
			return 0x01;
		}

		if (ioctl(this->file,I2C_SLAVE,this->address) < 0) {
			return 0x02;
		}
		
		return 0x00;
	}


#endif






