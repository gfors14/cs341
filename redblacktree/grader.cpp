#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>

void calculateLetterGrade(double numGrade, char & letterGrade);

int main()
{
	//initilizing variables and welcome statements
	std::string fileName("");
	std::cout << "Welcome to Connor's Grade Calculator" << std::endl;	
	std::cout << "\nPlease enter the file you wish to open: ";
	std::cin >> fileName;
	std::ifstream input(fileName);
	std::ofstream output;
	std::string numberString("");
	std::string category("");
	int count(0);
	double sum(0), totalGrade(0);
	char letterGrade;
	//checks if the file that the user wants to read is a valid file.
	if(input.is_open())
	{
		std::cout << "\nReading from file " << fileName << "..." << std::endl;
		//there can be a different number of elements, but there are only 8 lines in the input file, no matter what. because we read two lines at a time, we only need the for loop to run four times.
		for(int i(0); i < 4; i++)
		{
			category = "";
			std::getline(input, category);
			sum = 0;
			count = 0;
			std::getline(input, numberString);
			std::stringstream numberList(numberString);
			//gets all the values from numList and gets rid of the comma. this also takes the average of all the values using a counter, which would still work if there were multiple finals, for example. right now final is being divided by counter as 1.
			while(numberList.good())
			{
				std::string grade("");       
				getline(numberList, grade, ',' );   
				int x(0);
				std::stringstream converter;
				converter << grade;
				converter >> x;
				sum = sum + x;
				count++;
			}
			sum = sum / count;
			//grade multiplier based on the category value
			if(category == "Assignments")
			{
				sum = sum * 0.5;
			}
			else if(category == "Participation")
			{
				sum = sum * 0.1;
			}
			else if(category == "Midterm")
			{
				sum = sum * 0.2;
			}
			else
			{
				sum = sum * 0.2;
			} 
			totalGrade = totalGrade + sum;
		}
		//calls the function and saves number grade and letter grade to a file that the user chooses. we do not need an else here because if the file does not exist the computer will create it
		calculateLetterGrade(totalGrade, letterGrade);
		std::cout << "\nSave to (Filename): ";
		std::cin >> fileName;
		output.open(fileName);
		output << totalGrade << "\t" << letterGrade;
		output.close();
		std::cout << "\nScore & Letter Grade written to file: " << fileName << std::endl;
		
	}
	//if the file that the user wants to read cannot open, this prints
	else
	{
		std::cout << "\nUnable to open file!" << std::endl;
	}
	//closes the input and says goodbye
	input.close();
	std::cout << "\nThank you for using my program - good bye!" << std::endl;
	return 0;
}
//copy and pasted from an earlier in class exercise, compares the numGrade to the values to determine what letterGrade is using else ifs.
void calculateLetterGrade(double numGrade, char & letterGrade)
{
	std::cout << "\nCalculating grades..." << std::endl;
	if(numGrade >= 90)
	{
		letterGrade = 'A';
	}
	else if(numGrade < 90 && numGrade >= 80)
	{
		letterGrade = 'B';
	}
	else if(numGrade < 80 && numGrade >= 70)
	{
		letterGrade = 'C';
	}
	else if(numGrade < 70 && numGrade >= 60)
	{
		letterGrade = 'D';
	}
	else
	{
		letterGrade = 'F';
	}
}