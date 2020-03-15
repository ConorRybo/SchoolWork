/*
Conor Rybacki
csc1720-01
2/26/2019
Main function to test automobileType
*/

#include <iostream>
#include <string>
#include "automobileType.h"
using namespace std;

int main(){
	//creating 2 objects
	//testing how my code reacts to invalid parameters
	cout << endl << "Instanciating an object called myCar with an efficiency of -20, maxFuel level of 30 and fuelLevel of 70." << endl;
	automobileType myCar(-20, 30, 70);
	//making sure my code works with valid parameters
	cout << "Instanciating an object called yourCar with efficiency of 30, maxFuel level of 60 and fuelLevel of 30." << endl;
	automobileType yourCar(30, 60, 50);
	//making sure my default constructor works
	cout << "Instanciating an obect called ourCar with the default constructor." << endl;
	automobileType ourCar;
	//displaying the cars before being edited
	cout << endl;
	cout << "My car before being changed:" << endl;
	cout << myCar.displayStatus() << endl << endl;
	cout << "Your car before being changed:" << endl;
	cout << yourCar.displayStatus() << endl << endl;
	cout << "Our car before being changed:" << endl;
	cout << ourCar.displayStatus() << endl << endl;

	cout << "Because our car was instanciated using the default constructor, lets set its values: " << endl;
	//testing my set functions
	ourCar.setOdometer(15000);
	ourCar.setEfficiency(15);
	ourCar.setMaxFuel(60);
	ourCar.addFuel(30);
	//testing our get functions
	cout << "Our car's odometer after being set to 15000: " << ourCar.getOdometer() << " miles" << endl;
	cout << "Our car's efficiency after being set to 15: " << ourCar.getEfficiency() << " MPG" << endl;
	cout << "Our car's max fuel level after being set to 60: " << ourCar.getMaxFuel() << " gallons" << endl;
	cout << "Our car's fuel level after adding 30 gallons to the tank: " << ourCar.getFuelLevel() << " gallons" << endl << endl;

	//filling myCar with fuel
	cout << "Because my car doesn't have any gas in it, lets try to add 500 gallons: " << endl;
	myCar.addFuel(500);
	cout << "Fuel Level: " << myCar.getFuelLevel() << " gallons" << endl << endl;

	//testing my drive functions
	cout << "My car after trying to be driven 100 miles: " << endl;
	myCar.driveCar(100);
	cout << myCar.displayStatus() << endl << endl;
	cout << "Your car after being driven in reverse 20 miles: " << endl;
	yourCar.driveCar(-20);
	cout << yourCar.displayStatus() << endl << endl;
	cout << "Our car after trying to be driven 1000 miles: " << endl;
	ourCar.driveCar(1000);
	cout << ourCar.displayStatus() << endl << endl;

	//testing set my setCar function
	cout << "Testing my set car function " << endl;
	cout << "Trying to set my cars efficiency to -20 and fuel level to 30:" << endl;
	myCar.setCar(-20, 30);
	cout << "My cars efficiency: " << myCar.getEfficiency() << " MPG" << endl;
	cout << "My cars fuel level: " << myCar.getFuelLevel() << " gallons" << endl << endl;

	//trying to set our cars odometer back
	cout << "Trying to turn back the odometer in our car: " << endl;
	ourCar.setOdometer(100);
	cout << "Our cars odometer: " << ourCar.getOdometer() << " miles" << endl << endl;

	cout << "Filling all the cars with gas, taking a 500 mile roadtrip and then displaying their status: " << endl;
	myCar.addFuel(1000);
	yourCar.addFuel(1000);
	ourCar.addFuel(1000);

	cout << "My car before the trip:" << endl;
	cout << myCar.displayStatus() << endl << endl;
	cout << "Your car before the trip:" << endl;
	cout << yourCar.displayStatus() << endl << endl;
	cout << "Our car before the trip:" << endl;
	cout << ourCar.displayStatus() << endl << endl;

	myCar.driveCar(500);
	yourCar.driveCar(500);
	ourCar.driveCar(500);

	cout << "My car after the trip:" << endl;
	cout << myCar.displayStatus() << endl << endl;
	cout << "Your car after the trip:" << endl;
	cout << yourCar.displayStatus() << endl << endl;
	cout << "Our car after the trip:" << endl;
	cout << ourCar.displayStatus() << endl << endl;


	return 0;
}
