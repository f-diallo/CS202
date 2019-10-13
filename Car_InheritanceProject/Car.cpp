
//Car.cpp

#include <iostream>
#include <fstream>

#include "Vehicle.h"
#include "Car.h"
#include <cstring>

using namespace std;


//default ctor
Car::Car()
{
	//ctor
	cout<<"Car #"<<getVin()<<": Default-ctor\n";
}

//parameterized ctor
Car::Car(char* plates, const int vin, float* lla): Vehicle(vin, lla), m_throttle(0)
{
	strcpy(m_plates, plates);
	setLla(lla);

	cout<<"Car #"<<vin<<" Parameterized-ctor\n";

}

//copy ctor
Car::Car(Car &obj)
{
	setPlates(obj.m_plates);
	setThrottle(obj.m_throttle);
	setLla(obj.m_lla);
	cout<< "Car #"<<obj.m_vin<<": Copy-ctor\n";

}

//dtor
Car::~Car()
{
	cout << "Car #" << getVin() << " Dtor\n";
}



//operator- function
void Car:: operator-(Car &c1)
{
//	 v1.m_vin = getVin();
	 for (int i = 0; i < 3; i++)
	 {
		 m_lla[i] = c1.m_lla[i];
	 }
	 cout << "Car #" << getVin() << ": Assignment\n";
}

//get functions
char *Car:: getPlates()		{return m_plates; }
int Car:: getThrottle()		{return m_throttle; }


//set functions
void Car::setPlates(char plates[256])	{strcpy(m_plates, plates); }
void Car::setThrottle(int throttle)	{m_throttle = throttle; }


//drive function
void Car::drive(int throttle)
{
	setThrottle(throttle);

}

//move function
void Car:: move(float* lla)
{
	cout<<"Car #"<<getVin() <<": DRIVE to destination with throttle @ 75\n";
	drive(75);
	setLla(lla);

}

//friend insertion operator<< function
ostream & operator<<(ostream& os, const Car& car)
{
	os << "Car #" << car.m_vin; 
	 


	os <<" Plates: ";
	
	for(int i=0; car.m_plates[i] != '\0'; i++)
	{
		os<<car.m_plates[i];
	}
	os<< ", Throttle: "<< car.m_throttle<< " @ [" ;
	for (int i = 0; i < 3; i++)
	{
		 os << car.m_lla[i];
		 if (i < 2)
			 os << ", ";
		 if (i == 2)
			 os << "]\n";
	}
	// << m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2] << "]\n";
	 return os;
 }






