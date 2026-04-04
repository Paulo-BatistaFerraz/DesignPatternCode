#include <iostream>
using namespace std;

class Car{
    public:
    virtual void working() = 0;
    virtual ~Car() = default;
};
class BMW: public Car{
    public:
        void working() override{
            cout << "BMW is working" << endl;
        }
        ~BMW() override{
            cout << "BMW is destroyed" << endl;
        }
};


int main(){
    Car* car = new BMW();
    car->working();
    delete car;
    return 0; // if car is not virtual then the car will not be destroyed

}