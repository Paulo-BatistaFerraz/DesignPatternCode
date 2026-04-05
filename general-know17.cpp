#include <iostream>
using namespace std;
class Door{};
class Room{
    virtual void describe() = 0;
    virtual ~Room() = default; //default destructor else the destructor will be deleted when the class is inherited
};
class BoombRoom: public Room{
    virtual void describe() override{
        cout << "This room has a BOMB" << endl;
    }

};
class NormalRoom: public Room{
    virtual void describe() override{
        cout << "Just a boring room " << endl;
    }
}
class Maze{
    Room* rooms;
    Door* doors;
};

int main(){
    Room* r = new NormalRoom();
    r->describe();
    Room* r2 = new BombRoom();
    r2->describe();

    delete r;
    delete r2;
    return 0;
}