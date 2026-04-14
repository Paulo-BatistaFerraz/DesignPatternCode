#include <iostream>
using namespace std;

int main(){
    // t is holding the memory address of the array of shared pointers on the heap (so it can be deleted)
    auto t = new std::shared_ptr<char>[15]; // holds the memory address of the array of shared pointers on the heap (so it can be deleted)
    for(int i = 0; i < 15; i++) {
        t[i] = std::make_shared<char>('a' + i);
    }
    delete[] t; // delete the array of shared pointers
    return 0;
}