#include <iostream>
using namespace std;

template<typename... Types>
class Bag{
    public:
        Bag(Types... args) : data{args...} {}
        std::tuple<Types...> data;
};

class Bag{
    public:
        Bag(Types... args): data{args...} {}
        std::tuple<Types...> data; // for each data on the bag we will store it in a tuple its type
}


int main(){
    Bag<int, string> bag(1, "Hello");


}