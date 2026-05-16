#include <future>
#include <stdexcept>
#include <iostream>

int riskDivide(int a, int b){
    if (b == 0)
        throw std::runtime_error("Division by zero!");
    return a / b;
}

int main(){

    std::future<int> result = std::async(std::launch::async, riskDivide, 10, 0);

    try{
        int val = result.get();
        std::cout << "result: " << val << '\n';
    } catch (const std:: runtime_error& e){
        std::cout << "Caugth exception: " << e.what() << "\n"
    }
    return 0;
}