#include <iostream> 
#include <string>
#include <fstream>
#include "car.h"
#include <sstream>

void Race(car car[]);

int main()
{
	std::cout << "Welcome to the 2020 Indianapolis 500 Race Simulator!!!" << std::endl;
	std::ifstream input("indy500.txt");
	std::string line("");
	
	car carArray[100];
	std::string name("");
//	int speed(0);
//	int control(0);
	std::string speedStr("");
	std::string controlStr("");
	int i(0);
	std::string first("");

	if(input.is_open())
	
	{
		while(!input.eof())
		{
			while (getline(input, line))
			{
				std::stringstream ss(line);
				std::getline(ss, name, ' ');
				std::getline(ss, speedStr, ' ');
				std::getline(ss, controlStr, ' ');
				
				int speed = stoi(speedStr);
				int control = stoi(controlStr);
				
			//	std::cout << name << std::endl;
			//	std::cout << speed << std::endl;
			//	std::cout << control << std::endl;
			//	std::cout << line << std::endl;
				car car1;
				
				
				
				car1.setName(name);
				car1.setSpeed(speed);
				car1.setControl(control);
				carArray[i]=car1;
				i++;
			}
				
			
		}	
	input.close();
	}
	Race(carArray);
	
	return 0;
}

void Race(car car[])
{
	//random number generator
	srand((unsigned) time(0));
	int random(0);
	
	//while no winner, control >5
	//control / random + speed
	bool complete = false;
	std::string first(" ");
	std::string name(" ");
	int lapNumber = 0;
	int speed = 0;
	int control = 0;
	
	
	
	while(complete != true)
	{
		for(int i=0; i<33; i++)
		{
			lapNumber = car[i].getlapNumber();
			speed = car[i].getSpeed();
			control = car[i].getControl();
			
			if(control > 5)
			{
				random = (rand() % 10) + 1;
				car[i].setlapNumber(lapNumber+(control/random) + speed);
			}
			else
			{
				car[i].setlapNumber(lapNumber + speed);
			}
			
			lapNumber = car[i].getlapNumber();
			
			if(lapNumber >= 200)
			{
				complete = true;
				car[i].setlapNumber(200);
				first = car[i].getName();
				
				break;
			}
			else
			{
				
			}
			
			
		}
		
	}
	std::cout << "********* " << first << " has won the 2022 Indianapolis 500!!!!! *********" << std::endl;
	std::cout << "Driver name: Lap Number:" << std::endl;
	
	for(int i=0; i<33; i++)
	{
		lapNumber= car[i].getlapNumber();
		name = car[i].getName();
		std::cout << name << ": " << lapNumber << std::endl;
	}
	
	
}

