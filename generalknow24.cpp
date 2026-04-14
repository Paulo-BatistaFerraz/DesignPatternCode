#include <iostream>
using namespace std;

class A{
    void print(string a){
        cout << a << endl;
    }
    ~A(){
        cout << "memory utilized have been cleaned" << endl;
    };
    
}

class B: public A{
    void print(string a) override{
        cout << a << a << endl;
    }
    
}

int main(){
    B b;
    b.print("Hello");
    
    return 0;
}