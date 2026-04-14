#include <iostream>
using namespace std;

struct A{
    virtual int foo(int x){
        cout <<"2" << endl;
    }


}
struct B: public A{ // having A will inherit both private and public members of A
    int foo(int x){
        cout <<"1" << endl;
    }
}

int main(){
    A* a = new B();
    a->foo(1);

}