#include <iostream>
using namespace std;


class fairlife{
    public:
    virtual void drink() = 0;
    virtual ~fairlife() = default;
};
class NJF: public fairlife{
    public:
        virtual void drink() override{
            cout << "Drinking NJF" << endl;
        }
        ~NJF() {cout << "NJF is destroyed" << endl;}
};


class Base{
    public:
    virtual void foo() = 0;
    virtual void bar() = 0;
    virtual ~Base() = default;
};
class Derived: public Base{
    public:
        void foo() override{
            cout << "Derived::foo" << endl;
        }
        void bar() override{
            cout << "Derived::bar" << endl;
        }
        ~Derived() {cout << "Derived is destroyed" << endl;}
}


int main(){
    fairlife* f = new NJF();
    f->drink();
    delete f;

    Base* p = new Derived(); // p is the pointer and vtable is the table of functions
    p->foo();  // p->vptr → Derived's vtable[0] → Derived::foo
    p->bar();  // p->vptr → Derived's vtable[1] → Base::bar
    delete p;
    return 0;
}