


proj5: proj5.o Car.o Vehicle.o
	g++ proj5.o Car.o Vehicle.o -o proj5
	
proj5.o: proj5.cpp
	g++ -c proj5.cpp

Car.o: Car.cpp Car.h
	g++ -c Car.cpp

Vehicle.o: Vehicle.cpp Vehicle.h
	g++ -c Vehicle.cpp

clean:
	rm *.o proj5

