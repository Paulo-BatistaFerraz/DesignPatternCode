#include <iostream>
#include <array>
#include <cassert>
 
template<typename T, int Size>
class Stack {
    std::array<T, Size> data;
    int count = 0;
 
public:
    Stack() = default;
 
    // Converting constructor — build a larger stack from a smaller one
    template<int OtherSize>
    Stack(Stack<T, OtherSize> const& other) {
        for (int i = 0; i < other.size(); i++) {
            push(other[i]);
        }
    }
 
    void push(T const& val) {
        assert(count < Size);
        data[count++] = val;
    }
 
    T operator[](int i) const { return data[i]; }
    int size() const { return count; }
};
 
int main() {
    Stack<int, 20> small;
    small.push(1);
    small.push(2);
    small.push(3);
 
    Stack<int, 40> big(small);  // copy small into big
 
    std::cout << "big box contains:\n";
    for (int i = 0; i < big.size(); i++) {
        std::cout << big[i] << "\n";
    }
}