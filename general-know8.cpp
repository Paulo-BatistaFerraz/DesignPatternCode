#include <iostream>
using namespace std;
struct Animal{
    public:
    virtual void bark() = 0;

}

struct Dog: Animal{
    public:
    void bark() override {
        cout << "Woof" << endl;
    }
};

struct Cat: Animal{
    public:
    void bark() override{
        cout << "Meow" << endl;
    }
}



int main(){
    Animal* dog = new Dog(); // dog is a pointe to animal
    dog->bark(); // called based on the object type
}