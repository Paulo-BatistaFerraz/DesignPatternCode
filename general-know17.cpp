#include <iostream>
using namespace std;
class Door{};
class Room{
    public:
    virtual void describe() = 0;
    virtual ~Room() = default; //default destructor else the destructor will be deleted when the class is inherited
};
class BombRoom: public Room{
    public:
    virtual void describe() override{
        cout << "This room has a BOMB" << endl;
    }

};
class NormalRoom: public Room{
    public:
    virtual void describe() override{
        cout << "Just a boring room " << endl;
    }
};

class MazeBuilder{
    virtual void buildRoom() = 0; // pure virtual
}

class NormalMazeBuilder: public MazeBuilder{
    


}

class Maze{
    public:
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