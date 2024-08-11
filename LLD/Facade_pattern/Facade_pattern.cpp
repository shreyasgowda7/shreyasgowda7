// Facade is a structural design pattern that provides a simplified interface to a library, a framework, or any other complex set of classes.
// A facade is a class that provides a simple interface to a complex subsystem which contains lots of moving parts. A facade might provide limited functionality in comparison to working with the subsystem directly. However, it includes only those features that clients really care about.

#include <iostream>
using namespace std;

class Product
{
    string p;
    public:
    Product(string s)
    {
        p=s;
    }
    string getproduct()
    {
        return "sending "+p;
    }
};

class Payment
{
    public: 
    void makepayment()
    {
        cout<<"Payement done\n";
    }
};

class notification
{
    public:
     void getnotification()
     {
         cout<<"notification sent to client";
     }
};

class facade
{   
    string pr;
    Product *p;
    Payment *pay;
    notification *n;

    public: 
    facade(string s)
    {   
        pr=s;
        p=new Product(pr);
        pay = new Payment();
        n = new notification();
    }
    
    void createorder()
    {
        pr=p->getproduct();
        cout<<pr<<endl;
        pay->makepayment();
        n->getnotification();
    }
};


int main() {
  
  facade *f=new facade("iphone");
  f->createorder();
  
  return 0;
}
