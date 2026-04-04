#include <iostream>
using namespace std;


class WatchHardware{
    public:
    static WatchHardware& GetInstance(){
        static WatchHardware instance;
        return instance;
    }

    void operator=(const WatchHardware&) = delete; // copy assignment operator 
    WatchHardware(const WatchHardware&) = delete; // copy constructor
    WatchHardware(WatchHardware&&) = delete; // move constructor
    void operator=(WatchHardware&&) = delete; // move assignment operator

    private:
    WatchHardware() = default;
    ~WatchHardware() = default;
}


int main(){
    WatchHardware& w = WatchHardware::GetInstance();
    return 0;
}
