#include <iostream>
using namespace std;

struct A{
    virtual int foo(int x){
        cout <<"2" << endl;
    }
};
struct B: public A{
    int foo(int x) const{ // non member function cannot be overridden
        cout << "1" << endl;
    }
};



int main(){
    A* a = new B();
    a->foo(1); 
}