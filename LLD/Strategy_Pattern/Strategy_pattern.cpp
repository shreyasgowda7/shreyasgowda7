#include <iostream>
using namespace std;
#include <vector>
class SortingStrategy {
public:
    virtual void sort(vector<int>& arr) = 0;
};

class BubbleSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr) override {
        cout<<"Sorting with bubble\n";
    }
};
 
class QuickSort : public SortingStrategy {
public:
    void sort(std::vector<int>& arr) override {
        cout<<"Sorting with quick\n";
    }
};
 

class SortTool
{
    private:
    SortingStrategy* strategy;
 
 public:
    void setStrategy(SortingStrategy* strategy) {
        this->strategy = strategy;
    }
 
    void executeStrategy(std::vector<int>& arr) {
        strategy->sort(arr);
    }
};


int main() {
  
  SortTool *t1= new SortTool();
  SortingStrategy *st=new QuickSort();
  t1->setStrategy(st);
  vector<int>a(1,0);
  //st->sort(a);
  t1->executeStrategy(a);
  
  
  return 0;
}
