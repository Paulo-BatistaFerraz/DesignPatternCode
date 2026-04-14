#include <iostream>
using namespace std;


// Write your solution here
// C++23 using GCC 14.2
// Debug with std::cerr or std::clog.
// All headers are already included for you in the test environment.
// !!! IMPORTANT !!!
// 99% of headers are pre-compiled for you server-side.
// If your submission fails to compile due to a missing header, add it to your submission.

struct Elf {
    virtual std::string_view Name() const = 0; 
};


struct ArcherElf : Elf {
    virtual std::string_view Name() const override { return "Legolas"; }; 
};



int main(){


}