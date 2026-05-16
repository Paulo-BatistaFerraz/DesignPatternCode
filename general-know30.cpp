// Headers
#include <iostream>
using namespace std;

struct A {
    A() { std::cout << "1"; }
    A(const A &a) { std::cout << "2"; }
    virtual void f() { std::cout << "3"; }
  };
  
  int main() {
    A b;

  }