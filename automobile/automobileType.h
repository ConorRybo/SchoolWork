/*
Conor Rybacki
csc1720-01
2/26/2019
automobileType header file;
*/
#ifndef autoType
#define autoType
#include <string>
using namespace std;

class automobileType
{
private:
	float odometer;
	float efficiency;
	float fuelLevel;
	float maxFuel;

public:
	const float DEFAULT_FUEL_LEVEL = 0;
	const float DEFAULT_EFFICIENCY = 25;
	const float DEFAULT_MAX_FUEL = 40;
	string displayStatus() const;
	//This function will display the current status of the car
	//Postcondition: The values of odometer, efficency, and fuelLevel will be output
	void driveCar(int);
	//This function will simulate driving the car. The user should input the desired amount of miles
	//they want to drive. If the entered parameter is negative, it will treat it as driving in reverse
	//Postcondition: the odometer and fuelLevel will be adjusted acording to the user input
	void setCar(float, float);
	/*This function will allow the user to set the efficency and fuelLevel
	(in that order), and the odometer will be set to zero. Efficiency must
	be greater than zero, if not it none of the values will be changed.
	Same rules apply to fuelLevel
	Postcondition:efficency, maxFuel and fuelLevel will be set to desired values
	*/
	float getFuelLevel() const;
	//Postcondition: returns the value of fuelLevel
	float getOdometer() const;
	//Postcondition: returns the value of odometer
	float getEfficiency() const;
	//Postcondition: returns the value of efficiency
	float getMaxFuel() const;
	//Postcondition: returns the value of maxFuel
	void addFuel(float);
	/*Function that will add fuel to the current fuelLevel.
	Only will allow it to add up to the maxFuel Level
	Postcondition: fuelLevle + specified value;
	*/
	void setOdometer(float) ;
	/*Function that will allow the user to change the miles on the odometer
	They will not be allowed set it to a lower value than it is currently at
	Postcondition: odometer + specified value;
	*/
	void setEfficiency(float);
	/*This function will set the efficiency
	Value cannot be zero or below
	Postcondition: efficiency = specified value;*/
	void setMaxFuel(float);
	//This function will set the maximum fuel Level
	//Postcondition: maxFuel = specified value;
	automobileType();
	//Default constructor that will set all of the values to zero if the
	//user doesn't specify
	//Postcondition: odometer, efficency and fuelLevel will all equal zero
	automobileType(float, float, float);
	//Constructor with parameters that allows the user to set efficency, maxFuel and fuelLevel
	//(in that order), odometer will automatically be set to zero
	//Postcondition: odometer = 0; efficency, fuelLevel, and maxFuel will be set to desired values

};
#endif
