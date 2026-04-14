#include <iostream>
using namespace std;
class Subject{
    vector<object*> observers = {new Observer1(), new Observer2()}; // vector of memory addresses of the observers
    public:
        void notify() {for(auto* observer : observers){observer->update();}} // update() -> function that will be overridden by the observer
}





int main(){
    Subject subject;
    subject.notify(); // notify() -> function that will be overridden by the observer

    return 0;


}