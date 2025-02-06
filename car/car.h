#include <string>



class car
{
	public:
		car();
		car(std::string name, int speed, int control);
		
		//destructor
		~car();
		
		//accessor methods
		std::string getName();
		void setName(std::string name);
		int getSpeed();
		void setSpeed(int speed);
		int getControl();
		void setControl(int control);
		int getlapNumber();
		void setlapNumber(int lapNumber);
	private:
	
	std::string name_;
	int speed_;
	int control_;
	int lapNumber_;
};