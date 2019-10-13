
//Car.h

#ifndef CAR_H
#define CAR_H

class Car: public Vehicle
{
public:
	//ctor
	Car();
	//parameterized ctor
	Car(char* plates, const int vin, float* lla);
	//copy ctor
	Car(Car &obj);
	//dtor
	~Car();

	//operator- function
	void operator-(Car &c1);


	//get functions
	char *getPlates();
	int getThrottle();

	//set functions
	void setPlates(char *plates);
	void setThrottle(int throttle);

	//drive function
	void drive(int throttle);

	//move function
	void move(float* lla);
	
	//friend insertion operator<< function
	friend ostream & operator<<(ostream& os, const Car& car);

private:
	char m_plates[256];
	int m_throttle;


};










#endif

