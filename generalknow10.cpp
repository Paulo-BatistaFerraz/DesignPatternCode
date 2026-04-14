#include <iostream>
using namespace std;

int main() 
{
    cout << is_same_v<
        void(double*),
        void(const double*)>;
}