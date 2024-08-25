// Decorator is a structural design pattern that lets you attach new behaviors to objects by placing these objects inside special wrapper objects that contain the behaviors.
// Many perm and comb of callses can happen which leads to class explosion hence this pattern is needed.

#include <iostream>
using namespace std;

class Pizza
{
    public:
    virtual int cost()=0;
};

class Pizzadecorator: public Pizza
{
    
};

class Pizza1:public Pizza
{
  public:
   int cost()
   {
       return 10;
   }
};

class Pizza2:public Pizza
{
  public:
   int cost()
   {
       return 20;
   }
};

class cheese:public Pizzadecorator
{
    Pizza* p1;
    
    public:
    cheese(Pizza *p)
    {
        this->p1=p;
    }
    
    int cost()
    {
        return 10+p1->cost();
    }
    
};

class mushroom:public Pizzadecorator
{
    Pizza* p1;
    
    public:
    mushroom(Pizza *p)
    {
        this->p1=p;
    }
    
    int cost()
    {
        return 7+p1->cost();
    }
    
};

int main() {
  
  int a=0;
  Pizza *p = new cheese(new Pizza1());
  Pizza *p1 = new mushroom(p);
  a=p1->cost();
  cout<<a;
  return 0;
}
