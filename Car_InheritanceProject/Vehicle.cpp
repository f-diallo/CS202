
//Vehicle.cpp

#include <iostream>
#include <fstream>

#include "Vehicle.h"
#include "Car.h"
#include <cstring>

using namespace std;


//initialize s_idgen to 0 somewhere, then increment
//if use parameterized ctor where vin is given, just increment from there


int Vehicle::s_idgen=0;

//default constructor
 Vehicle:: Vehicle(): m_vin(s_idgen++)
{
	//ctor
	 cout<< "Vehicle #" <<getVin()<<": Default-ctor\n";

}

 //parameterized constructor
 Vehicle::Vehicle(const int vin, float *lla): m_vin(vin < s_idgen ? s_idgen++ : vin)
 {
	 setLla(lla);
	 //initializer list checks if vin is same or exists
	 cout<< "Vehicle #" <<m_vin<<": Parameterized-ctor\n";

 }

 //copy constructor
 Vehicle::Vehicle(Vehicle &obj)
 {
	 //initializer list checks if vin is same or exists
	 setLla(obj.m_lla);

	 cout<< "Vehicle #"<<obj.m_vin<<": Copy-ctor\n";

 }


 //destructor
 Vehicle::~Vehicle()
 {
	 //ctor
	cout<< "Vehicle #" <<getVin()<<": Dtor\n";

 }


 //operator= function
 void Vehicle:: operator=(Vehicle &v1)
 //: m_vin(v1.m_vin < s_idgen ? s_idgen++ : v1.m_vin) 
 {
 //	 v1.m_vin = getVin();
	 for (int i = 0; i < 3; i++)
	 {
		 m_lla[i] = v1.m_lla[i];
	 }
	 cout << "Vehicle #" << m_vin << ": Assignment\n";
	 //return v2;

 }
 

 //get function
 int Vehicle::getVin()		{ return m_vin; }
 float* Vehicle::getLla()	 { return m_lla; }

 //set methods

 void Vehicle::setLla(float lla[3]) 
 { 
	for(int i=0; i<3; i++)
		m_lla[i] = lla[i]; 
 }

 //move function: just changing the location "move location"
 void Vehicle:: move(float * lla)
 {
	cout<< "Vehicle #" <<getVin()<<": CANNOT MOVE - I DON'T KNOW HOW\n";

 }

 //getIdgen static member function
 int Vehicle::getIdgen()	 { return s_idgen; }

 //friend insertion operator<< function
 ostream & operator<<(ostream& os, const Vehicle& vehicle)
 {
	 os << "Vehicle #" << vehicle.m_vin << " @ [" ;
	 
	 for (int i = 0; i < 3; i++)
	 {
		 os << vehicle.m_lla[i];
		 if (i < 2)
			 os << ", ";
		 if (i == 2)
			 os << "]\n";
	 }
	//os << m_lla[0] << ", " << m_lla[1] << ", " << m_lla[2] << "]\n";
	 return os;
 }



