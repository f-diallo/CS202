//Name: proj2.cpp
//Purpose: C++ project that takes in a file with car data and gives the user car rental options
//Author:Fatmata (Fatima) Diallo
//Date:9/11/19

#include <iostream>
#include <fstream>

using namespace std;


size_t myStringLength(const char *str);

int myStringCompare(const char *str1, const char *str2);

char *myStringCopy(char *destination, const char *source);

char *myStringCat(char *destination, const char *source);


void swap(char array1[10], char array2[10]);


void sortPrice(struct Cars car[]);


struct Cars {
		int year;
		char make[10];
		char model[10];
		float price;
		bool available;
	
	};


int main()
{


	char inputFile[50], outputFile[50];
	int order[5]={0, 1, 2, 3, 4};
	int menuOption;
	int avail= 0;
	int days, choice;
	
	Cars car[5], *carPtr;

	//creating file streams
	ifstream fin;
	ofstream fout;


	while(menuOption != 7){
		cout<<"\nMenu Options:\n"<<"[1]: Enter input file name\n"<<"[2]: View car rental options\n";
		cout<<"[3]: Print car rental options to output file\n";
		cout<<"[4]: View car rental options by ascending price\n";
		cout<<"[5]: Enter the number of days you want to rent a car\n"<<"[6]: Choose a car to rent\n";
		cout<<"[7]: Exit program\n";
	
		cout<<"Enter an option:\n";	
		cin>>menuOption;

		if((menuOption <1) || (menuOption>7))
		{	cout<<"\nMenu Options:\n"<<"[1]: Enter input file name\n"<<"[2]: View car rental options\n";
			cout<<"[3]: Print car rental options to output file\n";
			cout<<"[4]: View car rental options by ascending price\n";
			cout<<"[5]: Enter the number of days you want to rent a car\n"<<"[6]: Choose a car to rent\n";
			cout<<"[7]: Exit program\n";
	
			cout<<"Enter a vaild option\n";
			cin>>menuOption;
		}

		switch(menuOption){
			case 1:
			{	//Names input file w/ user input and opens file
				cout<< "Enter the name of your input file:\n";
				cin>>inputFile;
				fin.open(inputFile);
	
				//stores data into cars array of structs
				for(int i=0; i<5; i++){
					fin>>car[i].year>> car[i].make>> car[i].model>> car[i].price;
					fin>> car[i].available;
				}

				break;}
			case 2:
			{	//printing car rental options
				for(int i=0; i<5; i++){
					cout<< "["<< order[i]<< "]: "<< car[i].year<< " "<< car[i].make<< " ";
					cout<< car[i].model;
					cout<< ", $"<< car[i].price<< " per day , Available: ";
					if(car[i].available==1)
						cout<<"true\n\n";
					else if(car[i].available==0)
						cout<<"false\n\n";
				}
				
				break;}
			case 3:
			{	//Names output file w/ user input and opens file
				cout<< "Enter the name of your output file:\n";
				cin>>outputFile;
				fout.open(outputFile);

				//prints cars array of structs to output file
				for(int i=0; i<5; i++){
					fout<<car[i].year<<" "<< car[i].make<<" "<< car[i].model<<" ";
					fout<< car[i].price<<" "<< car[i].available<<"\n";

					fout.close();
				}
				break;}
			case 4:
			{	//uses swap function and sort function

				sortPrice(car);
					
				for(int i=0; i<5; i++)
				{
					cout<< "["<< order[i]<< "]: ";

					cout<<car[i].year<<" "<<car[i].make<<" "<<car[i].model;
					cout<< ", $"<< car[i].price<< " per day , Available: ";

					if(car[i].available==1)
						cout<< "true\n\n";
					else if(car[i].available==0)
						cout<<"false\n\n";
				}
				break;}
			case 5:
			{//show available, sort by price, calculate price for num of days, and correspond index
			//print index(use avail to see how many index),if to check availability, then print from
 			//result of bubble sort
				cout<<"For How many days would you like to rent a car?\n";
				cin>>days;

				for(int i=0; i<5; i++){
					if(car[i].available==1){
						//counts availability for entry 5
						avail++;}
				}
				for(int i=0; i<=avail; i++)
				{
					if(car[i].available==1)
					{	cout<<"[" <<order[i]<<"] ";
						cout<<car[i].year<<" "<<car[i].make<<" "<<car[i].model<<", ";
						cout<<"Total Cost: $"<<(car[i].price*days)<< "\n\n";
					}
				}
				avail--;
				
				
				break;}
			case 6:
			{
				cout<<"Which car do you want to rent?\n";
				cin>>choice;
				cout<<"You selected: "<<"["<<choice<<"]: "<< car[choice].year<<" "; 					cout<<car[choice].make<<" "<<car[choice].model<<", Total Cost: $"; 					cout<<(car[choice].price*days)<< "\n";

				car[choice].available=0;
				
				break;}
			case 7:
				
				break;
			default:
				
				break;

		}
	}









	fin.close();
	

return 0;
}



//string functions

size_t myStringLength(const char *str)
{
	int length=0;
	for(int i=0; str[i] !='\0'; i++)
	{
		length++;
	}
return length;
}

int myStringCompare(const char *str1, const char *str2)
{
	int i=0;
	while((str1[i] != '\0')||(str2[i] != '\0'))
	{
		if(str1[i]>str2[i])
			return 1;
		else if(str1[i]<str2[i])
			return -1;
		i++;
	}
	if(str1==str2)
		return 0;

}

char *myStringCopy(char *destination, const char *source)
{
	char *begin=destination;
	for(int i=0; *source != '\0'; i++)
	{
		*destination=*source;
		destination++;
		source++;
	}
	*destination= '\0';
	return begin;
}

char *myStringCat(char *destination, const char *source)
{
	char *begin=destination;
	int taken_space=0;
	for(int i=0; *destination != '\0'; i++)
	{
		destination++;
	}
	for(int i=0; *source != '\0'; i++)
	{
		*destination=*source;
		destination++;
		source++;
	}
	*destination='\0';
	return begin;
}



//functions for swapping

void swap(char array1[10], char array2[10])
{
	char temp[10];
	myStringCopy(temp, array1);
	myStringCopy(array1, array2);
	myStringCopy(array2, temp);
}




//function for sorting by price


void sortPrice(struct Cars car[])
{
	int order=0;
	bool needSwap=true;

	while(needSwap==true)
	{
		needSwap=false;
		for(int i=0; i<4; i++)
		{
			if(car[i].price>car[i+1].price)
			{
				swap(car[i].year, car[i+1].year);
				swap(car[i].make, car[i+1].make);
				swap(car[i].model, car[i+1].model);
				swap(car[i].price, car[i+1].price);
				swap(car[i].available, car[i+1].available);
				
				needSwap=true;
				
//cout<<"hi\n\n";
			}
			else if((car[0].price<=car[1].price)&& (car[1].price<=car[2].price)&& (car[2].price<=car[3].price) && (car[3].price<=car[4].price))
			{	needSwap=false;
				break;}
			else if((i==3))
				i=0;
			if(needSwap==false)
				break;
			order++;
		}
		order=0;
	
	}

		
}




