#include <iostream>
using namespace std;

Class Singleton{
    public:
    static Singleton& GetInstance(){ // static(static local var), Singleton&(address of the instance), GetInstance(function name)
        static Singleton instance; // instance variable (holds the instance of the singleton class)
        return instance;
    }
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    void operator=(const Singleton&) = delete;
    void operator=(Singleton&&) = delete;

    // class function is used in order to have access to properties of the class ex

    private:
    Singleton() = default;
    ~Singleton() = default;
}



