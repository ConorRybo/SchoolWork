/*
Conor Rybacki
csc1720-01
2/26/2019
automobileType implementation file;
*/

#include <iostream>
#include <string>
#include "automobileType.h"
using namespace std;

//method to display the status of the car
string automobileType::displayStatus() const{
	string status;
	status = "Odometer: " + to_string(odometer) + " miles " + "\n" + "MPG: " + to_string(efficiency)  + " miles/gallon" + "\n"
	 + "Fuel Level: " + to_string(fuelLevel) + " gallons" + "\n" + "Max Fuel Level: " + to_string(maxFuel) + " gallons";

	return status;
}

//method to simulate driving the car
void automobileType::driveCar(int a){
	if(a < 0){
		a = a*(-1);
	}
	if(a >= (fuelLevel* efficiency)){
		odometer += (fuelLevel * efficiency);
		fuelLevel = 0;
	}
	else{
		odometer += a;
		fuelLevel = fuelLevel - (a/efficiency);
	}

}

//method that allows us to set the MPG and fuelLevel of the car
void automobileType::setCar(float x, float y){
	bool check=0;
	if(x < 0){
		cerr << "In setCar: Invalid MPG; Must be above 0. No values set." << endl;
		check = true;
	}
	if(y > maxFuel || y <= 0){
		cerr << "In setCar: Invalid fuel level; Must be above 0 or below maxFuel level. No values set." << endl;
		check = true;
	}
	if(!check){
		efficiency = x;
		fuelLevel = y;
	}
}

//method that returns the value of fuelLevel
float automobileType::getFuelLevel() const{
		return fuelLevel;
}

//method that returns th value of odometer
float automobileType::getOdometer() const{
		return odometer;
}

//method that returns the value of efficiency
float automobileType::getEfficiency() const{
		return efficiency;
}

//method that returns the value of maxFuel
float automobileType::getMaxFuel() const{
	return maxFuel;
}

//method to add fuel to fuelLevel
void automobileType::addFuel(float x){
			if(x >= 0 && (fuelLevel + x) <= maxFuel){
				fuelLevel += x;
			}
			else if((fuelLevel + x)> maxFuel){
				cerr << "In addFuel: Invalid Parameter; Trying to add too much fuel. Tank filled." << endl;
				fuelLevel = maxFuel;
			}
			else{
				cerr << "In addFuel: Invalid Parameter; Cannot add negative gallons of fuel. No fuel added." << endl;
			}
}

//method to set the Odometer
void automobileType::setOdometer(float x){
	if(x >= odometer){
		odometer = x;
	}
	else{
		cerr << "In setOdometer: Invalid Parameter; Cannot turn back odometer. Value not changed." << endl;
	}
}

//method to setEfficiency
void automobileType::setEfficiency(float x){
	if(x > 0){
		efficiency = x;
	}
	else{
		cerr << "In setEfficiency: Invalid Parameter; Efficency cannot be less than or equal to zero. Value not changed." << endl;
	}
}

//method to set the maxFuel value
void automobileType::setMaxFuel(float x){
	if(x > 0){
		maxFuel = x;
	}
	else{
		cerr << "In setMaxFuel: Invalid Parameter; Max fuel level cannot be 0 or below. Value not changed." << endl;
	}
}

//default constructor
automobileType::automobileType(){
	odometer = 0;
	efficiency = 0;
	fuelLevel = 0;
	maxFuel = 0;
}

//parameterized constructor
automobileType::automobileType(float m, float t, float f){
	odometer = 0;
	bool a=0, b=0, c=0;
	if(m <= 0){
		cerr << "In parameterized constructor: Invalid MPG; Must be above 0. Value defaulted to 25." << endl;
		a = true;
		efficiency = DEFAULT_EFFICIENCY;
	}
	if(t <= 0){
		cerr << "In parameterized constructor: Invalid maxFuel Level; Must be above 0. Value defaulted to 40." << endl;
		b = true;
		maxFuel = DEFAULT_MAX_FUEL;
	}
	if(f > t || f <= 0){
		cerr << "In parameterized constructor: Invalid Fuel Level; Must be above 0 or below (or equal to) maxFuel. Value defaulted to 0." << endl;
		c = true;
		fuelLevel = DEFAULT_FUEL_LEVEL;
	}
	if(!a){
		efficiency = m;
	}
	if(!b){
		maxFuel = t;
	}
	if(!c){
		fuelLevel = f;
	}
}
