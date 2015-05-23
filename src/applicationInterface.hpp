#ifndef applicationinterface_hpp
#define applicationinterface_hpp

class ApplicationInterface{
	public:
		virtual void init() = 0;
		virtual void cycle() = 0;
};
		
#endif






