#include <iostream>
using namespace std;


struct C{
    virtual void foo(int a = 1){
        cout << "C" << a;
    }

}
struct D: C{
    virtual void foo(int a = 2){
        cout << "D" << a;
    }
}

int main(){
    C* c = new D; // result is C1
    c->foo(); // output: D2
}