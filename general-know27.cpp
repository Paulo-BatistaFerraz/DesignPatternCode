#include <iostream>
using namespace std;


auto add(int a, int b) -> (int){
    return a + b;


}

bool add(bool a, bool b){
    return a + b;
}

template<typename... T>
void f(T... args);
f(1);
f(1,2);

template<typename... sum_args> // prints a set of arguments
void log(sum_args... args){
    //summing the arguments
    int sum = 0;
    ((sum += args), ...);
    cout << sum << endl;
}

template<typename T>
struct Box{T value;};


int main(){
    Box(int) -> Box<int>; // write the rules manually
    Box b{42};
    log(1, 2, 3);
    sum_args(1, 2, 3); // this will sum the arguments (ie result will be 6)

    
    int a = 5;
    int b = 10;

    auto c = add(a,b);
    cout << c << endl;

    bool d = add(true, false);

    return 0;


}