#include <iostream>
using namespace std;

#include <iostream>
#include <vector>

template <typename T>
class CustomIterator
{
public:
    CustomIterator(T* ptr) : ptr_{ ptr } { }

    // Prefix increment (++it)
    CustomIterator& operator++() {
        ptr_++;
        return *this;
    }

    // Postfix increment (it++)
    CustomIterator operator++(int) {
        CustomIterator tmp = *this;
        ptr_++;
        return tmp;
    }

    T& operator*() {
        return *ptr_;
    }

    friend bool operator==(const CustomIterator& a, const CustomIterator& b) {
        return a.ptr_ == b.ptr_;
    }

    friend bool operator!=(const CustomIterator& a, const CustomIterator& b) {
        return !(a == b);
    }

private:
    T* ptr_{ nullptr };
};

template <typename T>
class Container {
public:
    Container() = default;
    Container(std::initializer_list<T> list) : list_{ list } { }
    Container(const std::vector<T>& list) : list_{ list } { }

    CustomIterator<T> begin() { return CustomIterator<T>(list_.data()); }
    CustomIterator<T> end()   { return CustomIterator<T>(list_.data() + list_.size()); }

private:
    std::vector<T> list_{};
};




int main(){
    Container<int> container = {1, 2, 3, 4, 5};
    for(auto it = container.begin(); it != container.end(); ++it){
        cout << *it << endl;
    }


}