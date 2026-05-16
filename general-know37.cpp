#include <iostream>
using namespace std;

template<typename T>
T safe_double(T val){
    if constexpr(std::is_integral_v<T>){
        return 2 * val;
        
    }
    else{
        return val;
    }
    if 
}

int main(){
    cout << safe_double(5) << endl;
    cout << safe_double(3.14) << endl;

}