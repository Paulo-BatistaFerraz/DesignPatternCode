#include <iostream?

enum class FeePriority {
    One = 0,
    Two,
    Three
};

int main(){
    FeePriority priority = FeePriority(3);
    std::cout << int(priority) << std::endl; // result
}