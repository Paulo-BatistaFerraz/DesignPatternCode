#include <iostream>
using namespace std;

int main(){
    goto trap;

    try
    {
        trap:
        throw std::runtime_error("trap");
    }
    catch(...)
    {
        cout << "caught" << endl;
    }
    std::cout << "end" << endl;
    return 0;
}