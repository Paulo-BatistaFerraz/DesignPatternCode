#include <iostream>
using namespace std;

struct IImage {
    virtual void display() = 0;
};

struct RealImage: IImage{
    void display() override {}
};

struct ProxyImage: IImage{
    RealImage* real = nullptr;
    void display() override {
        if(!real) real = new RealImage(); // if (!real) means if its not
        real->display();
    }
};

int main(){

}