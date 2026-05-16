#include <iostream>
using namespace std;

class Maze{
    public:
    virtual void enter() = 0;
    virtual ~Maze() = default;
};
class Room: public Maze{
    public:
    Room(int roomNumber): roomNumber(roomNumber){cout << "Room created" << roomNumber << endl;};
    virtual void enter(int roomNumber) override{ // if not constructor, then roomnumber is not stored in memory, so its lost after the constructor is called
        cout << "Entering room" << roomNumber << endl;
    }
    ~Room() {cout << "Room destroyed" << roomNumber << endl;};
};

class Door: public Maze, public Room{
    public:
    Door(Room* room1, Room* room2): Room(room1), Room(room2){cout << "Door created" << room1->roomNumber << " and " << room2->roomNumber << endl;};
    virtual void enter(int roomNumber, int otherRoomNumber) override{
        cout << "Entering door" << << roomNumber << << otherRoomNumber << endl;
    }
    ~Door() = default; // if ~Door() without default, then the destructor will be deleted when
}


Maze* createMaze(){ // 
    Maze* m = new Maze(); // new is used to allocate memory on the heap
    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Door* d = new Door(r1, r2);

    return m;
}


int main(){
    Maze *m = createMaze(); 
    m->enter(1);


}