// creation of object logic is kept in factory class and it will create and return the object
#include <iostream>
using namespace std;

class shape
{ 
    public:
    virtual void draw()=0;
};

class sqaure:public shape
{
    public:
    void draw()
    {
        cout<<"I'm a square bro\n";
    }
};

class circle:public shape
{
    public:
    void draw()
    {
        cout<<"I'm a circleee bro\n";
    }
};

class shapefactory
{   
    shape *s;
public:
   shape* getshape(string str)
   {
     if(str=="sqaure")
     return new sqaure();
     else 
     return new circle();
   }
};

int main() {
    shapefactory* shf = new shapefactory();
    shape* sh=shf->getshape("sqaure");
    sh->draw();
    shape* sh1=shf->getshape("circle");
    sh1->draw();
    return 0;
}


//


#include <iostream>
#include <mutex>
#include<thread>
using namespace std;

class vehicle
{
    public: virtual void createvehicle()=0;
};

class twowheeler:public vehicle
{
    public:
    void createvehicle()
    {
        cout<<"girls like me broo\n";
    }
};

class fourwheeler:public vehicle
{
    public:
    void createvehicle()
    {
        cout<<"boys like me broo\n";
    }
};

class vehiclefactory
{
    string strs;
    public: 
    vehiclefactory(string str)
    {
        this->strs=str;
    }
    
    vehicle* getvehicle()
    {
        if(strs=="boys")
            return new fourwheeler();
        
        else return new twowheeler();
    }
};

int main() {
    
  vehiclefactory *vh = new vehiclefactory("boys");
  vehicle *v1=vh->getvehicle();
  v1->createvehicle();
  
  vehiclefactory *vh1 = new vehiclefactory("girlsasasas");
  vehicle *v11=vh1->getvehicle();
  v11->createvehicle();
  
}
//
