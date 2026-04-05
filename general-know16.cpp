#include <iostream>
using namespace std;

// Abstract base class - defines the uniform interface
// enter() takes NO arguments: state lives in the object, not in the call
class Maze {
public:
    virtual void enter() = 0;
    virtual ~Maze() = default;
};

class Room : public Maze {
    int roomNumber; // member variable declared here - constructor sets it, enter() reads it
public:
    explicit Room(int roomNumber) : roomNumber(roomNumber) {
        cout << "Room created: " << roomNumber << "\n";
    }

    void enter() override { // matches Maze::enter() exactly - no arguments
        cout << "Entering room " << roomNumber << "\n";
    }

    int getId() const { return roomNumber; } // getter so Door can read without breaking encapsulation

    ~Room() {
        cout << "Room destroyed: " << roomNumber << "\n";
    }
};

// Door is NOT a Room - it CONNECTS two Rooms (composition over inheritance)
// Only inherits from Maze to fulfill the polymorphic interface
class Door : public Maze {
    Room* room1; // Door HAS rooms, it doesn't IS-A room
    Room* room2;
public:
    Door(Room* r1, Room* r2) : room1(r1), room2(r2) {
        cout << "Door created between room " << r1->getId() << " and room " << r2->getId() << "\n";
    }

    void enter() override { // matches Maze::enter() exactly
        cout << "Entering door between room " << room1->getId()
             << " and room " << room2->getId() << "\n";
    }

    ~Door() = default;
};

// createMaze returns r1 as the entry point
// r1, r2, d are allocated on the heap - caller is responsible for cleanup
// (in production, use unique_ptr or store components inside the maze object)
Maze* createMaze() {
    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Door* d  = new Door(r1, r2);

    (void)d; // d is created but ownership not transferred - demo only
    return r1;
}

int main() {
    Maze* m = createMaze();
    m->enter(); // polymorphic call - works on Room, Door, or any future Maze subclass

    delete m;
    return 0;
}
