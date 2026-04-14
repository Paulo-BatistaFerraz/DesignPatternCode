#include <iostream>
#include <thread>
#include <memory>
using namespace std;



int main(){
    auto counter = make_shared<int>(0);


    thread writer([counter])(){
        for (int i = 0; i < 1000; i++){
            (*counter)++;
        }
    }
    thread reader([counter])(){
        for (int i = 0; i < 1000; i++){
            cout << *counter << endl;
        }
    }

    writer.join();
    reader.join();

    

}