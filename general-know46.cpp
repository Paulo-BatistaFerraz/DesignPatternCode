#include <iostream>
using namespace std;

class A{
    void  process(int x) { std::cout << "int\n";}
    void  process(char* s) { std::cout << "string\n";}

    template<typename T>
    void safe_proess(T x){
        static_assert(!std::is_same_v<T, std::nullptr_t>, "T cannot be nullptr"); // static_assert is a compile-time assertion that checks if the condition is true
        process(x);
    }
};

int main() {
    A a;
    a.safe_process(1);
    a.safe_process("hello");
    return 0;
}