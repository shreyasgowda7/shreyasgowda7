// Create only 1 instance of class

#include <iostream>
#include <mutex>
#include<thread>
using namespace std;

class logger
{   
    static mutex mtx;
    static  int ctr;
    static  logger* instance;
    logger(){};
    
    public:
    static logger* getlogger()
    {   
        if(instance==nullptr)
        {
         mtx.lock()
           if(instance==nullptr)
           {
             instance= new logger();
              ctr++;
              cout<<"new instance created "<<ctr<<endl;
           }
        mtx.unlock();
        }
        return instance;
    }
    void log(string msg)
    {
        cout<<msg<<endl;
    }
};

int logger::ctr=0;
logger* logger::instance=nullptr;

void user1()
{
    logger* user1=logger::getlogger();
    user1->log("i'm user 1");
}

void user2()
{
    logger* user2=logger::getlogger();
    user2->log("i'm user 2");
}
int main() {
    
   thread t1(user1);
   thread t2(user2);
   t1.join();
   t2.join();
    return 0;
}
