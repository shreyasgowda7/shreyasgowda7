// Builder is a creational design pattern that lets you construct complex objects step by step. The pattern allows you to produce different types and representations of an object using the same construction code.
// The Builder pattern suggests that you extract the object construction code out of its own class and move it to separate objects called builders.

#include <iostream>
using namespace std;

class Desktop
{
    public:
    string mouse;
    string keyboard;
    string monitor;
    string ram;
    
    public:
    
    void setmouse(string m)
    {
        mouse=m;
    }
    
    void setkeyboard(string k)
    {
        keyboard=k;
    }
    
    void setmonitor(string moni)
    {
        monitor=moni;
    }
    
    void setram(string r)
    {
        ram=r;
    }
    
    void showspecs()
    {
        cout<<mouse<<"\n";
        cout<<keyboard<<"\n";
        cout<<monitor<<"\n";
        cout<<ram<<"\n";
    }
};

class DesktopBuilder
{
    protected: Desktop *d;
    public: 
    DesktopBuilder()
    {
     d=new Desktop();
    }
     virtual void buildmouse()=0;
     virtual void buildkeyboard()=0;
     virtual void buildmonitor()=0;
     virtual void buildram()=0;
     virtual Desktop* getdesktop()=0;
};

class HPbuilder:public DesktopBuilder
{
    public: 
     void buildmouse()
     {
         d->setmouse("HP mouse");
     }
     void buildkeyboard()
     {
         d->setkeyboard("HP keyboard");
     }
     void buildram()
     {
         d->setram("HP ram");
     }
     void buildmonitor()
     {
         d->setmonitor("HP monitor");
     }
     Desktop* getdesktop()
     {
         return d;
     }
};

class Dellbuilder:public DesktopBuilder
{
    public: 
     void buildmouse()
     {
         d->setmouse("Dell mouse");
     }
     void buildkeyboard()
     {
         d->setkeyboard("DEll keyboard");
     }
     void buildram()
     {
         d->setram("DEll ram");
     }
     void buildmonitor()
     {
         d->setmonitor("Delll monitor");
     }
     Desktop* getdesktop()
     {
         return d;
     }
};


class Director
{
   DesktopBuilder *db;
   
   public: Director(DesktopBuilder *b)
   {
       db=b;
   }
   
   Desktop* builddesktop()
   {
       db->buildmouse();
       db->buildkeyboard();
       db->buildmonitor();
       db->buildram();
       return db->getdesktop();
   }
};


int main() {
  
  DesktopBuilder *DB1=new HPbuilder();
  DesktopBuilder *DB2=new Dellbuilder();
  
  Director *D1= new Director(DB1);
  Director *D2= new Director(DB2);
  
  Desktop *hpe=D1->builddesktop();
  hpe->showspecs();
  
  Desktop *dell=D2->builddesktop();
  dell->showspecs();
  
}
