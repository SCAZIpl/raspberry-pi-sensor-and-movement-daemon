#ifndef movement_hpp
#define movement_hpp

class Movement{
	public:
		virtual  void rightForward(uint8_t)  = 0;
		virtual  void leftForward(uint8_t) 	 = 0;
		virtual  void rightBackward(uint8_t)  = 0;
		virtual  void leftBackward(uint8_t)	 = 0;
};

		
#endif






