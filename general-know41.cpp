#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<string> names = {"Alice", "Bob", "Charlie"};

    for (auto name : names){
        name = "nobody"
        cout << name << endl;
    }
    for (auto& name : names){
        name = "nobody";
        cout << name << endl;
    }
    for (const auto& name : names){
        cout << name << endl; // just modifying the value of the name
    }
    
}