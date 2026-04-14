#include <iostream> 
using namespace std;

struct Command{
    virtual void execture() = 0; // pure virtual function
    virtual void undo() = 0;

};

struct PastCommand : Command{
    void execture() override {
        cout << "Executing past command" << endl;

    }
    void undo() override {
        cout << "Undoing past command" << endl;
    }
};