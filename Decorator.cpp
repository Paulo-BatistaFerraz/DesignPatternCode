#include <iostream>
using namespace std;

struct Icomponent{
    virtual void execute() = 0;
}
struct Component{
    virtual void execute() = 0;

};
struct Logger : Component{ // interface -> implementation
    Icomponent* wrapped; // Icomponent is the interface that the logger will wrap
    void execute() override { // add behavior on top of the original(behavior on top)
        cout << "Logging" << endl;
        wrapped->execute(); // delegate to original
    }
}

int main(){


}