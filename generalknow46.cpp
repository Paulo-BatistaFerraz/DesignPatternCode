#include <iostream>
using namespace std;
struct Foo {
    std::map<int, int> map_;

    int Bar(int key) const {
        auto it = map_.find(key);
        if (it == map_.end()) {
            return -1;
        }
        return it->second; // return the value of the key
    }

    bool same_parity(int a, int b) {
        return (a%2 == b%2);
    }
};

int main(){
    Foo f;
    f.map_[1] = 10;
    cout << f.Bar(1) << endl;
    cout << f.same_parity(1, 2) << endl;


}