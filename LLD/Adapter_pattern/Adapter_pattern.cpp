// Adapter is a structural design pattern that allows objects with incompatible interfaces to collaborate
//  the adapter implements the interface of one object and wraps the other one.

#include <iostream>
using namespace std;

class XMLdata
{
    string xml;
    public:
    XMLdata(string x)
    {
        xml=x;
    }
    string getXMLdata()
    {
        return xml;
    }
};

class DataAnalysisTool
{
    string jsondata;
    public: 
     DataAnalysisTool() {}
     DataAnalysisTool(string json)
     {
         jsondata=json;
     }
    virtual void analyse()
    {
        cout<<"Analysing data "<<jsondata;
    }
};

class adapter:public DataAnalysisTool
{
    XMLdata* x;
    public: 
    adapter(XMLdata* y)
    {
        x=y;
    }
    
    void analyse() override
    {
        cout<<"Converting XML data "<<x->getXMLdata()<<" to JSOn \n";
        DataAnalysisTool::analyse();
    }
};

class client
{   
    public: 
    void processdata(DataAnalysisTool *a)
    {
        a->analyse();
    }
};


int main() {
  
  XMLdata *x=new XMLdata("I'm XML");
  DataAnalysisTool *t= new adapter(x);
  client *c=new client();
  c->processdata(t);
  
  return 0;
}
