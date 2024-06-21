// Observer Pattern

// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class stockinventory;
class notifyobs
{   
    public:
    virtual void notify()=0;
};

class emailnotify:public notifyobs
{   
    private:
    string mail; 
    stockinventory *s;
    public:
    emailnotify(string mailid,stockinventory *ss) 
    {
        this->mail=mailid;
        this->s=ss;
    }
    void notify()
    {
       cout<<"msg sent to mailid "<<mail<<"\n";
    }
    
};

class stockinventory
{   
    public:
    virtual void add(notifyobs* obj)=0;
    virtual void remover(notifyobs* obj)=0;
    virtual void update(int count)=0;
    
};
class iphonestock: public stockinventory
{   
    private: int setcount;
    public:
    list<notifyobs*> objlist;
    
    void add(notifyobs* obj) 
    {
        objlist.push_back(obj);
    }
    
    void remover(notifyobs* obj) 
    {
        objlist.remove(obj);
    }
    
    void update(int count) 
    {
        setcount=count;
        for(auto i:objlist)
        {
            i->notify();
        }
    }
    
};


int main()
{
    stockinventory* iphone = new iphonestock();
    notifyobs* obs1 = new emailnotify("chechu",iphone);
    notifyobs* obs2 = new emailnotify("chechusss",iphone);
    iphone->add(obs1);
    iphone->add(obs2);
    iphone->update(7);
    iphone->update(11);
    iphone->remover(obs2);
    iphone->update(11);
}
