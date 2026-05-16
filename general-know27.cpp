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



#include <chrono>
#include <future>
#include <iostream>
#include <thread>


unsigned long long fibonacci(unsigned long n)
{
    if (n <= 1) return 1;
    return fibonacci( n - 1) + fibonacci(n - 2);
}

int main()
{
    unsigned long n{40};
    std::cout << "calling fibonacci" << endl;
    auto result_future = std::async(fibonacci, n);

    using namespace std::literals;
}

unsigned long long fibonacci(unsigned long n)
{
    if (n <= 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    unsigned long n{40};
    std::cout << "calling fibonacci(" << n << ")" << std::endl;

    auto result_future = std::async(fibonacci, n);

    using namespace std::literals;

    
    while (result_future.wait_for(100ms) != std::future_status::ready)
        std::cout << "Waiting for result...\n";

    std::cout << "result is " << result_future.get() << std::endl;
    return 0;
}


int main(){
    auto add = [](int a, int b) { return a + b;};
    add(1, 2);
    auto add = [](int a, int b) { return a + b;};
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