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
