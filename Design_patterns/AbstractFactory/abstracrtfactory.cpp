// The Abstract Factory Pattern is a creational design pattern that provides an interface for creating families of related or dependent objects without specifying their concrete classes, in simpler terms the Abstract Factory Pattern is a way of organizing how you create groups of things that are related to each other
// The Abstract Factory pattern helps you control the classes(familiy) of objects that an application creates.

#include <iostream>
#include <mutex>
#include<thread>
using namespace std;

class Textbox
{
    public:
    virtual void inserttextbox()=0;
};

class Clickbox
{
    public:
    virtual void insertclickbox()=0;
};

class Ifactory
{
    public:
    
    virtual Textbox* createtextbox()=0;
    virtual Clickbox* createclickbox()=0;
};



class Wintext:public Textbox
{
    public:
    void inserttextbox()
    {
        cout<<"Inserting windows text box \n";
    }
};

class Mactext:public Textbox
{
    public:
    void inserttextbox()
    {
        cout<<"Inserting Mac text box \n";
    }
};

class Macclick:public Clickbox
{
    public:
    void insertclickbox()
    {
        cout<<"Inserting Mac Click box \n";
    }
};

class Winclick:public Clickbox
{
    public:
    void insertclickbox()
    {
        cout<<"Inserting Windows Click box \n";
    }
};


class Winfactory: public Ifactory
{
    public:
    
    Textbox* createtextbox()
    {
        return new Wintext();
    }
    
    Clickbox* createclickbox()
    {
        return new Winclick();
    }
};

class Macfactory: public Ifactory
{
    public:
    
    Textbox* createtextbox()
    {
        return new Mactext();
    }
    
    Clickbox* createclickbox()
    {
        return new Macclick();
    }
};

class GUIfactory
{
    public:
    static Ifactory* createfactory(string os)
    {
        if(os=="windows")
        return new Winfactory();
        else return new Macfactory();
    }
   
};

int main() {

  string OS;
  cout<<"Enter OS type";
  cin>>OS;
  Ifactory *fact = GUIfactory::createfactory(OS);
  
  Textbox* text1=fact->createtextbox();
  text1->inserttextbox();
  
  Clickbox* click1=fact->createclickbox();
  click1->insertclickbox();
  
}
