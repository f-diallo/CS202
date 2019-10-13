
//Vehicle.h

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <fstream>



using namespace std;


class Vehicle
{
	public:
		//ctor
		Vehicle();
		//parameterized ctor
		Vehicle(const int vin, float* lla);
		//copy ctor
		Vehicle(Vehicle &obj);
		//dtor
		~Vehicle();

		//operator= function
		void operator=(Vehicle& v1);

		//get functions
		int getVin();
		float * getLla();

		//set functions
		void setLla(float lla[3]);

		//move function
		void move(float * lla);

		//getIdgen static member function
		static int getIdgen();

		//friend insertion operator<< function
		friend ostream & operator<<(ostream& os, const Vehicle& vehicle);

	private:
		static int s_idgen;
		
	protected:
		float m_lla[3]={0, 0, 0};
		const int m_vin=00;
};









#endif

