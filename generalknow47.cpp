#include <iostream>
using namespace std;
namespace get {
    class D {};
    void bar(const D& i) {
      std::cout << "1";
    }
  }
  
  namespace cracked {
    void bar(const get::D& i) {
      std::cout << "2";
    }
  }
  
  int main() {
    bar(get::D());
  }