// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DriveStrategy {
public:
	virtual void drive() = 0;
};

class NormalDrive : public DriveStrategy {
public:
	void drive() 
	{
		cout<<"Normal drivingg\n";
	}
};

class SpecialDrive : public DriveStrategy {
public:
	void drive()
	{
		cout<<"Special drivingg";
	}
};



class Vehicle {
private:
	DriveStrategy* strategy;

public:
    Vehicle(DriveStrategy* strategy) 
    {
        this->strategy=strategy;
    }
	void setStrategy(DriveStrategy* strategy)
	{
		this->strategy = strategy;
	}

	void executeStrategy()
	{
		strategy->drive();
	}
};

class passenger: public Vehicle
{
    public:
    passenger(): Vehicle(new SpecialDrive())
    {
        
    }
};
int main()
{
	Vehicle* vv=new passenger();
	vv->executeStrategy();
    NormalDrive normal;
	SpecialDrive special;
	Vehicle vehicle(&normal);
	
    passenger v1;
    
    v1.executeStrategy();
	vehicle.setStrategy(&normal);
	vehicle.executeStrategy(); // Executes Bubble Sort

	vehicle.setStrategy(&special);
	vehicle.executeStrategy(); // Executes Quick Sort

	return 0;
}
